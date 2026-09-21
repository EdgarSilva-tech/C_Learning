#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c;
  int state = OUT;
  int last_char = '\n';

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ') {
      if (last_char == '\n') {
        state = IN;
      } else {
        state = OUT;
        last_char = '\n';
        putchar('\n');
      }
    } else {
      putchar(c);
      last_char = c;
      state = OUT;
      continue;
    }
  }
  return 0;
}
