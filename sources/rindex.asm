BITS 64

SECTION .text

GLOBAL rindex

rindex:
    XOR RAX, RAX
    XOR RDX, RDX
    CMP BYTE [RDI], 0
    JE .end
    JMP .cmp
.rdx:
    INC RDX
.cmp:
    CMP BYTE [RDI + RDX], 0
    JNE .rdx
.loop:
    CMP BYTE [RDI + RDX], SIL
    JE .set
    CMP RDX, 0
    JE .end
    DEC RDX
    JMP .loop
.set:
    MOV RAX, RDI
    ADD RAX, RDX
.end:
    RET