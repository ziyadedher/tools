#include <stdio.h>
#include "_parser.h"

void echo(int argc, char** argv) {
  for (; argc; --argc, ++argv) printf(argc - 1 ? "%s " : "%s\n", *argv);
}
