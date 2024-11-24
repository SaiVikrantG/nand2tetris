# Project 2: Boolean Arithmetic

This project focused on building key components of the Hack architecture related to arithmetic and logical operations. The main goal is to construct a collection of combinational logic gates, culminating in the **ALU (Arithmetic Logic Unit)**. These gates are built using the hardware description language (HDL) and are tested using the provided testing scripts.

## Components Built

### 1. **HalfAdder**
- **Purpose**: Computes the sum and carry of two input bits.
- **Inputs**: 
  - `a`: First input bit.
  - `b`: Second input bit.
- **Outputs**:
  - `sum`: Sum of `a` and `b` (ignoring carry-in).
  - `carry`: Carry-out from the addition.
- **Implementation**: Built using `Xor` and `And` gates.

---

### 2. **FullAdder**
- **Purpose**: Computes the sum of three input bits, accommodating a carry-in bit.
- **Inputs**:
  - `a`: First input bit.
  - `b`: Second input bit.
  - `c`: Carry-in bit.
- **Outputs**:
  - `sum`: Sum of `a`, `b`, and `c`.
  - `carry`: Carry-out from the addition.
- **Implementation**: Combines two `HalfAdder` gates and an `Or` gate.

---

### 3. **Add16**
- **Purpose**: Adds two 16-bit values.
- **Inputs**:
  - `a[16]`: First 16-bit input.
  - `b[16]`: Second 16-bit input.
- **Output**:
  - `out[16]`: 16-bit sum of `a` and `b`.
- **Implementation**: Chains 16 `FullAdder` gates to handle bit-wise addition.

---

### 4. **Inc16**
- **Purpose**: Increments a 16-bit value by 1.
- **Input**:
  - `in[16]`: A 16-bit input.
- **Output**:
  - `out[16]`: Incremented 16-bit value (`in + 1`).
- **Implementation**: Built using the `Add16` gate, with the second input set to `1`.

---

### 5. **ALU**
- **Purpose**: Performs arithmetic and logical operations based on control bits.
- **Inputs**:
  - `x[16]`: First 16-bit input.
  - `y[16]`: Second 16-bit input.
  - `zx`: Zero the `x` input (set all bits of `x` to 0).
  - `nx`: Negate the `x` input (bitwise NOT of `x`).
  - `zy`: Zero the `y` input (set all bits of `y` to 0).
  - `ny`: Negate the `y` input (bitwise NOT of `y`).
  - `f`: Function control:
    - `0`: Perform bitwise AND on `x` and `y`.
    - `1`: Perform addition on `x` and `y`.
  - `no`: Negate the output.
- **Outputs**:
  - `out[16]`: 16-bit result based on the inputs and control bits.
  - `zr`: Zero flag (`1` if `out` is 0, otherwise `0`).
  - `ng`: Negative flag (`1` if `out` is negative, otherwise `0`).
- **Implementation**: Combines multiple sub-components (e.g., `Add16`, `And`, `Mux16`, etc.) to process the inputs based on the control bits.

---

## Tools and Workflow
- **Hardware Simulator**: All gates were implemented and tested in the Nand2Tetris hardware simulator.
- **Testing**: Provided `.tst` and `.cmp` files were used to verify correctness for each component.

---
