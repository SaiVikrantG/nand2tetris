// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
// The algorithm is based on repetitive addition.
    @2
    M = 0 //Sets value in RAM[2] to 0
(LOOP)
    @1
    D = M   //Set value of D to RAM[1]
    @END
    D;JEQ   //Jump to END if RAM[1]==0
    @1
    D = M-1
    @1
    M = D   //Set value of RAM[1] to register D
    @0
    D = M   //Set value of register D to RAM[0]
    @2
    M = M+D
    @LOOP
    0;JMP   //Jump to LOOP to iterate
(END)
    @END
    0;JMP   //Infinite loop to terminate execution
