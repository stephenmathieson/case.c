
//
// case.c
//
// Copyright (c) 2014 Stephen Mathieson
// MIT licensed
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "case.h"

#define CASE_IS_SEP(c)    ((c) == '-' || (c) == '_' || (c) == ' ')

char *
case_upper(char *str) {
  for (char *s = str; *s; s++) {
    *s = toupper(*s);
  }
  return str;
}

char *
case_lower(char *str) {
  for (char *s = str; *s; s++) {
    *s = tolower(*s);
  }
  return str;
}

char *
case_camel(char *str) {
  char *r = str, *w = str;
  // never cap the first char
  while (CASE_IS_SEP(*r)) {
    r++;
  }
  while (*r && !CASE_IS_SEP(*r)) {
    *w++ = *r++;
  }
  while (*r) {
    do {
      r++;
    } while (CASE_IS_SEP(*r));
    if (!*r)
	    break;
    *w++ = toupper(*r);
    r++;
    while (*r && !CASE_IS_SEP(*r)) {
      *w++ = *r++;
    }
  }
  *w = 0;
  return str;
}
