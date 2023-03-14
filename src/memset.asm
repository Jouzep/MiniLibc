bits 64
;void *memset(void *s, int c, size_t n);
section .text
    global memset

memset:
    push rbp
    mov rbp, rsp
    xor rcx, rcx
.loop:
    cmp rcx, rdx
    je .end
    mov [rdi + rcx], sil
    inc rcx
    jmp .loop
.end:
    lea rax, [rdi]
    leave
    ret