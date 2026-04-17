#include <stdatomic.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
void reverse_line(char s[], char reversed_line[]);

int main() {
  int len = 0;
  // int max = 0;
  char line[MAXLINE];
  char reversed_line[MAXLINE];
  // char longest[MAXLINE];

  while ((len = get_line(line, MAXLINE)) != EOF) {
    // clear out reversed_line...
    memset(reversed_line, '\0', sizeof(reversed_line));
    // then draw it
    reverse_line(line, reversed_line);
    printf("%s", line);
    printf("%s\n", reversed_line);
    printf("\n");
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

void reverse_line(char s[], char reversed_line[]) {
  int i, c, d;
  d = 0;

  for (i = 0; s[i] != '\0'; ++i)
    ;

  c = i - 2;

  while (c >= 0) {
    reversed_line[d] = s[c];
    --c;
    ++d;
  }
}
