
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "src/case.h"

#define EQUALS(a, b) ({                               \
  if (0 != strcmp(a, b))  {                           \
    fprintf(stderr                                    \
      , "Assertion error: \"%s\" == \"%s\" (%s:%d)\n" \
      , a                                             \
      , b                                             \
      , __FILE__                                      \
      , __LINE__);                                    \
    exit(1);                                          \
  }                                                   \
})

#define TEST(name) \
  static void test_##name(void)

#define SUITE(title) \
  printf("\n  \e[36m%s\e[0m\n", title)

#define RUN_TEST(test) \
  test_##test(); \
  puts("    \e[92m✓ \e[90m" #test "\e[0m");


TEST(lowercase_string) {
  char hello_world[] = "HELLO WORLD";
  char foo[] = "fOo";

  EQUALS("hello world", case_lower(hello_world));
  EQUALS("foo", case_lower(foo));
}

TEST(lowercase_empty_string) {
  char str[] = "";
  EQUALS("", case_lower(str));
}

TEST(lowercase_unicode_string) {
  char unicode[] = "åAçCƒF";
  EQUALS("åaçcƒf", case_lower(unicode));
}

TEST(uppercase_string) {
  char hello_world[] = "hello world";
  char foo[] = "fOo";

  EQUALS("HELLO WORLD", case_upper(hello_world));
  EQUALS("FOO", case_upper(foo));
}

TEST(uppercase_empty_string) {
  char str[] = "";
  EQUALS("", case_upper(str));
}

TEST(uppercase_unicode_string) {
  char unicode[] = "åaçcƒf";
  EQUALS("åAçCƒF", case_upper(unicode));
}

TEST(camel_single_char) {
  char str[] = "a";
  EQUALS("a", case_camel(str));
};

TEST(camel_empty_string) {
  char str[] = "";
  EQUALS("", case_camel(str));
}

TEST(camel_hypen_seperators) {
  char str[] = "foo-bar-baz";

  EQUALS("fooBarBaz", case_camel(str));
}

TEST(camel_underscore_seperators) {
  char str[] = "foo_bar_baz";

  EQUALS("fooBarBaz", case_camel(str));
}

TEST(camel_space_seperators) {
  char str[] = "a few spaces";

  EQUALS("aFewSpaces", case_camel(str));
}

TEST(camel_leading_seperator) {
  char moz_something[] = "-moz-something";
  char leading_sep[] = "---leading-sep";

  EQUALS("mozSomething", case_camel(moz_something));
  EQUALS("leadingSep", case_camel(leading_sep));
}

TEST(camel_trailing_seperator) {
  char trailing_sep[] = "trailing-sep---";

  EQUALS("trailingSep", case_camel(trailing_sep));
}

int
main() {
  SUITE("case_lower");
  RUN_TEST(lowercase_string);
  RUN_TEST(lowercase_empty_string);
  RUN_TEST(lowercase_unicode_string);

  SUITE("case_upper");
  RUN_TEST(uppercase_string);
  RUN_TEST(uppercase_empty_string);
  RUN_TEST(uppercase_unicode_string);

  SUITE("case_camel");
  RUN_TEST(camel_single_char);
  RUN_TEST(camel_empty_string);
  RUN_TEST(camel_hypen_seperators);
  RUN_TEST(camel_underscore_seperators);
  RUN_TEST(camel_leading_seperator);
  RUN_TEST(camel_trailing_seperator);
  printf("\n");
  return 0;
}
