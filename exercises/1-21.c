/**
 * Write a program entab that replaces string of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as
 * for detab. When either a tab or a single blank would suffice to reach a tab
 * stop, which sould be given preference?
 */

#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4

int get_line(char line[], int lim);
void detab(char original[], char mutated[], int tabstop);

main() {
  int len;
  char line[MAXLINE];
  char entabbed[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    detab(line, entabbed, TABSTOP);
    printf("%s", entabbed);
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

void detab(char original[], char mutated[], int tabstop) {
  int i, j, spaces, tabs;

  spaces = 0;
  tabs = 0;

  for (i = 0; original[i] != '\0'; ++i) {
    if (original[i] == ' ') {
      ++spaces;
    } else {
      if (spaces >= tabstop) {
        for (j = spaces / tabstop; j > 0; --j) {
          mutated[i - (j * tabstop) - (spaces % tabstop) - tabs * (tabstop - 1)] = '\t';
          ++tabs;
        }

        for (j = spaces % tabstop; j > 0; --j) {
          mutated[i - j - tabs * (tabstop - 1)] = ' ';
        }

        spaces = 0;
      } else if (spaces > 0) {
        for (j = spaces; j > 0; --j) {
          mutated[i - j - tabs * (tabstop - 1)] = ' ';
        }

        spaces = 0;
      }

      mutated[i - tabs * (tabstop - 1)] = original[i];
    }
  }
}
