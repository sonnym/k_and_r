/**
 * Write a program to print all input lines that are longer than 80 characters.
 */

#include <stdio.h>
#define MAXLINE 1000
#define LENGTH 80

int get_line(char line[], int lim);

main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > LENGTH) {
      printf("%d: %s\n", len, line);
    }

    line[0] = '\0';
  }
}

int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i < lim - 1) {
      s[i] = c;
    }
  }

  if (c  == '\n') {
    s[i] = c;
    i++;
  }

  s[i] = '\0';

  return i;
}
