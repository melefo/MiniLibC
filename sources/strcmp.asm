BITS 64

SECTION .text

GLOBAL strcmp

strcmp:
    XOR RAX, RAX
.loop:
    MOV AL, BYTE [RSI]
    CMP BYTE [RDI], AL
    JNE .end
    CMP BYTE [RDI], 0
    JE .end
    CMP BYTE [RSI], 0
    JE .end
    INC RSI
    INC RDI
    JMP .loop
.end:
    MOVSX EAX, BYTE [RDI]
    MOVSX EDX, BYTE [RSI]
    SUB EAX, EDX
.ret
    RET