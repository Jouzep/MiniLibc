bits 64
;size_t strcspn(const char *s, const char *reject);
;                       RDI,    RSI
section .text
    global strcspn

strcspn:
    xor rcx, rcx ; loop 1
    xor rdx, rdx ; loop 2
    xor r9, r9 ; tmp 1
.loop:
    mov r9b, [rdi + rcx]
    cmp r9, byte 0
    je .notfound
    .compare:
        cmp r9b, [rsi + rdx]
        je .found
        cmp [rsi + rdx], byte 0
        je .next
        inc rdx
        jmp .compare 
    .next:
        inc rcx
        xor rdx, rdx
        xor r9, r9
        jmp .loop
.notfound:
    mov rax, rcx
    jmp .end
.found:
    mov rax, rcx
    jmp .end
.end:
    ret