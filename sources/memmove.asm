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
    DEC R10
    MOV BYTE [RDI + R10], R8B
    JMP .dest
.end:
    RET