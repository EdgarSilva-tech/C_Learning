#include <stdio.h>

int main() {
  int c;
  int char_counter = 0;
  int word_counter = 0;
  int last_char = ' ';
  int x_axis[5];
  int n;
  struct histogram_counts {
    int counts[10];
    int unique_values[10];
  };
  int equal_counts = 0;
  struct histogram_counts histogram;

  for (int k = 0; k < 10; ++k) {
    histogram.counts[k] = 0;
    histogram.unique_values[k] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (last_char != ' ') {
        ++word_counter;
        last_char = c;
        putchar('\n');
      } else {
        continue;
      }
    } else {
      ++char_counter;
      last_char = c;
      putchar(c);
      continue;
    }
    x_axis[word_counter - 1] = char_counter;
    char_counter = 0;
  }
  printf(" ");
  n = sizeof(x_axis) / sizeof(x_axis[0]);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (x_axis[i] == histogram.unique_values[j]) {
        printf("Comparing: %d - %d\n", x_axis[i], histogram.unique_values[j]);
        ++equal_counts;
      }
    }
    printf("Equal counts: %d - %d\n", x_axis[i], equal_counts);
    if (equal_counts == 0) {
      histogram.unique_values[i] = x_axis[i];
      printf("Unique values: %d\n", histogram.unique_values[i]);
    }
    equal_counts = 0;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (histogram.unique_values[i] == x_axis[j]) {
        ++histogram.counts[i];
      }
    }
    printf("Value: %d - freqs: %d\n", histogram.unique_values[i],
           histogram.counts[i]);
  }
  printf("\n");

  printf("%d\n", word_counter);
  return 0;
}
