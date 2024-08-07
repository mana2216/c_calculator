#include <stdio.h>
#include <stdbool.h>

bool is_integer(char c);

int main(void) {
  printf("please input integer >> ");
  char buf[256];
  scanf("%255s", buf);
  int result = 0;
  for (int i = 0; buf[i] != '\0'; i++) {
    if (!(is_integer(buf[i]))) {
      break;
    }
    result *= 10;
    result += (buf[i] - '0');
  }
  printf("%d\n", result);
}

bool is_integer(char c) {
  if ('0' <= c && c <= '9') {
    return true;
  } else {
    return false;
  }
}