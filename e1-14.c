#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, i, length;
  int lwords[256];
  int status = 0;

  length = 0;

  for (i = 0; i < 256; i++) {
    lwords[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    ++lwords[c];
  }

  for (i = 0; i < 256; i++) {
    int y;
    if (lwords[i] > 0) {
      printf("%c", i);
    }

    for (y = lwords[i]; y > 0; y--) {
     putchar('-');
    }

    if (lwords[i] > 0) {
      putchar('\n');
    }
  }
}
