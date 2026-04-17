#include <stdatomic.h>
#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
int remove_trailing(char s[]);

int main() {
  int len = 0;
  // int max = 0;
  char line[MAXLINE];
  // char longest[MAXLINE];

  int max = 2;

  while ((len = get_line(line, MAXLINE)) != EOF) {
    len = remove_trailing(line);

    if (len > 0) {
      printf("%s", line);
    }
  }

  return 0;
}

/* Returns line length */
int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i++] = '\n';
  }

  s[i] = '\0';

  if (c == EOF && i == 0)
    return EOF;

  return i;
}

int remove_trailing(char s[]) {
  int i;

  for (i = 0; s[i] != '\0'; ++i);

  i--;

  if (s[i] == '\n')
    --i;

  while (i >= 0 && (i[s] == ' ' || s[i] == '\t'))
    i--;

  if (i < 0) {
    s[0] = '\0';
    return 0;
  }

  s[++i] = '\n';
  s[++i] = '\0';

  return i;
}
