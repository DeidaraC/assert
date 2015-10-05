#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

void _Assert(char *msg) {
  fputs(msg, stderr);
  fputs("-- assertion failed\n", stderr);
  abort();
}
