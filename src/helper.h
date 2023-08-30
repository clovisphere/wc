#ifndef WC_HELPER
#define WC_HELPER

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define PRETTY_PRINT(count, filename)                                          \
  printf(" 📈%7d %10s 📃\n", count, filename)

typedef struct wc {
  int bytes;
  int word;
  int line;
} wc;

enum option { byte_count, line_count, word_count };

void help(char *exec);

void report(char *filename, wc rs, int option);

void generate_count(char *filename, wc *rs);

#endif
