#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MAX BUFFER SIZE
#define MAX_SIZE 100

void trim(char *s);

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

        // lines++;
      }
    }

    fclose(asm_file);
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
