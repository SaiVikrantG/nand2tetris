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
  char *comp = strtok(NULL, ";");
  char *jump = strtok(NULL, ";");

  htab **dest_dict = init_dest();
  htab **jump_dict = init_jump();
  htab **comp_dict_a = init_comp_a();
  htab **comp_dict_b = init_comp_b();

  return s;
}

int main(int argc, char *argv[]) {
  char s[] = "D=D+A;JGT";
  parse_C(s);

  return 0;
}
