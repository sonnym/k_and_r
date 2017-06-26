/**
 * Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input.  Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>

#define MAXLINE 1000
#define WIDTH 40

char line[MAXLINE];
char folded[WIDTH + 1];

int get_line(void);
int fold(void);

int main() {
  int len;
  extern char line[];

  while ((len = get_line()) > 0) {
    if (len > WIDTH) {
      while (fold() > WIDTH) {
        printf("%s", folded);
      }

      printf("%s", folded);
    }

    printf("%s", line);
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

int fold() {
  int i, last;

  extern char line[];
  extern char folded[];

  for (i = 0, last = 0; i < WIDTH && i < MAXLINE && line[i] != '\0'; ++i) {
    if (line[i] == '\t' || line[i] == ' ') {
      last = i;
    }

    folded[i] = line[i];
  }

  if (last == 0) {
    last = WIDTH;
  }

  folded[last] = '\n';
  folded[last + 1] = '\0';

  for (i = 0; i < MAXLINE && line[i] != '\0'; ++i) {
    line[i] = line[last + i + 1];
  }

  line[i] = '\0';

  return i - 1;
}
