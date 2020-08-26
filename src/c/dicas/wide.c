#include <wchar.h>

int main(void) {
  wchar_t *s = L"papo";
  wprintf(L"%S\n", s);

  return 0;
}
