BITS 64

SECTION .text

GLOBAL memmove

memmove:
    MOV RAX, RDI
    XOR R10, R10
.tmp:
    CMP R10, RDX
    JE .dest
    MOVSX R8, BYTE [RSI + R10]
    PUSH R8
    INC R10
    JMP .tmp
.dest:
    CMP R10, 0
    JE .end
    POP R8
    MOV BYTE [RDI + R10 - 1], R8B
    DEC R10
    JMP .dest
.end:
    RET