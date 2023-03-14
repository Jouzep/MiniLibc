bits 64
; void *memcpy(void *dest, const void *src, size_t n);
;                 RDI          RSI          RDX
section .text
    global memmove

memmove:
    xor rcx ,rcx
    xor r8, r8

.loop:
    cmp rcx, rdx
    jz .end
    mov r8b, [rsi + rcx]
    mov [rdi + rcx], r8b
    inc rcx
    jmp .loop

.end:
    lea rax, [rdi]
    ret