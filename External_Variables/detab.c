#include <stdio.h>
#define MAXLINE 1000   /* maximum input line size */
#define TAB_STOP 8
int max;               /* maximum length seen so far */
char line[MAXLINE];    /* current input line */
char longest[MAXLINE]; /* longest line saved here */
int get_line(void);
void copy(void);
void detab();
int c, i;
/* print longest input line; specialized version */
int main() {
  int len;
  extern int max;
  extern char longest[];
  max = 0;
  while ((len = get_line()) > 0)
    if (len > max) {
      printf("Max updated\n");
      max = len;
      copy();
    }
  if (max > 0) /* there was a line */
    printf("%s\n", longest);
  return 0;
}

/* getline: specialized version */
int get_line(void) {
  extern int c, i;
  extern char line[];
  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    if (c == '\t') {
      printf("Before detab: %d\n", c);
      detab();
      printf("Tab char: %c - index: %d - Ascii value: %d\n", line[i], i, line[i]);
    } else {
      line[i] = c;
      printf("Current char: %c - index: %d - Ascii value: %d\n", line[i], i, c);
    }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}
/* copy: specialized version */
void copy(void) {
  int k;
  extern char line[], longest[];
  k = 0;
  while ((longest[k] = line[k]) != '\0')
    ++k;
}

void detab(void) {

  extern int i;
  extern char line[];

  while (1) {
    line[i] = ' ';
    printf("Remainder result: %d - %s\n", i, ((i % TAB_STOP) != 0)?"true":"false");
    printf("Before increment: \\t - %d - %c - Ascii value: %d\n", i, line[i], line[i]);
    if (((i + 1) % TAB_STOP) == 0) {
      break;
    }
    ++i;
    printf("After increment: %d\n", i);
  }
}
