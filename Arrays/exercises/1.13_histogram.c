#include <stdio.h>

int main() {
  int c;
  int char_counter = 0;
  int word_counter = 0;
  int last_char = ' ';

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (last_char != ' ') {
        ++word_counter;
        last_char = c;
        putchar(':');
      } else {
        continue;
      }
    } else {
      ++char_counter;
      last_char = c;
      putchar(c);
      continue;
    }
    printf(" ");
    for (int i = 0; i < char_counter; ++i) {
      printf("*");
    }
    printf("\n");
    char_counter = 0;
  }
  printf("%d\n", word_counter);
  return 0;
}
