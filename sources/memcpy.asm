BITS 64

SECTION .text

GLOBAL memcpy

memcpy:
    MOV RAX, RDI
    CMP RDI, 0
    JE .end
.loop:
    CMP RDX, 0
    JE .end
    MOV R10B, BYTE [RSI]
    MOV BYTE [RDI], R10B
    DEC RDX
    INC RDI
    INC RSI
    JMP .loop
.end:
    RET