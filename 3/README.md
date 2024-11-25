# Project 3: Sequential Logic

This project focused on building the foundational sequential logic components for the Hack computer. Unlike the combinational logic gates built in Project 1 and 2, these components involve **state**, enabling memory and time-based operations. 

The primary goal is to implement storage devices using **flip-flops**, culminating in the construction of a **16-bit register** and a **RAM** hierarchy.

---

## Components Built

### 1. **Bit**
- **Purpose**: Stores a single bit of data.
- **Inputs**:
  - `in`: The data value to store (1 bit).
  - `load`: Determines whether the input should be stored (`1`) or ignored (`0`).
- **Output**:
  - `out`: The stored data value (1 bit).
- **Implementation**: Built using a `DFF` (data flip-flop) to maintain the state across clock cycles.

---

### 2. **Register**
- **Purpose**: Stores a 16-bit value.
- **Inputs**:
  - `in[16]`: The 16-bit data to store.
  - `load`: Determines whether the input should be stored (`1`) or ignored (`0`).
- **Outputs**:
  - `out[16]`: The stored 16-bit value.
- **Implementation**: Combines 16 `Bit` gates to handle all 16 bits of data.

---

### 3. **RAM8**
- **Purpose**: Stores up to 8 16-bit values, with read/write capability for a specific address.
- **Inputs**:
  - `in[16]`: The 16-bit data to store.
  - `load`: Determines whether to store the input at the specified address.
  - `address[3]`: Specifies which of the 8 registers to access.
- **Outputs**:
  - `out[16]`: The 16-bit value stored at the specified address.
- **Implementation**: Combines 8 `Register` components with a **multiplexer** and **demultiplexer** for address-based access.

---

### 4. **RAM64**
- **Purpose**: Stores up to 64 16-bit values, with read/write capability for a specific address.
- **Inputs**:
  - `in[16]`: The 16-bit data to store.
  - `load`: Determines whether to store the input at the specified address.
  - `address[6]`: Specifies which of the 64 registers to access.
- **Outputs**:
  - `out[16]`: The 16-bit value stored at the specified address.
- **Implementation**: Combines 8 `RAM8` components with additional multiplexers and demultiplexers to handle the higher address space.

---

### 5. **RAM512**
- **Purpose**: Stores up to 512 16-bit values.
- **Inputs**:
  - `in[16]`: The 16-bit data to store.
  - `load`: Determines whether to store the input at the specified address.
  - `address[9]`: Specifies which of the 512 registers to access.
- **Outputs**:
  - `out[16]`: The 16-bit value stored at the specified address.
- **Implementation**: Combines 8 `RAM64` components with an expanded address decoding scheme.

---

### 6. **RAM4K**
- **Purpose**: Stores up to 4096 (4K) 16-bit values.
- **Inputs**:
  - `in[16]`: The 16-bit data to store.
  - `load`: Determines whether to store the input at the specified address.
  - `address[12]`: Specifies which of the 4096 registers to access.
- **Outputs**:
  - `out[16]`: The 16-bit value stored at the specified address.
- **Implementation**: Combines 8 `RAM512` components.

---

### 7. **RAM16K**
- **Purpose**: Stores up to 16,384 (16K) 16-bit values.
- **Inputs**:
  - `in[16]`: The 16-bit data to store.
  - `load`: Determines whether to store the input at the specified address.
  - `address[14]`: Specifies which of the 16,384 registers to access.
- **Outputs**:
  - `out[16]`: The 16-bit value stored at the specified address.
- **Implementation**: Combines 4 `RAM4K` components.

---

### 8. **PC (Program Counter)**
- **Purpose**: A 16-bit register that can increment its value, load a new value, or reset to 0.
- **Inputs**:
  - `in[16]`: The 16-bit value to load.
  - `load`: Determines whether to load the input (`1`) or retain the current value (`0`).
  - `inc`: Increments the counter by 1 when set to `1`.
  - `reset`: Resets the counter to 0 when set to `1`.
- **Outputs**:
  - `out[16]`: The current value of the program counter.
- **Implementation**: Combines a `Register`, an `Inc16` component, and control logic.

---

## Tools and Workflow

- **Hardware Simulator**: All components are implemented in HDL and tested using the Nand2Tetris hardware simulator.
- **Testing**:
  - `.tst` files: Provided testing scripts verify the correctness of each component.
  - `.cmp` files: Compare the actual output with the expected output.

---

## Directory Structure
- **HDL Files**: Contains all the implemented HDL components (`Bit.hdl`, `Register.hdl`, etc.).
- **Test Scripts**: Files ending with `.tst` to test each component.
- **Comparison Files**: Files ending with `.cmp` for expected output verification.


