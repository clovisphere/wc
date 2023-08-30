#include "helper.h"

// print help/usage message
void help(char *exec) {
  puts("\n\t⚡️⚡️ 🫧  Help ⚙️  🔍 ⚡️⚡️\n");
  printf("Name     😺\n\twc - word, line, character, and byte count.\n\n");
  printf("Synopsis 😸\n\t%1$s [<option>] [<file> ...]\n\n"
         "Description\n\tThe wc utility displays the number of lines, words, "
         "and bytes contained in each input file,\n\tor standard input (if no "
         "file is specified) to the standard output.\n\n"
         "The following options are available:\n"
         "\t-c\tThe number of bytes in each input file is written to the "
         "standard output.\n"
         "\t-l\tThe number of lines in each input file is written to the "
         "standard output.\n"
         "\t-w\tThe number of words in each input file is written to the "
         "standard output.\n"
         // TODO: add `-m` option to the help message
         "\t-h\tShows this help and exit.\n"
         "\t-v\tPrints the version and exit.\n",
         exec);
  exit(EXIT_SUCCESS);
} // end `help`

// pretty-prints `wc` results
void report(char *filename, wc stat, int option) {
  switch (option) {
  case byte_count:
    PRETTY_PRINT(stat.bytes, filename);
    break;
  case line_count:
    PRETTY_PRINT(stat.line, filename);
    break;
  case word_count:
    PRETTY_PRINT(stat.word, filename);
    break;
  default:
    printf(" 📊%7d %7d %7d %s 📃\n", stat.line, stat.word, stat.bytes,
           filename);
  }
} // end `report`

// generates or populates `wc` data
void generate_count(char *filename, wc *stat) {
  FILE *file;
  // check if the file exist
  if ((file = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "😾 error: '%s' 🙀 - unable to open file\n", filename);
    exit(EXIT_FAILURE);
  }
  int c, last_was_a_space = 0;
  while ((c = fgetc(file)) != EOF) {
    ++stat->bytes;
    /* **************************** */
    //       💫 LGTM 🚀             //
    /* **************************** */
    if (isspace(c)) {
      // do we have a new line?
      if (c == '\n') {
        ++stat->line;
      }
      // do we have a word?
      if (!last_was_a_space) {
        last_was_a_space = 1;
        ++stat->word;
      }
    } else {
      last_was_a_space = 0;
    }
  }
  fclose(file);
} // end `generate_count`
