BITS 64

SECTION .text

GLOBAL strchr
GLOBAL _strchr:function hidden

_strchr:
strchr:
    XOR RAX, RAX
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