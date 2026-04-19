#include <ctype.h>
#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
  char s1[] = "Hello this is my word";
  char s2[] = "Adios";
  squeeze(s1, s2);

  printf("Remaining = %s", s1);
  return 0;
}

void squeeze(char s1[], char s2[]) {
  int x, y, i, j;
  x = 0,y = 0;
  int found = 0;


  while(s1[x] != '\0') {
    printf("Proccesing x = %c\n", s1[x]);
    while(s2[y] != '\0') {
    printf("Proccesing y = %c\n", s2[y]);
      if (s1[x] == s2[y]) {
        for (i = x; s1[i] != '\0'; i++) {
          s1[i] = s1[i+1];
        }
      }
      ++y;
    }
    y = 0;
    printf("\n");
    ++x;
  }
}
