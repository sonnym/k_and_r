/**
 * Write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops,
 * say every n columns. Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4

int len;
char line[MAXLINE];
char detabbed[MAXLINE];

int get_line(void);
void detab(void);

int main() {
  while (get_line() > 0) {
    detab();
    printf("%s", detabbed);
  }
}

int get_line() {
  int c, i;
  extern char line[];

  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i < MAXLINE - 1) {
      line[i] = c;
    }
  }

  if (c == '\n') {
    line[i] = c;
    i++;
  }

  if (i >= MAXLINE) {
    line[MAXLINE - 1] = '\0';
  } else {
    line[i] = '\0';
  }

  return i;
}

void detab() {
  int i, j, tabs;

  extern char line[];
  extern char detabbed[];

  tabs = 0;

  for (i = 0; line[i] != '\0' && i + (tabs * (TABSTOP - 1)) < MAXLINE; ++i) {
    if (line[i] == '\t') {
      for (j = 0; j < TABSTOP && i + j + (tabs * (TABSTOP - 1)) < MAXLINE; ++j) {
        detabbed[i + j + (tabs * (TABSTOP - 1))] = ' ';
      }

      tabs++;
    } else {
      detabbed[i + tabs * (TABSTOP - 1)] = line[i];
    }
  }

  if (i + tabs * (TABSTOP - 1) >= MAXLINE) {
    detabbed[MAXLINE - 1] = '\0';
  } else {
    detabbed[i + tabs * (TABSTOP - 1)] = '\0';
  }
}
