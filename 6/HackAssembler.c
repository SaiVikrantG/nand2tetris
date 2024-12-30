#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MAX BUFFER SIZE
#define MAX_SIZE 100

int main(int argc, char *argv[]) {
  FILE *asm_file;
  char line[MAX_SIZE]; // Buffer to store file content

  asm_file = fopen(argv[1], "r"); // Pointer to file

  if (NULL == asm_file) {
    printf("Assembly file doesn't exist\n");
  } else {

    printf("Contents of this file are:\n");

    while (fgets(line, MAX_SIZE, asm_file) != NULL) {
      if (line[0] == ' ' || line[0] == '/' ||
          line[0] == '\n') { // Find a better way to ignore whitespaces and
                             // comments. Looks too burteforce-ish
        continue;
      } else {
        char *inst = strtok(line, "//");

        while (NULL != inst) {
          printf("%s\n", inst);
          inst = strtok(NULL, "//");
        }

        // printf("%s", line);
      }
    }

    fclose(asm_file);
  }

  return 0;
}
