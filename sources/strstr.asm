BITS 64

SECTION .text

GLOBAL strstr

strstr:
    XOR RAX, RAX
    XOR RDX, RDX
.loop:
    CMP BYTE [RSI + RDX], 0
    JE .set
    CMP BYTE [RDI + RDX], 0
    JE .end
    MOV R10B, BYTE [RSI + RDX]
    CMP BYTE [RDI + RDX], R10B
    JNE .false
    INC RDX
    JMP .loop
.false:
    MOV RDX, 0
    INC RDI
    JMP .loop
.set:
    MOV RAX, RDI
.end:
    RET