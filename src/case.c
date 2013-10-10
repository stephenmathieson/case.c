
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

#define modifier 'a' - 'A'

char *case_upper(char *str) {
  for (int i = 0, len = strlen(str); i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] -= modifier;
    }
  }
  return str;
}

char *case_lower(char *str) {
  for (int i = 0, len = strlen(str); i < len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += modifier;
    }
  }
  return str;
}
