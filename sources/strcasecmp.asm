BITS 64

SECTION .text

GLOBAL strcasecmp

strcasecmp:
    XOR AL, AL
    CMP RDI, 0
    JE .null
    CMP RSI, 0
    JE .null
.rdi: ; first param to lower
    CMP BYTE [RDI + AL], 0
    JE .end
    CMP BYTE [RDI + AL], 'A'
    JL .rdiEnd
    CMP BYTE [RDI + AL], 'Z'
    JG .rdiEnd
    ADD BYTE [RDI + AL], ' '
.rdiEnd:
    INC AL
    JMP .rdi
    XOR AL, AL
.rsi: ; second param to lower
    CMP BYTE [RSI + AL], 0
    JE .end
    CMP BYTE [RSI + AL], 'A'
    JL .rsiEnd
    CMP BYTE [RSI + AL], 'Z'
    JG .rsiEnd
    ADD BYTE [RSI + AL], ' '
.rsiEnd:
    INC AL
    JMP .rsi
    XOR AL, AL
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