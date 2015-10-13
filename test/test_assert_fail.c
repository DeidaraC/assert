#include <stdio.h>
#include <stdlib.h>

#undef NDEBUG
#include "../assert.h"

static void assert2(void) { assert(1 == 2); }

int main(void) { assert2(); }
