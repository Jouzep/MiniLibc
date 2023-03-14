bits 64

section .text
    global strrchr

strrchr:
    xor rcx, rcx
    mov rax, 0

.loop:
    cmp [rdi + rcx], sil
    jz .save
    cmp [rdi + rcx], byte 0
    jz .null 
    inc rcx
    jmp .loop

.save:
    lea rax, [rdi + rcx]
    cmp[rdi + rcx], byte 0
    je .end
    inc rcx
    jmp .loop

.null:
    cmp sil, byte 0
    je .fillnull
    jmp .end

.fillnull:
    lea rax, byte 0
.end:
    ret