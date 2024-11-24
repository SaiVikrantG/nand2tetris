# Nand2Tetris Project 1: Boolean Logic

## Overview
This project is the foundation of the Nand2Tetris course. The goal was to implement basic Boolean logic gates using the hardware description language (HDL) provided by the course. These gates will serve as building blocks for more complex hardware systems in subsequent projects.

The starting point is the `Nand` gate, which is assumed to be pre-built. Using `Nand`, you will construct a series of gates and components following the principles of combinational logic.

---

## Components Implemented

### 1. **Not Gate**
   - **Description**: A single-input gate that outputs the negation of the input.
   - **Truth Table**:
     | Input | Output |
     |-------|--------|
     | 0     | 1      |
     | 1     | 0      |
   - **Implementation**: Built using a single `Nand` gate.

---

### 2. **And Gate**
   - **Description**: A two-input gate that outputs `1` only if both inputs are `1`.
   - **Truth Table**:
     | Input A | Input B | Output |
     |---------|---------|--------|
     | 0       | 0       | 0      |
     | 0       | 1       | 0      |
     | 1       | 0       | 0      |
     | 1       | 1       | 1      |
   - **Implementation**: Built using `Nand` and `Not` gates.

---

### 3. **Or Gate**
   - **Description**: A two-input gate that outputs `1` if at least one input is `1`.
   - **Truth Table**:
     | Input A | Input B | Output |
     |---------|---------|--------|
     | 0       | 0       | 0      |
     | 0       | 1       | 1      |
     | 1       | 0       | 1      |
     | 1       | 1       | 1      |
   - **Implementation**: Built using `Nand` and `Not` gates.

---

### 4. **Xor Gate**
   - **Description**: A two-input gate that outputs `1` if exactly one input is `1`.
   - **Truth Table**:
     | Input A | Input B | Output |
     |---------|---------|--------|
     | 0       | 0       | 0      |
     | 0       | 1       | 1      |
     | 1       | 0       | 1      |
     | 1       | 1       | 0      |
   - **Implementation**: Built using a combination of `And`, `Or`, and `Not` gates.

---

### 5. **Multiplexer (Mux)**
   - **Description**: A three-input gate that selects one of two inputs (`a` or `b`) based on a selector input (`sel`).
   - **Truth Table**:
     | sel | a | b | Output |
     |-----|---|---|--------|
     | 0   | 0 | 0 | 0      |
     | 0   | 1 | 0 | 1      |
     | 1   | 0 | 0 | 0      |
     | 1   | 0 | 1 | 1      |
   - **Implementation**: Built using `And`, `Or`, and `Not` gates.

---

### 6. **Demultiplexer (DMux)**
   - **Description**: A two-input gate that routes a single input to one of two outputs based on a selector input (`sel`).
   - **Truth Table**:
     | sel | Input | Output A | Output B |
     |-----|-------|----------|----------|
     | 0   | 0     | 0        | 0        |
     | 0   | 1     | 1        | 0        |
     | 1   | 0     | 0        | 0        |
     | 1   | 1     | 0        | 1        |
   - **Implementation**: Built using `And` and `Not` gates.

---


## Resources
- **Hardware Simulator**: [Download and usage guide](https://www.nand2tetris.org/software).
- **Nand2Tetris Book**: Chapters 1 and 2 for theoretical background and step-by-step instructions.
- **Course Website**: [Nand2Tetris](https://www.nand2tetris.org/).

---
