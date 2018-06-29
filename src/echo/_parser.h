#include <argp.h>


static char doc[] = "echo -- an echo duplicate";
static char args_doc[] = "text";

static struct argp_option options[] = {

};

struct arguments {
  char* args[1];
};

static error_t parse_opt(int key, char* arg, struct argp_state* state) {
  struct arguments* arguments = state->input;

  switch (key) {
    case ARGP_KEY_ARG:
      arguments->args[state->arg_num] = arg;
      break;

    case ARGP_KEY_END:
      if (state->arg_num < 0) argp_usage(state);
      break;

    default:
      return ARGP_ERR_UNKNOWN;
  }

  return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc};

static struct arguments parse(int argc, char** argv) {
  struct arguments arguments;
  argp_parse(&argp, argc, argv, 0, 0, &arguments);
  return arguments;
}
