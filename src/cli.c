/* ***************************************** */
//            ✨ ✨ CLI ✨ ✨                //
// wc – word, line, character, and byte count //
/* ***************************************** */

#include "helper.h"
#include "version.h"
#include <unistd.h>

// prints the executable version
void version(char *exec) { printf("%s(1) - version %s\n", exec, WC_VERSION); }

// starts program execution
int main(int argc, char **argv) {
  int ch, option = -1;
  while ((ch = getopt(argc, argv, "hvclw")) != -1) {
    switch (ch) {
    case 'c':
      option = byte_count;
      break;
    case 'l':
      option = line_count;
      break;
    case 'w':
      option = word_count;
      break;
    case 'h':
      help(argv[0]);
      return EXIT_SUCCESS;
    case 'v':
      version(argv[0]);
      return EXIT_SUCCESS;
    default:
      return EXIT_FAILURE;
    }
  }
  /* **************************************************** */
  // If we did things well, the below code is all we need //
  // to display (wc) results                              //
  /* **************************************************** */

  // hold the total stats when we have more than 1 file.
  wc total = {0, 0, 0};
  // number of file processed so far
  int file_no = 0;

  for (int i = optind; i < argc; i++) {
    wc stat = {0, 0, 0};
    generate_count(argv[i], &stat);
    report(argv[i], stat, option);
    /* ******************************************************************** */
    //  when getting stats for more than one file                           //
    //  we need to calculate the overall wc i.e for lines, word, and bytes  //
    /* ******************************************************************** */
    total.line += stat.line;
    total.word += stat.word;
    total.bytes += stat.bytes;
    // this will help with overall stat when we have more than 1 file:-)
    ++file_no;
  }
  // only display overall stat when we are in
  // 'default' mode and have processed more than 1 file
  if (option == -1 && file_no > 1) {
    printf("%-50s\n", SEPARATOR);
    printf("%4s%7d %7d %7d %-15s%2s\n", " 😽", total.line, total.word,
           total.bytes, "[total]", "🧮");
  }
  return EXIT_SUCCESS;
}
