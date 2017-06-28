/**
 * Write an alternate version of squeeze(s1, s2) that deletes each character in
 * s1 that matches any character in the string s2.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void squeeze(char[], char[]);

char line[MAXLINE];

int main() {
  extern char line[];

  squeeze("foobar", "o");
  printf("%s\n", line);

  squeeze("bizbaz", "iaz");
  printf("%s\n", line);
}

void squeeze(char s1[], char s2[]) {
  int len, i, j, k;
  extern char line[];

  len = strlen(s2);

  for (i = 0, j = 0; s1[i] != '\0'; i++) {
    for (k = 0; k < len; k++) {
      if (s1[i] == s2[k]) {
        k = len + 1;
      }
    }

    if (k == len) {
      line[j++] = s1[i];
    }
  }

  line[j] = '\0';
}
