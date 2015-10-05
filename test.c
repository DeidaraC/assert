#define NDEBUG
#include "assert.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static int val = 0;

static void field_abort(int sig) {
  if (val == 1) {
    puts("success testing assert.h");
    exit(EXIT_SUCCESS);
  } else {
    puts("failed to testing assert.h");
    exit(EXIT_FAILURE);
  }
}

static void dummy(void) {
  int i = 0;
  assert(i == 0);
  assert(i == 1);
}

#undef NDEBUG
#include "assert.h"

int main(void) {
  assert(signal(SIGABRT, &field_abort) != SIG_ERR);
  dummy();
  assert(val == 0);
  ++val;
  fputs("sample assertion failure message --\n", stderr);
  assert(val == 0);
  puts("failure testing assert.h");

  exit(EXIT_FAILURE);
}
