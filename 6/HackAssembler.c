// TODO: Free memory after using malloc bruh

#include "hashmap.h"
#include "parser.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MAX BUFFER SIZE
#define MAX_SIZE 100

// ENUMS
typedef enum { ADDRESS = 0, COMP, LABEL } InstructionType;

// GLOBAL VARIABLES
htab **symbol_table;
int free_ram_addr = 16;

// FUNCTION DECLARATIONS
void trim(char *s);
InstructionType identify_type(char *s);
char *convert(char *s);
void first_pass(FILE *asm_file);
void itoa(char *num, int i);

// MAIN IMPLEMENTATION STARTS
int main(int argc, char *argv[]) {
  char line[MAX_SIZE]; // Buffer to store file content
  int lines = 0;

  FILE *asm_file = fopen(argv[1], "r"); // Pointer to file

  if (NULL == asm_file) {
    printf("Assembly file doesn't exist\n");
  } else {
    first_pass(asm_file);

    char *name = strtok(argv[1], ".");

    FILE *hack_file = fopen(strcat(name, ".hack"), "w+");

    if (NULL == hack_file) {
      printf("Error in opening in hack file.\n");

      return 0;
    }

    while (fgets(line, MAX_SIZE, asm_file) != NULL) {
      if (line[0] == '/' ||
          line[0] == '\r') { // TODO: Find a better way to ignore whitespaces
                             // and comments. Looks too burteforce-ish
        continue;
      } else {
        char *inst = strtok(line, "//");
        char *temp = inst;
        int flag = 0;

        while (*temp !=
               '\0') { // TODO: Need to improve this whitespace check condition
          if (*temp != ' ') {
            flag = 1;
            break;
          }

          temp++;
        }

        if (!flag) {
          continue;
        }

        trim(inst);

        char *conv_inst = convert(inst);

        fputs(conv_inst, hack_file);
        // fputs("\n", hack_file);
      }
    }

    fclose(asm_file);
    fclose(hack_file);
  }

  return 0;
}

void trim(char *s) {
  // removes leading and trailing whitespaces
  int i = 0, j = 0;

  while (s[i] == ' ') {
    i++;
  }

  while (s[i] != '\r' && s[i] != ' ') {
    s[j++] = s[i++];
  }

  s[j] = '\0';
}

InstructionType identify_type(char *s) {
  // idetifies type of instruction

  if (s[0] == '@') {
    return ADDRESS;
  } else if (s[0] == '(') {
    return COMP;
  } else {
    return LABEL;
  }
}

char *convert(char *s) {
  InstructionType type = identify_type(s);
  char *result = (char *)malloc(sizeof(char) * 16);
  memset(result, '0', sizeof(char) * 17);

  if (type == ADDRESS) {
    if (!isdigit(s[1])) {
      htab *ref = lookup(s + 1, symbol_table);

      if (ref == NULL) {
        printf("Symbol not found in symbol table\n");
      } else {
        // printf("Original: %s\n", s);

        int i = 0;
        char *sym = ref->defn;

        for (; sym[i] != '\0'; i++) {
          s[i + 1] = sym[i];
        }

        s[i + 1] = '\0';

        // printf("Translated from symbol table: %s\n", s);
      }
    }

    int address = atoi(s + 1);
    int i = 15;

    while (address > 0) {
      result[i--] = address % 2 + '0';
      address = address / 2;
    }

    result[16] = '\n';
  } else if (type == LABEL) {
    result = parse_C(s);
  } else {
    result[0] = '\0';
  }

  return result;
}

void first_pass(FILE *asm_file) {
  char line[MAX_SIZE];
  int line_no = 0;
  symbol_table = create_hashtab();

  // populating symbol tabe with predefined symbols
  install("SP", "0", symbol_table);
  install("LCL", "1", symbol_table);
  install("ARG", "2", symbol_table);
  install("THIS", "3", symbol_table);
  install("THAT", "4", symbol_table);
  install("SCREEN", "16384", symbol_table);
  install("KBD", "24576", symbol_table);

  char num[12];

  for (int i = 0; i < 16; i++) {
    itoa(num, i); // Try to make this conversion efficient
    char reg[4] = "R";

    strcat(reg, num);

    install(reg, num, symbol_table);
  }

  while (fgets(line, MAX_SIZE, asm_file) != NULL) {

    if (identify_type(line) == COMP) {
      char *label = line;
      label++;
      label[strlen(label) - 3] = '\0';
      itoa(num, line_no + 1);

      install(label, num, symbol_table);
    } else {
      line_no++;
    }
  }

  // prod(symbol_table);
  rewind(asm_file);
}

void itoa(char *num, int i) {
  int j = 0;

  if (i == 0) {
    num[j++] = i + '0';
  } else {
    while (i > 0) {
      num[j++] = i % 10 + '0';
      i = i / 10;
    }
  }

  num[j] = '\0';

  for (int k = 0, l = j - 1; k < l; k++, l--) {
    char temp = num[k];
    num[k] = num[l];
    num[l] = temp;
  }
}
