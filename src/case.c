
//
// case.c
//
// Copyright (c) 2013 Stephen Mathieson
// MIT licensed
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "case.h"

#define modifier     'a' - 'A'
#define is_lower(c)  c >= 'a' && c <= 'z'
#define is_upper(c)  c >= 'A' && c <= 'Z'

char *case_upper(char *str) {
  for (int i = 0, len = strlen(str); i < len; i++) {
    if (is_lower(str[i])) {
      str[i] -= modifier;
    }
  }
  return str;
}

char *case_lower(char *str) {
  for (int i = 0, len = strlen(str); i < len; i++) {
    if (is_upper(str[i])) {
      str[i] += modifier;
    }
  }
  return str;
}
