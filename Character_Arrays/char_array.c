#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */

typedef struct {
  int index;
  int empty_state;
} line_ouput;

typedef struct {
  char reversed[MAXLINE];
} reversed_array;

line_ouput get_line(char line[], int maxline, int prt_lim);
void copy(char to[], char from[]);
int fullEmpty(char arr[], int size);
reversed_array reverse(char arr[]);

/* print the longest input line */
int main() {

  line_ouput len;        /* current line length */
  int max;               /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  max = 0;

  while ((len = get_line(line, MAXLINE, 100)).index > 0) {
    if (len.index > max) {
      max = len.index;
      if (len.empty_state == 0) {
        copy(longest, line);
      }
    }
  }

  if (max > 0) { /* there was a line */
    printf("Longest: %s", longest);
  }

  reversed_array test_reverse = reverse(longest);
  for (int c = 0; c < strlen(longest); ++c) {
    printf("Reversed longest: %c\n", test_reverse.reversed[c]);
  }
  return 0;
}

/* getline: read a line into s, return length */
line_ouput get_line(char s[], int lim, int prt_lim) {

  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  int array_size = strlen(s);
  printf("Get line array size: %d\n", array_size);
  line_ouput result;
  result.empty_state = fullEmpty(s, array_size);

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  result.index = i;

  if (i <= prt_lim) {
    for (int j = 0; j < array_size; ++j) {
      if (s[j] == '\n') {
        printf("\\n\n");
      } else if (s[j] == '\t') {
        printf("\\t\n");
      } else if (s[j] == '\0') {
        printf("\\0\n");
      } else {
        printf("Non control chars: %c\n", s[j]);
      }
    }
  }

  return result;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {

  int i;
  i = 0;

  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}

int fullEmpty(char arr[], int size) {
  int counter;

  counter = 0;

  for (int i = 0; i < size; ++i) {
    printf("Current member of the array: %c\n", arr[i]);
    if (arr[i] == ' ') {
      ++counter;
    }
  }
  printf("Counter vs size: %d - %d\n", counter, size);

  if (counter == size) {
    return 1;
  } else {
    return 0;
  }
  return 0;
}

reversed_array reverse(char arr[]) {
  int size_arr = strlen(arr);
  int c;
  reversed_array reverse_arr;

  c = size_arr - 1;

  for (int i = 0; i < size_arr ; ++i) {
    reverse_arr.reversed[i] = arr[c];
    --c;
  }

  return reverse_arr;
}
