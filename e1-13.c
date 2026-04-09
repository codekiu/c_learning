#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, i, length;
  int lwords[100];
  int status = 0;

  length = 0;

  for (i = 0; i < 100; i++) {
    lwords[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n') {
      status = OUT;
    } else {
      status = IN;
    }

    if (status == OUT) {
      ++lwords[length];
      length = 0;
    } else {
      ++length;
    }
  }

  for (i = 0; i < 100; i++) {
    int y;
    if (lwords[i] > 0) {
      printf("%d", i);
    }
    for (y = lwords[i]; y > 0; y--) {
      putchar('-');
    }
    if (lwords[i] > 0) {
      putchar('\n');
    }
  }
}
