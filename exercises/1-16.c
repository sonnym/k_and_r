/**
 * Revise the main routine of the longest line program so it correctly prints
 * the length of arbitrary long input lines, and as much as possible of the
 * text.
 */

#include <stdio.h>
#define MAXLINE 20

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("%d: %s\n", max, longest);
  }

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

void copy(char to[], char from[]) {
  int i;

  i = 0;

  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
