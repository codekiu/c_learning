#include <stdio.h>

#define IN 1
#define OUT 0

int calculate_celsius(int c);
int calculate_fahr(int c, int x);

int main() {
  int fahr, celsius;
  int lower, upper, step;
  lower = 0;
  upper = 300;
  step = 20; /* lower limit of temperature scale */
  /* upper limit */
  /* step size */
  fahr = lower;
  while (fahr <= upper) {
    celsius = calculate_celsius(fahr);
    printf("%d\t%d\n", fahr, celsius);
    fahr = calculate_fahr(fahr, step);
  }
}

int calculate_celsius(int fahr) { return 5 * (fahr - 32) / 9; }

int calculate_fahr(int fahr, int step) { return fahr + step; }
