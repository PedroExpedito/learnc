#include <stdio.h>
#include <math.h>

int main(void) {
  double a = 2.32f;
  char str[8];
  double integral;
  double fractional = modf(a, &integral);

  snprintf(str, 8, "%.2f", fractional);
  puts(str);
  snprintf(str, 8, "%.2f", integral);
  puts(str);

}
