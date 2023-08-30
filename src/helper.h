#ifndef HELPER_H
#define HELPER_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRETTY_PRINT(count, filename)                                          \
  printf(" 📈%7d %10s 📃\n", count, filename)

typedef struct wc {
  int bytes;
  int word;
  int line;
} wc;

enum option { all, byte_count, line_count, word_count };

void help(char *exec);

void report(char *filename, wc rs, int option);

void generate_count(char *filename, wc *rs);

#endif
