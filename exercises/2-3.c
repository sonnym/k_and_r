/**
 * Write a function htoi(s), which converts a string of hexidecimal digits
 * (including an optional 0x or 0X into its equivalent integer value.  The
 * allowable digits are 0 through 9, a through f, and A through F.
 */

#include <stdio.h>
#include <string.h>

int htoi(char []);
int raise(int, int);

int main() {
  printf("%d\n", htoi("0xff"));
  printf("%d\n", htoi("09"));
  printf("%d\n", htoi("foobar"));
  printf("%d\n", htoi("0XFA"));
}

int htoi(char str[]) {
  int i, val, len, pow;
  char c;

  len = strlen(str);

  for (i = val = 0; (c = str[i]) != '\0'; ++i) {
    if (i == 0 && c == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X')) {
      ++i;
    } else {
      pow = len - i - 1;

      if (c >= '0' && c <= '9') {
        val += raise(c - '0', pow);
      } else if (c >= 'a' && c <= 'f') {
        val += raise(c - 'a' + 10, pow);
      } else if (c >= 'A' && c <= 'F') {
        val += raise(c - 'A' + 10, pow);
      } else {
        return -1;
      }
    }
  }

  return val;
}

int raise(int base, int power) {
  int i;
  int val = 1;

  if (power == 0) {
    return base;
  }

  for (i = 0; i < power; i++) {
    val *= 16;
  }

  return base * val;
}
