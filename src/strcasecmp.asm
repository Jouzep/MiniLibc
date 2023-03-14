bits 64

section .text
    global strcasecmp
;  int my_strcasecmp(const char *s1, const char *s2);
;                       RDI         RSI
strcasecmp:
    xor rcx, rcx
    xor r8, r8
    xor r9, r9
    xor r10, r10

.loop:
    .checkend:
        mov r8b, [rsi + rcx]
        mov r9b, [rdi + rcx]
        cmp r8, byte 0
        jz .end
        cmp r9, byte 0
        jz .end
    cmp r9b, 'A'
    jg .upper
    .compare:
        cmp r9b, r8b
        jne .end
        inc rcx
        jmp .loop

.upper:
    cmp r9b, 'Z'
    jg .lower
    mov r10, r9
    add r10, 32
    cmp r10b, r8b
    jne .compare
    inc rcx
    jmp .loop

.lower:
    cmp r9b, 'a'
    jl .compare
    cmp r9b, 'z'
    jg .compare
    mov r10, r9
    sub r10, 32
    cmp r10b, r8b
    inc rcx
    jmp .loop

.end:
    sub r9, r8
    mov rax, r9
    ret