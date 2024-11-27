// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, 
// the screen should be cleared.

(LOOP)
    @KBD
    D = M
    @DISPLAY
    D;JNE
    @WHITE
    0;JMP

(CONT1)
    D = 0
    @LOOP
    0;JMP

(DISPLAY)
    @BLACK
    0;JMP

(BLACK)
    @cursor
    M = 0
(COVER)
    @cursor
    D = M
    @SCREEN
    A = A+D
    M = -1
    D = D+1
    @cursor
    M = D
    @8192
    D = D-A
    @COVER
    D;JLT
    @CONT1
    0;JMP

(WHITE)
    @cursor
    M = 0
(COVER1)
    @cursor
    D = M
  @SCREEN
    A = A+D
    M = 0
    D = D+1
    @cursor
    M = D
    @8192
    D = D-A
    @COVER1
    D;JLT
    @CONT1
    0;JMP
