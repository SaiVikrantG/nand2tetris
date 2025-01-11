#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 101

// make a duplicate of s
char *strduplicate(char *s) {
  char *p;
  p = (char *)malloc(strlen(s) + 1);

  if (p != NULL) {
    strcpy(p, s);
  }

  return p;
}

// table entry
typedef struct nlist {
  struct nlist *next; // next entry
  char *name;
  char *defn;
} htab;

// form hashvalue for string s
unsigned hash(char *s) {
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++) {
    hashval = *s + 31 * hashval;
  }

  return hashval % HASHSIZE;
}

// creates a hashtab and returns it's reference
htab **create_hashtab() {
  htab **hashtab = (htab **)malloc(sizeof(htab *) * HASHSIZE);

  if (hashtab == NULL) {
    return NULL;
  }

  return hashtab;
}

// lookup for s in hash table
htab *lookup(char *s, htab **table) {
  htab *np;

  for (np = table[hash(s)]; np != NULL; np = np->next) {
    if (strcmp(s, np->name) == 0) {
      return np; // found
    }
  }

  return NULL; // not found
}

// install: put (name,defn) in hashtab
htab *install(char *name, char *defn, htab **table) {
  htab *np;
  unsigned hashval;

  if ((np = lookup(name, table)) == NULL) {
    np = (htab *)malloc(sizeof(*np));

    if (np == NULL || (np->name = strduplicate(name)) == NULL) {
      return NULL;
    }

    hashval = hash(name);
    np->next = table[hashval];
    table[hashval] = np;
  } else {
    free((void *)np->defn);
  }

  if ((np->defn = strduplicate(defn)) == NULL) {
    return NULL;
  }

  return np;
}

void prod(htab **table) {
  htab *pointer;

  for (int i = 0; i < HASHSIZE; i++) {
    pointer = table[i];

    while (pointer != NULL) {
      printf("%s: %s\n", pointer->name, pointer->defn);
      pointer = pointer->next;
    }
  }
}
