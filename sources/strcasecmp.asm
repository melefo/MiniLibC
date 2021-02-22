BITS 64

SECTION .text

GLOBAL strcasecmp

strcasecmp:
    XOR RAX, RAX
.loop:
    MOV AL, BYTE [RDI]
    MOV DL, BYTE [RSI]
.rdi:
    CMP AL, 'A'
    JL .rsi
    CMP AL, 'Z'
    JG .rsi
    ADD AL, 'a' - 'A'
.rsi:
    CMP DL, 'A'
    JL .cmp
    CMP DL, 'Z'
    JG .cmp
    ADD DL, 'a' - 'A'
.cmp:
    CMP AL, DL
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
    RET