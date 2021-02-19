BITS 64

SECTION .text

GLOBAL strlen

strlen:
    XOR RAX, RAX
    CMP BYTE [RDI], 0
    JE .end
.loop:
    INC RAX
    INC RDI
    CMP BYTE [RDI], 0
    JNE .loop
.end:
    RET