#include "cs1010.h"
#include <stdbool.h>

bool is_open(char c) {
  return c == '(' || c == '{' || c == '[' || c == '<';
}

bool is_matching_close(char c, char d) {
  return (c == '(' && d == ')') ||
    (c == '{' && d == '}') ||
    (c == '<' && d == '>') ||
    (c == '[' && d == ']');
}

long is_valid(char *string, long begin) {
  if (string[begin] == '\0') {
    return begin;
  }
  if (!is_open(string[begin])) {
    return begin;
  }

  long end = is_valid(string, begin+1);
  if (is_matching_close(string[begin], string[end])) {
    return is_valid(string, end + 1);
  }
  return begin;
}

int main()
{
  char *str = cs1010_read_word();
  if (str == NULL) {
    cs1010_println_string("memory allocation error");
    return 1;
  }
  long end = is_valid(str, 0);
  if (str[end] == '\0') {
    cs1010_println_string("yes");
  } else { 
    cs1010_println_string("no");
  }
  free(str);
}
