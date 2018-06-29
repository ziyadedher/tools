#include <stdio.h>
#include "_parser.h"

void echo(int argc, char** argv) {
  // struct arguments arguments = parse(argc, argv);
  for (; argc; --argc, ++argv) printf("%s ", *argv);
  printf("\n");
}
