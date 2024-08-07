#include <stdio.h>
#include <stdbool.h>

char buf[256];
int i = 0;
char plus_sign;

bool is_integer(char c);
int read_buf(char buf[]);

int main(void) {
  printf("please input integer >> ");
  char buf[256];
  scanf("%255s", buf);
  int result1 = read_buf(buf);
  int result2 = read_buf(buf);
  int ans = result1 + result2;
  printf("%d\n", ans);
}

bool is_integer(char c) {
  if ('0' <= c && c <= '9') {
    return true;
  } else {
    return false;
  }
}

int read_buf(char buf[]) {
  int result = 0;
  for (; buf[i] != '\0'; i++) {
    if (!(is_integer(buf[i]))) {
      plus_sign = buf[i];
      i++;
      return result;
    }
    result = result * 10 + (buf[i] - '0');
  }
  return result;
}