#include "hashmap.h"
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
// struct nlist {
//   struct nlist *next; // next entry
//   char *name;
//   char *defn;
// };

static struct nlist *hashtab[HASHSIZE]; // pointer table

// form hashvalue for string s
unsigned hash(char *s) {
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++) {
    hashval = *s + 31 * hashval;
  }

  return hashval % HASHSIZE;
}

// lookup for s in hash table
struct nlist *lookup(char *s) {
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
    if (strcmp(s, np->name) == 0) {
      return np; // found
    }
  }

  return NULL; // not found
}

// install: put (name,defn) in hashtab
struct nlist *install(char *name, char *defn) {
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) {
    np = (struct nlist *)malloc(sizeof(*np));

    if (np == NULL || (np->name = strduplicate(name)) == NULL) {
      return NULL;
    }

    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else {
    free((void *)np->defn);
  }

  if ((np->defn = strduplicate(defn)) == NULL) {
    return NULL;
  }

  return np;
}
