#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

void __assert(const char *func, const char *file, int line, const char *expr) {
  fprintf(stderr,
    "Assertion failed: (%s), function %s, file %s, line %d.\n",
    expr, func, file, line
  );

  abort();
}
