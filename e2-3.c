#include <ctype.h>
#include <stdio.h>

int htoi(const char hex[]);

int main() {
  const char hex[] = "0x02";
  int converted_hex = htoi(hex);
  printf("The int is = %d\n", converted_hex);
  return 0;
}

int htoi(const char hex[]) {
  if (hex[0] != '0' || tolower(hex[1]) != 'x')
    return -1;

  int result = 0;
  int i = 2;

  while (hex[i] != '\0') {
    char c = tolower(hex[i]);
    int digit_value;

    if (c >= '0' && c <= '9')
      digit_value = c - '0';
    else if (c >= 'a' && c <= 'f')
      digit_value = c - 'a' + 10;
    else
      return -1;

    result = result * 16 + digit_value;
    i++;
  }

  return result;
}
