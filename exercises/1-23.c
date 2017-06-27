/**
 * Write a program to remove all comments from a C program.  Don't forget to
 * handle quoted strings and character constants properly.  C comments don't
 * nest.
 */

#include <stdio.h>

#define MAXLINE 1000

int get_line(void);
void strip(void);

char line[MAXLINE];
char stripped[MAXLINE];

int open_comment;

int main() {
  open_comment = 0;

  while (get_line() > 0) {
    strip();
    printf("%s", stripped);
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

void strip() {
  int i, offset, skip, line_offset, open_char, open_string;

  extern char line[];
  extern char stripped[];

  offset = skip = open_char = open_string = 0;

  for (i = 0; i < MAXLINE && line[i] != '\0'; ++i) {
    if (open_char == 0 && open_string == 0) {
      if (line[i] == '/' && line[i + 1] == '*') {
        open_comment = 1;
      }

      if (line[i] == '/' && line[i - 1] == '*') {
        ++offset;

        skip = 1;
        open_comment = 0;
      }
    }

    if (skip == 0) {
      if (open_comment == 0) {
        if (line[i] == '\'') {
          if (open_char == 0) {
            open_char = 1;
          } else {
            open_char = 0;
          }
        }

        if (line[i] == '"') {
          if (open_string == 0) {
            open_string = 1;
          } else {
            open_string = 0;
          }
        }

        stripped[i - offset] = line[i];
      } else {
        ++offset;
      }
    } else {
      skip = 0;
    }
  }

  if (i >= MAXLINE) {
    stripped[MAXLINE - 1] = '\0';
  } else {
    stripped[i - offset] = '\0';
  }
}
