// TODO: Free memory after using malloc bruh

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MAX BUFFER SIZE
#define MAX_SIZE 100

typedef enum { ADDRESS = 0, COMP, LABEL } InstructionType;

void trim(char *s);
InstructionType identify_type(char *s);
char *convert(char *s);

int main(int argc, char *argv[]) {
  char line[MAX_SIZE]; // Buffer to store file content
  int lines = 0;

  FILE *asm_file = fopen(argv[1], "r"); // Pointer to file

  if (NULL == asm_file) {
    printf("Assembly file doesn't exist\n");
  } else {
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

        trim(inst);

        char *conv_inst = convert(inst);

        fputs(conv_inst, hack_file);
        fputs("\n", hack_file);
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
  memset(result, '0', sizeof(char) * 16);

  if (type == ADDRESS) {
    result[0] = '0';

    int address = atoi(s + 1);
    int i = 15;

    while (address > 0) {
      result[i--] = address % 2 + '0';
      address = address / 2;
    }
  } else {
  }

  return result;
}
