#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline, int prt_lim);
void copy(char to[], char from[]);
void delLast(char arr[], int *n);
int fullEmpty(char arr[]);

/* print the longest input line */
int main() {

  int len;               /* current line length */
  int max;               /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  max = 0;

  while ((len = get_line(line, MAXLINE, 100)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) { /* there was a line */
    printf("Longest: %s", longest);
  }
  return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim, int prt_lim) {

  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  int array_size = strlen(s);
  printf("Get line array size: %d\n", array_size);
  printf("Is this empty: %d\n", fullEmpty(s));

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  if (i <= prt_lim) {
    printf("Length of the line: %d\n", i);
    for (int j = 0; j < prt_lim; ++j) {
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

  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {

  int i;
  i = 0;

  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}

void delLast(char arr[], int *n) {
  int arr_size = *n;
  printf("Array size: %d\n", arr_size);

  for (int i = arr_size - 3; i > 0; --i) {
    printf("Current character: %d - %c\n", i, arr[i]);
    if (arr[i] == ' ' || arr[i] == '\t') {
      printf("Remove: %c\n", arr[i]);
      (*n)--;
      printf("Array size after decrement: %d\n", arr_size);
    } else {
      printf("Went straight to the else condition\n");
      break;
    }
  }
}

int fullEmpty(char arr[]) {
  int counter;
  int size;

  size = strlen(arr);
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

