#include <stdio.h>

int main() {
  int c;
  int letters[62];
  int counts[62];

  for (int i = 0; i < 62; ++i) {
    counts[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      continue;
    } else {
      if (c >= 97) {
        printf("C97: %d\n", c);
        letters[c - 'a'] = c;
        ++counts[c - 'a'];
        printf("Letter: %c - code: %d - count: %d\n", letters[c - 'a'],
               letters[c - 'a'], counts[c - 'a']);
      } else if (c >= 65) {
        printf("C65: %d\n", c);
        letters[c - 'A' + 26] = c;
        ++counts[c - 'A' + 26];
        printf("Letter: %c - code: %d - count: %d\n", letters[c - 'A' + 26],
               letters[c - 'A' + 26], counts[c - 'A' + 26]);
      } else {
        printf("C digit: %d\n", c);
        letters[c - '0' + 52] = c;
        ++counts[c - '0' + 52];
        printf("Digit: %c - code: %d - count: %d\n", letters[c - '0' + 52],
               letters[c - '0' + 52], counts[c - '0' + 52]);
      }
    }
  }
  int len_char = sizeof(counts) / sizeof(counts[0]);
  printf("%d\n", len_char);
  printf("Size of int: %lu\n", sizeof(int));

  for (int e = 0; e < len_char; ++e) {
    printf("Counts: %d\n", counts[e]);
  }

  for (int j = 0; j < len_char; ++j) {
    if (counts[j] > 0) {
      printf("%d - %c: %d ", letters[j], letters[j], counts[j]);
      for (int d = 0; d < counts[j]; ++d) {
        printf("*");
        continue;
      }
      printf("\n");
    }
  }
}
