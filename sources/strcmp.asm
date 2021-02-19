BITS 64

SECTION .text

GLOBAL strcmp

strcmp:
    XOR AL, AL
    CMP RDI, 0
    JE .null
    CMP RSI, 0
    JE .null
.loop:
    MOV AL, BYTE [RSI]
    CMP BYTE [RDI], AL
    JNE .end
    INC RSI
    INC RDI
    JMP .loop
.end:
    MOV AL, BYTE [RDI]
    SUB AL, BYTE [RSI]
    RET
.null:
    MOV AL, 0
    RET