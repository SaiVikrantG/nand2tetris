#ifndef HASHMAP_H
#define HASHMAP_H

// hashtable entry
typedef struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
} htab;

// inserts key-value pairs in the hashtable
struct nlist *install(char *name, char *defn, htab **tab);

// creates hashtable
htab **create_hashtab();

// finds a key in the hashtable and returns the struct object
// associated with that key if present
struct nlist *lookup(char *s, htab **tab);

// duplicates a string and returns a pointer to it
char *strduplicate(char *s);

// Forms a hash value for a string s
unsigned hash(char *s);

// Reads all keys from hashtable
void prod(htab **tab);

#endif
