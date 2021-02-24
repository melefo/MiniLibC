BITS 64

SECTION .text

GLOBAL strpbrk
GLOBAL _strpbrk:function hidden
EXTERN _strchr

_strpbrk
strpbrk:
    XOR RAX, RAX
    XOR R10, R10
    MOV R8, RDI
    MOV RDX, RSI
    JMP .loop
.inc:
    INC RDX
.loop:
    CMP BYTE [RDX], 0
    JE .ret
    MOV SIL, BYTE [RDX]
    CALL _strchr
    MOV RDI, R8
    CMP RAX, 0
    JE .inc
    CMP R10, 0
    JE .rep
    CMP RAX, R10
    JL .rep
    JMP .inc
.rep:
    MOV R10, RAX
    JMP .inc
.ret:
    MOV RAX, R10
    RET