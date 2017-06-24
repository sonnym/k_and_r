/**
 * Write a function reverse(s) that reverses the character string s.  Use it to
 * write a program that reverses its input a line at a time.
 */

#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char s[]);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    reverse(line);
    printf("%s", line);
  }

  printf("\n");

  return 0;
}

int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i < lim - 1) {
      s[i] = c;
    }
  }

  if (c == '\n') {
    s[i] = c;
    i++;
  }

  if (i >= lim) {
    s[lim - 1] = '\0';
  } else {
    s[i] = '\0';
  }

  return i;
}

void reverse(char s[]) {
  int i, j;
  char tmp;

  i = 0;

  while (s[i] != '\0') {
    ++i;
  }

  for (j = 0; j < i / 2; ++j) {
    tmp = s[j];
    s[j] = s[i - j - 1];
    s[i - j - 1] = tmp;
  }
}
