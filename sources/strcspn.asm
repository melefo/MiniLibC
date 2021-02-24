BITS 64

SECTION .text

GLOBAL strcspn
EXTERN _strpbrk
EXTERN _strlen

strcspn:
    XOR RAX, RAX
    CMP BYTE [RDI], 0
    JE .len
    CMP BYTE [RSI], 0
    JE .len
    CALL _strpbrk
    CMP RAX, 0
    JE .len
    SUB RAX, RDI
    RET
.len:
    CALL _strlen
    RET