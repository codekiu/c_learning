#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define IN_WORD 1
#define OUT_WORD 0

struct longest_word {
  int lenght;
  char word[64];
};

int sum_values(char s1[]);
int sum_odd_idx_values(char s1[]);
struct longest_word calculate_longest_word(char s1[]);

int main() {

  char numbers[20] = {1, 2, 3, 5, 7};
  char my_string[100] = "this is my string and wordsfakfasa is the longest.";

  int sum_values_total = sum_values(numbers);
  int sum_odd_idx_values_total = sum_odd_idx_values(numbers);
  struct longest_word longest_word_result = calculate_longest_word(my_string);

  printf("Sum values total = %d\n", sum_values_total);
  printf("Sum odd idx values total = %d\n", sum_odd_idx_values_total);
  printf("The longest word is %s and its length is %d\n", longest_word_result.word, longest_word_result.lenght);
}

int sum_values(char values[]) {
  int total = 0;
  int idx = 0;

  while (values[idx] != '\0')
    total += values[idx++];

  return total;
}

int sum_odd_idx_values(char values[]) {
  int total = 0;
  int idx = 0;

  while (values[idx] != '\0') {
    if (idx % 2 != 0)
      total += values[idx];
    ++idx;
  }

  return total;
}


struct longest_word calculate_longest_word(char string[]) {
  int length = 0;
  int idx = 0;
  int status = 0;

  struct longest_word result = {
    .lenght = 0,
  };

  while (string[idx] != '\0') {
    status = string[idx] != ' ' ? IN_WORD : OUT_WORD;

    if (status == IN_WORD) {
      ++length;
    } else {
      if (length > result.lenght) {
        result.lenght = length;
        int a = 0;
        int pos = idx - length;
        while(string[pos] != ' ') {
          result.word[a++] = string[pos++];
        }
        result.word[a] = '\0';
      }
      length = 0;
    }
    ++idx;
  }

  return result;
}
