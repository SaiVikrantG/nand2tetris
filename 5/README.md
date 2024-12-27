# nand2tetris Project 5: Computer Architecture

This project focuses on implementing the **Memory Chip**, **CPU Chip**, and **Computer Chip** for HACK architecture. The goal is to assemble these components into a working computer system that can execute a program from memory. This README provides an overview of the chips' specifications and address ranges, as well as details about the screen and keyboard chips.

## Specifications

### Memory Chip
The **Memory Chip** is responsible for storing data and instructions in the computer system. It implements random access memory (RAM) functionality. The chip must handle reads and writes to memory.

- **Size**: 32K (32,768 memory locations)
- **Address Range**: 0x0000 to 0x7FFF (0 to 32767 in decimal)
- **Input/Output**:
  - **Input**: 
    - **Address (15 bits)**: A 16-bit address to access a specific memory location.
    - **Write Data (16 bits)**: A 16-bit value to write to the specified address.
    - **Write Enable**: A control signal that allows the chip to write data to memory when asserted.
  - **Output**:
    - **Read Data (16 bits)**: The 16-bit value stored at the given address.

### CPU Chip
The **CPU Chip** is the central processing unit of the computer. It executes instructions from memory, handles the control flow, and performs arithmetic and logic operations.

- **Size**: 16-bit architecture (16-bit registers, 16-bit instructions)
- **Registers**:
  - **Program Counter (PC)**: Points to the address of the next instruction to execute (15 bits).
  - **Instruction Register (IR)**: Holds the current instruction (16 bits).
  - **Data Register (D)**: Holds data temporarily (16 bits).
  - **A Register (A)**: Holds data or an address (16 bits).
- **Instruction Set**:
  - Supports arithmetic operations (e.g., addition, subtraction, bitwise operations).
  - Supports jumps, conditional branches, and subroutine calls.
  - Access to the memory chip for loading and storing data.

### Computer Chip
The **Computer Chip** is a high-level integration of the Memory Chip, CPU Chip, and other peripherals. It implements the full computer system, allowing you to load, run, and debug programs.

- **Components**:
  - **CPU Chip** (as described above)
  - **Memory Chip** (as described above)
  - **Screen Chip**
  - **Keyboard Chip**
- **Connections**:
  - The **CPU** communicates with the **Memory Chip** to fetch and execute instructions.
  - The **Screen Chip** handles output to the screen.
  - The **Keyboard Chip** reads input from the keyboard.
  
### Address Ranges

- **Memory Address Range**: 
  - The **Memory Chip** has a 16-bit address space, supporting addresses from `0x0000` to `0x7FFF` (i.e., 32K memory locations).
  
- **Screen Address Range**:
  - The **Screen Chip** controls the screen output, with a memory-mapped address range from `0x4000` to `0x5FFF`.
  - Each location corresponds to a 16-bit value, where each bit represents a pixel on the screen.
  - The screen has a resolution of 256x512 pixels, which is mapped to the memory range starting at `0x4000`.
  
- **Keyboard Address Range**:
  - The **Keyboard Chip** is mapped to the address range `0x6000` to `0x600F`.
  - The chip can be used to read a 16-bit value, representing the state of the keyboard.

## How It Works

1. **Memory Chip**:
   - The Memory Chip is accessed by the CPU via the address bus and the data bus.
   - Memory read and write operations are controlled by the CPU. The Memory Chip supports read and write operations based on the CPU's control signals.

2. **CPU Chip**:
   - The CPU fetches instructions from memory, decodes them, and executes them, interacting with the memory, screen, and keyboard.
   - The CPU manages the **Program Counter** to point to the next instruction, loads the instruction into the **Instruction Register**, and processes it.

3. **Screen Chip**:
   - The Screen Chip is memory-mapped. The CPU can write data to the screen's memory range to update the pixels.
   - Each memory location in the screen's address range represents one pixel (1-bit monochrome image).

4. **Keyboard Chip**:
   - The Keyboard Chip is also memory-mapped. It can be read by the CPU to check which keys are pressed.
   - The CPU can read the keyboard data from the range `0x6000` to `0x600F`.

## Usage

1. **Program Execution**:
   - Load your program into the memory chip, starting from address `0x0000`.
   - The CPU will execute instructions from memory, updating the screen and reading input from the keyboard as needed.

2. **Screen Output**:
   - The program can output data to the screen using the memory-mapped address range `0x4000` to `0x5FFF`.
   - Each pixel can be toggled by writing data to the screen memory locations.

3. **Keyboard Input**:
   - The program can read the state of the keyboard from the memory-mapped range `0x6000` to `0x600F`.
   - This allows the user to provide input to the program.
