bits 64

section .text
    global strcmp
;  int my_strcmp(const char *s1, const char *s2);
;                       RDI         RSI
strcmp:
    xor rcx, rcx
    xor r8, r8
    xor r9, r9

.loop:
    mov r8b, [rsi + rcx]
    mov r9b, [rdi + rcx]
    cmp r8, byte 0
    jz .end
    cmp r9, byte 0
    jz .end
    cmp r9b, r8b
    jne .end
    inc rcx
    jmp .loop

.end:
    sub r9, r8
    mov rax, r9
    ret