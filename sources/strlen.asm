BITS 64

SECTION .text

GLOBAL strlen

strlen:
    XOR RAX, RAX
    CMP BYTE [RDI], 0
    JE .end
.loop:
    INC RAX
    CMP BYTE [RDI + RAX], 0
    JNE .loop
.end:
    RET