#include <assert.h>
#include <ctype.h>
#include <stdio.h>

int sum_values(char s1[]);

int main() {

  char numbers[20] = {1, 2, 3, 5, 7};

  int total = sum_values(numbers);

  printf("Total = %d\n", total);
}

int sum_values(char values[]) {
  int total = 0;
  int idx = 0;

  while (values[idx] != '\0')
    total += values[idx++];

  return total;
}
