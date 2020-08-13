#include <stdio.h>

int calc(int n) {
  for (int i = n-1; i > 0; i--) {
    n += i;
  }
  return n;
}
/* Codigo em assembly da para ver que usa instruções a mais

   0x0000000000001135 <+0>:     push   %rbp
   0x0000000000001136 <+1>:     mov    %rsp,%rbp
   0x0000000000001139 <+4>:     mov    %edi,-0x14(%rbp)
   0x000000000000113c <+7>:     mov    -0x14(%rbp),%eax
   0x000000000000113f <+10>:    sub    $0x1,%eax
   0x0000000000001142 <+13>:    mov    %eax,-0x4(%rbp)
   0x0000000000001145 <+16>:    jmp    0x1151 <calc+28>
   0x0000000000001147 <+18>:    mov    -0x4(%rbp),%eax
   0x000000000000114a <+21>:    add    %eax,-0x14(%rbp)
   0x000000000000114d <+24>:    subl   $0x1,-0x4(%rbp)
   0x0000000000001151 <+28>:    cmpl   $0x0,-0x4(%rbp)
   0x0000000000001155 <+32>:    jg     0x1147 <calc+18>
   0x0000000000001157 <+34>:    mov    -0x14(%rbp),%eax
   0x000000000000115a <+37>:    pop    %rbp
   0x000000000000115b <+38>:    retq

   São 14 linhas e ainda chama instruições de comparação....
*/


int calmat(int n) { return ((n + 1) * n) / 2; }

/*

   0x000000000000115c <+0>:     push   %rbp
   0x000000000000115d <+1>:     mov    %rsp,%rbp
   0x0000000000001160 <+4>:     mov    %edi,-0x4(%rbp)
   0x0000000000001163 <+7>:     mov    -0x4(%rbp),%eax
   0x0000000000001166 <+10>:    add    $0x1,%eax
   0x0000000000001169 <+13>:    imul   -0x4(%rbp),%eax
   0x000000000000116d <+17>:    mov    %eax,%edx
   0x000000000000116f <+19>:    shr    $0x1f,%edx
   0x0000000000001172 <+22>:    add    %edx,%eax
   0x0000000000001174 <+24>:    sar    %eax
   0x0000000000001176 <+26>:    pop    %rbp
   0x0000000000001177 <+27>:    retq

   11 linhas para fazer a mesma coisa
 */

int main(void) {
  printf("%d\n",calc(10));
  printf("%d\n",calmat(10));
}
