#include <stdint.h>
#include <signal.h>
#include <assert.h>
#include <cmath>

#include <SDL2/SDL.h>
#include <vector>

typedef uint_least32_t u32;
typedef uint_least16_t u16;
typedef uint_least8_t u8;
typedef int_least8_t s8;

template <unsigned bitno, unsigned nbits=1, typename T=u8>

struct RegBit {
  T data;
  template<typename T2>
  RegBit& operator=(T2 val)
  {
  }
  operator unsigned() const {}
  RegBit& operator++ () {}
  unsigned operador++ (int) {}
};

namespace CPU {
  // CPU registers:
  u16 PC=0xC000;
  u8 A=0,X=0,S=0;

  union {
    u8 raw;
    RegBit<0> ;
    RegBit<1> ;
    RegBit<2> ;
    RegBit<3> ;
    RegBit<4> ;
    RegBit<5> ;
    RegBit<6> ;
    RegBit<7> ;
  } P;
}

