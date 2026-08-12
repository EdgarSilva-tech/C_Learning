#include <stdio.h>

int main() {
  int counter = 0;
  int c;

  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\t' || c == '\n')
      ++counter;

  printf("%d\n", counter);
  return 0;
}
