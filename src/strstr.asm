bits 64
;char *strstr(const char *haystack, const char *needle);
;                    RDI                , RSI,      rdx
section .text
    global strstr
extern strlen
extern strncmp

strstr:


    cmp [rsi], byte 0
    je .nullcomparison
    lea r12, [rdi]; save rdi
    ; get the length
    mov rdi, rsi ; push rsi to rdi
    call strlen wrt ..plt; get the length of arg2
    mov rdi, r12
    mov rdx, rax ; set the length

.loop:
    xor rax, rax
    xor rcx, rcx
    call strncmp wrt ..plt
    jz .found
    cmp [rdi], byte 0
    je .notfound
    add rdi, 1
    jmp .loop

.notfound:
    xor rax, rax
    lea rax, byte 0
    jmp .end

.help:
    sub rdi, 1
    jmp .found2

.found:
    mov r9b, [rsi]
    cmp [rdi], r9b
    jne .help
    .found2:
    xor rax, rax
    lea rax, [rdi]
    jmp .end

.nullcomparison:
    lea rax, [rdi]
    ret

.end:
    xor rdi, rdi
    lea rdi, [r12]
    ret
