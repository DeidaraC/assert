#include <stdio.h>
#include <stdlib.h>

#undef NDEBUG
#include "../assert.h"

static void assert1(void) { assert(1 == 1); }

int main(void) {
  assert1();

  return 0;
}
