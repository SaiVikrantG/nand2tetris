
# Project 6 - Machine Language Assembler (C Implementation)

## Overview
In Project 6 of the Nand2Tetris course, the task is to implement an assembler that converts Hack assembly language code into machine code. The assembler reads the input `.asm` file, parses Hack assembly instructions, processes labels and variables, and outputs a `.hack` file containing the corresponding binary machine code. This implementation has been written in C.

The assembler must correctly handle both A-instructions (which load values into the A register) and C-instructions (which perform computation and control flow operations in the Hack machine). The goal is to generate machine code that can be loaded into the Hack Simulator.


## Files
- **HackAssembler.c**: The main C file that implements the assembler logic and translates assembly code to machine code.
- **parser.c**: Helper function that convert the C-instruction specifically read from `.asm` files.
- **hashmap.c**: Provides functions to create and operate on HashMaps.
- **___.asm**: Sample input Hack assembly programs used for testing the assembler.

## How to Run
To run the assembler, follow these steps:

1. Ensure that you have a C compiler such as GCC installed.
2. Compile the program using the following command in the root directory:
   ```bash
   gcc *.c -o HackAssembler

3. Run the assembler with the `.asm` files provided in add, max, pong and rect directories:
  ```bash
  ./HackAssembler path/to/file.asm
  ```

The assembler generates a .hack file in the same directory as the provided `.asm` files. The `.hack` files can be run using the compiled HackAssembler.

## Issues
- The hashmap needs better collision handling schemes, in the case that if two keys have the same hash, then the hashmap just stores the values one after the other in the form of a linked list, and the correct value needs to be found by iterating through the linked list.
- Using singletons for the hash tables for storing COMP, JUMP and DEST mnemonics in the `parser.c` file, is not good practice. Better to store it in a struct to encapsulate all the hashmaps and expose it through the parser.h file.
- Name variables and functions more clearly to exhibit their proper functionality just by reading the names. Also write better comments to explain what and how the function achieves it's functionality, it's parameters and return values etc.
- Use proper modifiers in parameters.
- Need to handle errors and exit from the program effectively, providing accurate error log information.
- Handle buffer overflows(mostly due to using `strcat`).

## Mentions
- The hashmap implementation was taken from the K&R book, and has worked effectively in storing mnemonics and their mappings, and as a symbol table. The implementation was found in this stack overflow thread [Quick way to implement a dictionary in c](https://stackoverflow.com/questions/4384359/quick-way-to-implement-dictionary-in-c).


