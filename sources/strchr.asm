BITS 64

SECTION .text

GLOBAL strchr
GLOBAL _strchr:function hidden

_strchr:
strchr:
    XOR RAX, RAX
.loop:
    CMP BYTE [RDI], SIL
    JE .set
    CMP BYTE [RDI], 0
    JE .end
    INC RDI
    JMP .loop
.set:
    MOV RAX, RDI
.end:
    RET