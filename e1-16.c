#include <stdio.h>

#define MAXLINE 10

int get_line(char s[], int lim);
void copy(char to[], char from[]);

int main() {
  int len = 0;
  int max = 0;
  char line[MAXLINE];
  char longest[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("%s", longest);
  }

  return 0;
}

/* Returns line length */
int get_line(char s[], int lim) {
  int c, i, d;
  d = 0;

  for (i = 0;(c = getchar()) != EOF && c != '\n'; ++i)
    if (i < lim - 1) {
      s[i] = c;
      ++d;
    }


  if (c == '\n' && i < (lim - 1)) {
    s[d] = c;
    ++d;
  }

  s[d] = '\0';

  return i;
}

/* Copy line */
void copy(char to[], char from[]) {
  int i = 0;

  while ((to[i] = from[i]) != '\0')
    ++i;
}
