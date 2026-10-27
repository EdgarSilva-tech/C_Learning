#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define TAB_SPACES 8

int max;               /* maximum length seen so far */
char line[MAXLINE];    /* current input line */
char longest[MAXLINE]; /* longest line saved here */
int last_char;
int num_spaces;
int c, i;
int get_line(void);
void copy(void);
void entab(void);
int start_col;

/* print longest input line; specialized version */
int main() {
  int len;
  extern int max;
  extern char longest[];
  max = 0;
  while ((len = get_line()) > 0) {
    if (len > max) {
      max = len;
      copy();
    }
  }
  if (max > 0) { /* there was a line */
    printf("%s", longest);
  }
  return 0;
}

/* getline: specialized version */
int get_line(void) {
  extern int c, i;
  extern char line[];
  extern int num_spaces;
  extern int last_char;
  extern int start_col;
  num_spaces = 0;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    printf("Index: %d and num spaces: %d\n", i, num_spaces);
    if (c == ' ') {
      if (last_char != ' ') {
        start_col = i;
        printf("Starting column: %d\n", start_col);
      }
      line[i] = c;
      ++num_spaces;
      last_char = c;
    } else {
      entab();
      line[i] = c;
      printf("Index after the entab function: %d\n", i);
      num_spaces = 0;
      last_char = c;
    }
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
  int i;
  extern char line[], longest[];
  i = 0;
  while ((longest[i] = line[i]) != '\0') {
    ++i;
  }
}

void entab(void) {
  extern int c, i;
  extern char line[];
  extern int last_char;
  extern int num_spaces;
  unsigned int spaces_to_fill;
  extern int start_col;
  int spaces_removed = 0;

  i = start_col;

  while (num_spaces > 0) {
  
    if (num_spaces >= TAB_SPACES) {
      spaces_to_fill = TAB_SPACES - (start_col % TAB_SPACES);
      spaces_removed = spaces_removed + spaces_to_fill;
      printf("C: %c\n", c);
      printf("Second char: %d\n", line[1]);
      line[i] = '\t';
      num_spaces = num_spaces - spaces_to_fill;
      printf("Spaces to fill: %d\n", spaces_to_fill);
      printf("Number of spaces: %d - %d\n", num_spaces, i);
      start_col = start_col + spaces_to_fill;
      i++;
    } else {
      printf("C: %c\n", c);
      printf("Number of spaces left: %d\n", num_spaces);
      printf("Current index: %d\n", i);

      for (int k = num_spaces; k > 0; --k) {
        line[i] = ' ';
        --num_spaces;
        i++;
        printf("K is: %d\n", k);
      }
      num_spaces = 0;
    }
  }
  printf("After the offset: %d\n", i);
}
