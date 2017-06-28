/**
 * In a two's complement number system, x &= (x - 1) deletes the rightmost 1-bit
 * in x.  Explain why.  Use this observation to write a faster version of
 * bitcount.
 */

#include <stdio.h>

#define INT_BIT __INT_WIDTH__

unsigned bitcount(unsigned);

void print_bits(unsigned);
unsigned power(int, int);

int main() {
  print_bits(0x12345678);
  printf("%d\n", bitcount(0x12345678));

  printf("\n");

  print_bits(0xd3adb33f);
  printf("%d\n", bitcount(0xd3adb33f));
}

unsigned bitcount(unsigned x) {
  int b = 0;

  while (x != 0) {
    x &= (x - 1);
    b++;
  }

  return b;
}

void print_bits(unsigned x) {
  int i;
  long p;
  char output[INT_BIT + 1];

  for (i = 0; i < INT_BIT; i++) {
    if ((p = power(2, INT_BIT - i - 1)) <= x) {
      x = x - p;

      output[i] = '1';
    } else {
      output[i] = '0';
    }
  }

  output[i] = '\0';

  printf("%s\n", output);
}

unsigned power(int base, int power) {
  int i;
  unsigned val = 1;

  for (i = 0; i < power; i++) {
    val *= base;
  }

  return val;
}
