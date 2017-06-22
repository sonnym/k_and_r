/**
 * Write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops,
 * say every n columns. Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4

int get_line(char line[], int lim);
void detab(char original[], char mutated[], int tabstop, int lim);

main() {
  int len;
  char line[MAXLINE];
  char detabbed[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    detab(line, detabbed, TABSTOP, MAXLINE);
    printf("%s", detabbed);
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

void detab(char original[], char mutated[], int tabstop, int lim) {
  int i, j, tabs;

  tabs = 0;

  for (i = 0; original[i] != '\0' && i + tabs * (tabstop - 1) < lim; ++i) {
    if (original[i] == '\t') {
      for (j = 0; j < tabstop && i + (tabs * (tabstop - 1)) + j < lim; j++) {
        mutated[i + (tabs * (tabstop - 1)) + j] = ' ';
      }
      tabs++;
    } else {
      mutated[i + tabs * (tabstop - 1)] = original[j];
    }
  }
}
