; visto no video do Fernando merces
; https://www.youtube.com/watch?v=m-_wli89FSg

; Compilar
; nasm -felf32 -o soma.o soma.asm
; ld -melf_i386 -o soma soma.o

; como pegar os argumentos passados para uma
; função

; Limitação não soma numero maior que o resultado é maior que 10

section .text
global _start

soma: ; int soma(int x, int y) { return x + y }
  mov eax, [esp+4]
  mov ebx, [esp+8]
  add eax, ebx ; eax = eax + ebx
  ret

_start: ;equivalente a main
  push ebp
  mov ebp, esp

  sub ebp, 4; int i

;soma
  push 1
  push 3
  call soma
  add esp, 8; limpar pilha

  add eax, 0x30
  mov [ebp-4], eax

; write
  mov eax, 4 ; NR_write
  mov ebx, 1 ; stdout
  ; load effect andress
  lea ecx, [ebp-4]
  mov edx, 1
  int 0x80

  pop ebp

; return 0
  mov eax, 1
  mov ebx, 0
  int 0x80
