#include <stdio.h>
int main() {

  int c;
  int counter;

  while ((c = getchar()) != EOF)

    if (c == ' ') {
      ++counter;
      continue;
    } else if (counter > 0) {
      putchar(' ');
      putchar(c);
      counter = 0;
    } else {
      putchar(c);
    }

  return 0;
}
