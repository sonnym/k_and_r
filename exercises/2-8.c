/**
 * Write a function rightrot(x, n) that returns the value of the integer x
 * rotated to the right by n positions.
 */

#include <stdio.h>

#define INT_BIT __INT_WIDTH__

unsigned rightrot(unsigned, int);

void print_bits(unsigned);
unsigned power(int, int);

int main() {
  print_bits(0x12345678);
  print_bits(rightrot(0x12345678, 4));

  printf("\n");

  print_bits(0xd3adb33f);
  print_bits(rightrot(0xd3adb33f, 10));
}

unsigned rightrot(unsigned x, int n) {
  return (x << (INT_BIT - n)) | (x >> n);
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
