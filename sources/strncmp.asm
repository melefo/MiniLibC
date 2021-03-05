BITS 64

SECTION .text

GLOBAL strncmp

strncmp:
    XOR RAX, RAX
    CMP RDX, 0
    JE .ret
    CMP BYTE [RDI], 0
    JE .end
    CMP BYTE [RSI], 0
    JE .end
    MOV AL, BYTE [RSI]
    CMP BYTE [RDI], AL
    JNE .end
    INC RSI
    INC RDI
    DEC RDX
    JMP strncmp
.end:
    MOVSX EAX, BYTE [RDI]
    MOVSX EDX, BYTE [RSI]
    SUB EAX, EDX
.ret:
    RET