#include <string.h>
#include "echo/echo.h"
#include "_parser.h"


static const size_t numTools = 1;
static const char* toolNames[] = {
  "echo"
};

int main(int argc, char** argv) {
  struct arguments arguments = parse(argc, argv);

  size_t tool;
  for (tool = 0; tool < numTools && !strcmp(arguments.args[0], toolNames[tool]) == 0; ++tool);

  switch (tool) {
    case 0:
      echo(argc - 2, argv + 2);
      break;

    default:
      printf("No such tool `%s`\n", arguments.args[0]);
      printf("Available tools:");
      for (size_t i = 0; i < numTools; i++) printf(" %s", toolNames[i]);
      printf("\n");
      return 1;
  }
}
