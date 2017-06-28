/**
 * Write a function setbits(x, p, n, y) that returns x with the n bits that
 * begin at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged.
 */

#include <stdio.h>

#define INT_BIT __INT_WIDTH__

unsigned setbits(unsigned, int, int, unsigned);

void print_bits(unsigned);
unsigned power(int, int);

int main() {
  print_bits(0x12345678);
  print_bits(0xf0f0f0f0);
  print_bits(setbits(0x12345678, 9, 6, 0xf0f0f0f0));

  printf("\n");

  print_bits(0xd3adb33f);
  print_bits(0xd15ea5ed);
  print_bits(setbits(0xd3adb33f, 10, 7, 0xd15ea5ed));
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  return (x & ((~0 << n + p) | ~(~0 << p))) | ((y & ~(~0 << n)) << p);
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
