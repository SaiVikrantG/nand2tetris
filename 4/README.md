# Project 4: Hack Instruction Set Architecture (ISA)

This README provides an overview of the Hack Instruction Set Architecture (ISA) as specified in Chapter 4 of the **Nand2Tetris** course. It includes details about the Hack assembly language, instruction types, and memory model. This serves as a reference for implementing and working with the Hack ISA in this project.

---

## Overview of the Hack ISA

The Hack ISA defines the assembly language and machine language used to program the Hack computer. It supports two types of instructions:
1. **A-instructions** (Address instructions)
2. **C-instructions** (Compute instructions)

### Hack Word
Each instruction is a 16-bit word:
- **A-instructions**: Specify memory addresses or constants.
- **C-instructions**: Perform computations and memory operations.

---

## 1. A-Instruction

The A-instruction is used to:
- Load a value into the `A` register.
- Specify a memory address for subsequent operations.

### Format
0 v v v v v v v v v v v v v v v

- **Bit 15**: `0` (indicates an A-instruction)
- **Bits 0–14**: A 15-bit value (`v`), representing:
  - A constant value.
  - A memory address.

### Examples
- `@42`: Loads the constant `42` into the `A` register.
- `@myVariable`: Loads the address of `myVariable` into the `A` register.

---

## 2. C-Instruction

The C-instruction is used for:
- Performing computations.
- Storing values in registers or memory.
- Controlling program flow with jumps.

### Format
1 1 1 a c1 c2 c3 c4 c5 c6 d1 d2 d3 j1 j2 j3

#### Components
1. **Bits 15–13**: `111` (indicates a C-instruction).
2. **Bit 12 (`a`)**:
   - `0`: Computation uses the `A` register.
   - `1`: Computation uses the memory value at address `A` (`M`).
3. **Bits 11–6 (`c1–c6`)**: Specify the computation (ALU operation).
4. **Bits 5–3 (`d1–d3`)**: Specify the destination(s).
5. **Bits 2–0 (`j1–j3`)**: Specify the jump condition.

---

### Computation Bits (`c1–c6`)
These bits specify the ALU operation. The table below summarizes supported operations:

| `a` | `c1 c2 c3 c4 c5 c6` | Computation |
|-----|---------------------|-------------|
| 0   | 010101              | `0`         |
| 0   | 011111              | `1`         |
| 0   | 011010              | `-1`        |
| 0   | 000110              | `D`         |
| 0   | 110000              | `A`         |
| 1   | 110000              | `M`         |
| 0   | 001111              | `!D`        |
| 0   | 110001              | `!A`        |
| 1   | 110001              | `!M`        |
| 0   | 001111              | `-D`        |
| 0   | 110011              | `-A`        |
| 1   | 001111              | `-M`        |
| 0   | 011111              | `D+1`       |
| 0   | 110111              | `A+1`       |
| 1   | 110111              | `M+1`       |
| 0   | 001110              | `D-1`       |
| 0   | 110010              | `A-1`       |
| 1   | 110010              | `M-1`       |
| 0   | 000010              | `D+A`       |
| 1   | 000010              | `D+M`       |
| 0   | 010011              | `D-A`       |
| 1   | 000010              | `D-M`       |
| 0   | 000111              | `A-D`       |
| 1   | 000111              | `M-D`       |
| 0   | 000000              | `D&A`       |
| 1   | 000000              | `D&M`       |
| 0   | 010101              | `D\|A`      |
| 1   | 010101              | `D\|M`      |


---

### Destination Bits (`d1–d3`)
These bits specify where the result of the computation will be stored.

| `d1` | `d2` | `d3` | Destination |
|------|------|------|-------------|
|  0   |  0   |  0   | No destination |
|  1   |  0   |  0   | `M` (memory)   |
|  0   |  1   |  0   | `D` (data register) |
|  0   |  0   |  1   | `A` (address register) |
|  1   |  1   |  0   | `MD` (memory and data register) |

---

### Jump Bits (`j1–j3`)
These bits specify the jump condition. The table below summarizes the supported conditions:

| `j1` | `j2` | `j3` | Jump Condition       |
|------|------|------|----------------------|
|  0   |  0   |  0   | No jump             |
|  0   |  0   |  1   | `JGT` (greater than) |
|  0   |  1   |  0   | `JEQ` (equal)       |
|  0   |  1   |  1   | `JGE` (greater or equal) |
|  1   |  0   |  0   | `JLT` (less than)   |
|  1   |  0   |  1   | `JNE` (not equal)   |
|  1   |  1   |  1   | `JMP` (unconditional jump) |

---

## Example C-Instruction
D = M + 1; JGT

Explanation:

Computation: M + 1 (value at memory address A plus 1).
Destination: D register.
Jump Condition: Jump if the result is greater than zero.

### Hack Memory Model

Registers:
R0 to R15 (mapped to RAM[0] to RAM[15]).

Predefined Pointers:
SCREEN (RAM[16384]): Video memory.
KBD (RAM[24576]): Keyboard input.
