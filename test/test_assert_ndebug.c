#include <stdio.h>
#include <stdlib.h>

#define NDEBUG
#include "../assert.h"

static void assert1(void) { assert(1 == 1); }

static void assert2(void) { assert(1 == 2); }

int main(void) {
  assert1();
  assert2();
}
