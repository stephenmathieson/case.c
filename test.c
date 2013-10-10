
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "src/case.h"

int main(int argc, char **argv) {
  char hello[] = "hello";

  assert(0 == strcmp("HELLO", case_upper(hello)));
  assert(0 == strcmp("hello", case_lower(hello)));

  char unicode[] = "åaçcƒf";
  assert(0 == strcmp("åAçCƒF", case_upper(unicode)));
  assert(0 == strcmp("åaçcƒf", case_lower(unicode)));

  return 0;
}
