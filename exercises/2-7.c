/**
 * Write a function invert(x, p, n) that returns x with the n bits that begin at
 * position p inverted (i.e. 1 changed to 0 and vice versa), leaving the others
 * unchanged.
 */

#include <stdio.h>

#define INT_BIT __INT_WIDTH__

unsigned invert(unsigned, int, int);

void print_bits(unsigned);
unsigned power(int, int);

int main() {
  print_bits(0x12345678);
  print_bits(invert(0x12345678, 9, 6));

  printf("\n");

  print_bits(0xd3adb33f);
  print_bits(invert(0xd3adb33f, 10, 7));
}

unsigned invert(unsigned x, int p, int n) {
  int mask = ~(~0 << n) << p;
  return (x & ~mask) | (~x & mask);
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
