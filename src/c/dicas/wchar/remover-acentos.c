#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>

// função para remover acentos

void wchar_replace(wchar_t *texto, wchar_t find, wchar_t replace) {
  wchar_t *current_pos = wcschr(texto, find);

// printf("Current_pos char: %p, wc in find %lc\n", current_pos, find);
  while(current_pos != NULL) {
    *current_pos = replace;
    current_pos = wcschr(texto, find);
  }
}

void removerAcentos(wchar_t *texto) {

  wchar_t comAcentos[] = L"ÄÅÁÂÀÃäáâàãÉÊËÈéêëèÍÎÏÌíîïìÖÓÔÒÕöóôòõÜÚÛüúûùÇç";
  wchar_t semAcentos[] = L"AAAAAAaaaaaEEEEeeeeIIIIiiiiOOOOOoooooUUUuuuuCc";
  int size = wcslen(comAcentos);
//  printf("size: %lu\n", size);

  for (int i = 0; i < size ; i++) {
    wchar_replace(texto, comAcentos[i], semAcentos[i]);
  }
}

int main(void) {

  // precisa verificar se tem esse locale
  setlocale(LC_ALL, "en_US.UTF-8");

  char *a = "Ação";
  wchar_t c[5];

  swprintf(c, 5, L"%hs", a);

  removerAcentos(c);

  //printf("%lc\n", p[1]);
  printf("%ls\n", c);

  return 0;
}
