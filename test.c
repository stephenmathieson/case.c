
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "src/case.h"

int main(int argc, char **argv) {
  assert(0 == strcmp("", case_upper("")));
  assert(0 == strcmp("", case_lower("")));

  char hello[] = "hello";
  assert(0 == strcmp("HELLO", case_upper(hello)));
  assert(0 == strcmp("hello", case_lower(hello)));

  char unicode[] = "åaçcƒf";
  assert(0 == strcmp("åAçCƒF", case_upper(unicode)));
  assert(0 == strcmp("åaçcƒf", case_lower(unicode)));

  char a[] = " a";
  char data_rate[] = "data_rate";
  char background_color[] = "background-color";
  char spaces[] = "a couple spaces";
  char moz_something[] = "-moz-something";
  char leading_sep[] = "---leading-sep";
  char trailing_sep[] = "trailing-sep---";
  assert(0 == strcmp("", case_camel("")));
  assert(0 == strcmp("a", case_camel(a)));
  assert(0 == strcmp("dataRate", case_camel(data_rate)));
  assert(0 == strcmp("backgroundColor", case_camel(background_color)));
  assert(0 == strcmp("aCoupleSpaces", case_camel(spaces)));
  assert(0 == strcmp("mozSomething", case_camel(moz_something)));
  assert(0 == strcmp("leadingSep", case_camel(leading_sep)));
  assert(0 == strcmp("trailingSep", case_camel(trailing_sep)));

  return 0;
}
