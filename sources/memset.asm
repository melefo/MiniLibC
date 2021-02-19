BITS 64

SECTION .text

GLOBAL memset

memset:
    MOV RAX, RDI
    CMP RDI, 0
    JE .end
.loop:
    CMP RDX, 0
    JE .end
    MOV BYTE [RDI], SIL
    DEC RDX
    INC RDI
    JMP .loop
.end:
    RET