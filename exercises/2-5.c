/**
 * Write the function any(s1, s2), which returns the first location in a string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains no
 * characters from s2.  (The standard library function strpbrk does the same job
 * but returns a pointer to the location.)
 */

#include <stdio.h>

int any(char[], char[]);

int main() {
  printf("%d\n", any("foobar", "bar"));
  printf("%d\n", any("bizbaz", "z"));
  printf("%d\n", any("bizbaz", "foo"));
  printf("%d\n", any("bizbaz", ""));
}

int any(char s1[], char s2[]) {
  int i, j;

  for (i = j = 0; s1[i] != '\0'; i++) {
    while (s2[j] != '\0') {
      if (s1[i] == s2[j++]) {
        return i;
      }
    }

    j = 0;
  }

  return -1;
}
