/**
 * Write a program entab that replaces string of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as
 * for detab. When either a tab or a single blank would suffice to reach a tab
 * stop, which sould be given preference?
 */

#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4

char line[MAXLINE];
char entabbed[MAXLINE];

int get_line(void);
void entab(void);

int main() {
  extern char line[];
  extern char entabbedp[];

  while (get_line() > 0) {
    entab();
    printf("%s", entabbed);
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

void entab() {
  int i, j, spaces, tabs;

  extern char line[];
  extern char entabbed[];

  spaces = 0;
  tabs = 0;

  for (i = 0; line[i] != '\0'; ++i) {
    if (line[i] == ' ') {
      ++spaces;
    } else {
      if (spaces >= TABSTOP) {
        for (j = spaces / TABSTOP; j > 0; --j) {
          entabbed[i - (j * TABSTOP) - (spaces % TABSTOP) - tabs * (TABSTOP - 1)] = '\t';
          ++tabs;
        }

        for (j = spaces % TABSTOP; j > 0; --j) {
          entabbed[i - j - tabs * (TABSTOP - 1)] = ' ';
        }

        spaces = 0;
      } else if (spaces > 0) {
        for (j = spaces; j > 0; --j) {
          entabbed[i - j - tabs * (TABSTOP - 1)] = ' ';
        }

        spaces = 0;
      }

      entabbed[i - tabs * (TABSTOP - 1)] = line[i];
    }
  }

  if (i + tabs * (TABSTOP - 1) >= MAXLINE) {
    entabbed[MAXLINE - 1] = '\0';
  } else {
    entabbed[i - tabs * (TABSTOP - 1)] = '\0';
  }
}
