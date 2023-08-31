/* ***************************************** */
//            ✨ ✨ CLI ✨ ✨                //
// wc – word, line, character, and byte count //
/* ***************************************** */

#include "helper.h"
#include "version.h"
#include <unistd.h>

// prints the executable version
void version(char *exec) {
  printf("%s(1) - version %s\n", exec, WC_VERSION);
}

// starts program execution
int main(int argc, char **argv) {
  int ch, option;
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
  for (int i = optind; i < argc; i++) {
    wc stat = {0, 0, 0};
    generate_count(argv[i], &stat);
    report(argv[i], stat, option);
  }
  return EXIT_SUCCESS;
}
