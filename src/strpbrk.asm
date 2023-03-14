bits 64

section .text
    global strpbrk

strpbrk:
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
; .loop:
;     mov r9b, [rdi + rcx]
;     cmp r9b, byte 0
;     je .notfound
;     .compare:
;         cmp r9b, byte 0
;         je .point
;         cmp r9b, [rsi + rdx]
;         je .found
;         inc rdx
;         jmp .compare
;     .point:
;     inc rcx
;     jmp .loop

.notfound:
    lea rax, byte 0
    jmp .end

.found:
    lea rax, [rdi + rcx]
    ; mov rax, rcx
    jmp .end

.end:
    ret