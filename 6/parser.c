#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap.h"

htab **init_dest() {
  static htab **dest_dict = NULL;

  if (dest_dict == NULL) {
    dest_dict = create_hashtab();

    if (dest_dict == NULL) {
      return NULL;
    }

    // Populating hashtable with destination mnemonics and maps
    install("M", "001", dest_dict);
    install("D", "010", dest_dict);
    install("MD", "011", dest_dict);
    install("A", "100", dest_dict);
    install("AM", "101", dest_dict);
    install("AD", "110", dest_dict);
    install("AMD", "111", dest_dict);
  }

  return dest_dict;
}

htab **init_jump() {
  static htab **jump_dict = NULL;

  if (jump_dict == NULL) {
    jump_dict = create_hashtab();

    if (jump_dict == NULL) {
      return NULL;
    }

    // Populating hashtable with jump mnemonics and maps
    install("JGT", "001", jump_dict);
    install("JEQ", "010", jump_dict);
    install("JGE", "011", jump_dict);
    install("JLT", "100", jump_dict);
    install("JNE", "101", jump_dict);
    install("JLE", "110", jump_dict);
    install("JMP", "111", jump_dict);
  }

  return jump_dict;
}

htab **init_comp_a() {
  static htab **comp_dict = NULL;

  if (comp_dict == NULL) {
    comp_dict = create_hashtab();

    if (comp_dict == NULL) {
      return NULL;
    }

    // Populating hashtable with comp mnemonics and maps(for case a=0)
    install("0", "101010", comp_dict);
    install("1", "111111", comp_dict);
    install("-1", "111010", comp_dict);
    install("D", "001100", comp_dict);
    install("A", "110000", comp_dict);
    install("!D", "001101", comp_dict);
    install("!A", "110001", comp_dict);
    install("-D", "001111", comp_dict);
    install("-A", "110011", comp_dict);
    install("D+1", "011111", comp_dict);
    install("A+1", "110111", comp_dict);
    install("D-1", "001110", comp_dict);
    install("A-1", "110010", comp_dict);
    install("D+A", "000010", comp_dict);
    install("D-A", "010011", comp_dict);
    install("A-D", "000111", comp_dict);
    install("D&A", "000000", comp_dict);
    install("D|A", "010101", comp_dict);
  }

  return comp_dict;
}

htab **init_comp_b() {
  static htab **comp_dict = NULL;

  if (comp_dict == NULL) {
    comp_dict = create_hashtab();

    if (comp_dict == NULL) {
      return NULL;
    }

    // Populating hashtable with comp mnemonics and maps(for case a=1)
    install("M", "110000", comp_dict);
    install("!M", "110001", comp_dict);
    install("-M", "110011", comp_dict);
    install("M+1", "110111", comp_dict);
    install("M-1", "110010", comp_dict);
    install("D+M", "000010", comp_dict);
    install("D-M", "010011", comp_dict);
    install("M-D", "000111", comp_dict);
    install("D&M", "000000", comp_dict);
    install("D|M", "010101", comp_dict);
  }

  return comp_dict;
}

char *parse_C(char *s) {

  char *dest = strtok(s, "=");
  char *temp = strtok(NULL, "=");
  char *comp, *jump;

  if (temp == NULL) {
    comp = strtok(dest, ";");
    jump = strtok(NULL, ";");
    dest = NULL;
  } else {
    comp = temp;
    jump = NULL;
  }

  htab **dest_dict = init_dest();
  htab **jump_dict = init_jump();
  htab **comp_dict_a = init_comp_a();
  htab **comp_dict_b = init_comp_b();

  static char *result = NULL;
  free(result);
  result = (char *)malloc(18 * sizeof(char));

  result[0] = '1';
  result[1] = '1';
  result[2] = '1';
  // result[16] = '\n';
  // result[17] = '\0';

  htab *ref = NULL;

  if ((ref = lookup(comp, comp_dict_a)) != NULL) {
    result[3] = '0';
  } else {
    result[3] = '1';
    ref = lookup(comp, comp_dict_b);
  }

  strcat(result, ref->defn);

  if (dest != NULL) {
    ref = lookup(dest, dest_dict);

    if (ref == NULL) {
      fprintf(stderr,
              "Failed to find destination mnemonic in destination hashtable\n");
    } else {
      strcat(result, ref->defn);
    }
  } else {
    strcat(result, "000");
  }

  if (jump != NULL) {
    ref = lookup(jump, jump_dict);

    if (ref == NULL) {
      fprintf(stderr, "Failed to find jump mnemonic in jump hashtable\n");
    } else {
      strcat(result, ref->defn);
    }
  } else {
    strcat(result, "000");
  }

  strcat(result, "\n");

  return result;
}

// for testing parser function

// int main(int argc, char *argv[]) {
//   char s[] = "D=D-A";
//   printf("%s\n", parse_C(s));
//
//   char s1[] = "D;JGT";
//   printf("%s\n", parse_C(s1));
//   // parse_C(s1);
//
//   printf("Done\n");
//
//   return 0;
// }
