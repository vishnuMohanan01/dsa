/*
 * Given 2 binary numbers M and N, write a program to insert M into N between 2 given given positions i and j.
*/
#include <cstdint>
#include <assert.h>

using namespace std;

uint32_t insert(u_int32_t m, uint32_t n, uint32_t i, uint32_t j) {
  uint32_t left = ~0 << (j + 1);
  uint32_t right = (1 << i) - 1;
  uint32_t mask = left | right;
  
  n &= mask;
  n |= m << i;
  
  return n;
}


int main() {
  uint32_t m = 37, n = 512, i = 2, j = 7;

  assert(insert(m, n, i, j) == 660);
  
  return 0;
}

