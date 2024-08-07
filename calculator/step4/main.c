#include <stdio.h>
#include <stdbool.h>

char buf[256];
int i = 0;

bool is_integer(char c);
int read_buf(char buf[], int i);

int main(void) {
  printf("please input integer >> ");
  char buf[256];
  scanf("%255s", buf);
  int result = read_buf(buf, i);
  printf("%d\n", result);
}

bool is_integer(char c) {
  if ('0' <= c && c <= '9') {
    return true;
  } else {
    return false;
  }
}

int read_buf(char buf[], int i) {
  int result = 0;
  for (i = 0; buf[i] != '\0'; (i)++) {
    if (!(is_integer(buf[i]))) {
      return result;
    }
    result = result * 10 + (buf[i] - '0');
  }
  return result;
}