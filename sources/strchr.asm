BITS 64

SECTION .text

GLOBAL strchr

strchr:
    MOV RAX, 0
    CMP BYTE [RDI], 0
    JE .end
    CMP BYTE [RDI], SIL
    JE .set
.loop:
    INC RDI
    CMP BYTE [RDI], 0
    JE .end
    CMP BYTE [RDI], SIL
    JNE .loop
.set:
    MOV RAX, RDI
.end:
    RET