#include <stdbool.h>

bool pe_ispe(const unsigned char *b) {
  return (b[0] == 'M' && b[1] == 'Z');
}
