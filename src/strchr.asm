bits 64

section .text
    global strchr

strchr:
    xor rcx, rcx; init
.loop:
    cmp [rdi + rcx] , sil ; les crochets transforment en 8 bits
    jz .fillpointer
    cmp [rdi + rcx] , byte 0 ; les crochets transforment en 8 bits
    jz .null
    inc rcx
    jmp .loop

.fillpointer:
    lea rax, [rdi + rcx] ; envoie adresse a rax
    jmp .end
.null:
    lea rax, byte 0
    jmp .end
.end:
    ret