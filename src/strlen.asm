bits 64

section .text

global strlen

strlen:
    xor     rcx, rcx

.loop:
    cmp     [rdi, rcx], byte 0
    jz      .stop
    inc     rcx
    jmp     .loop

.stop:
    mov rax, rcx
    ret