BITS 64

SECTION .text

GLOBAL strncmp

strncmp:
    XOR AL, AL
    CMP RDI, 0
    JE .null
    CMP RSI, 0
    JE .null
    CMP RDX, 0
    JE .null
.loop:
    MOV AL, BYTE [RSI]
    CMP BYTE [RDI], AL
    JNE .end
    CMP RDX, 0
    JE .end
    INC RSI
    INC RDI
    DEC RDX
    JMP .loop
.end:
    MOV AL, BYTE [RDI]
    SUB AL, BYTE [RSI]
    RET
.null:
    MOV AL, 0
    RET