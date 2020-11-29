;nasm -f elf32 hello.asm
;ld -m elf_i386 -o hello32E hello.o

section .data:
  msg db 'Hello World', 0xa
  len equ $ - msg


section .text:


global _start


_start:
  mov edx, len
  mov ecx, msg
  mov ebx, 1
  mov eax, 4
  int 0x80

; saida (return 0)
  mov eax, 1
  mov ebx, 0
  int 0x80
