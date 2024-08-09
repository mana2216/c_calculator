#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char buf[256];
int i = 0;

int integer(void);
int add_sub(void);
int mul_div(void);
int parentheses_expression(void);

int main(void) {
  printf("please input calculation formula >> ");
  scanf("%255s", buf);
  int ans = add_sub();
  printf("%d\n", ans);
}

int integer(void) {
  int num = 0;
  int sign = 1;
  if (buf[i] == '-') {
    sign = -1;
    i++;
  } else if (buf[i] == '+') {
    i++;
  }
  for (; '0' <= buf[i] && buf[i] <= '9'; i++) {
    num = num * 10 + (buf[i] - '0');
  }
  return num * sign;
}

int add_sub(void) {
  int result = mul_div();
  while (buf[i] == '+' || buf[i] == '-') {
    if (buf[i] == '+') {
      i++;
      result += mul_div();
    } else if (buf[i] == '-') {
      i++;
      result -= mul_div();
    }
  }
  return result;
}

int mul_div(void) {
  int result = parentheses_expression();
  while (buf[i] == '*' || buf[i] == '/') {
    if (buf[i] == '*') {
      i++;
      result *= parentheses_expression();
    } else if (buf[i] == '/') {
      i++;
      result /= parentheses_expression();
    }
  }
  return result;
}

int parentheses_expression(void) {
  int result = 0;
  if (buf[i] == '(') {
    i++;
    result = add_sub();
    i++;
  } else {
    result = integer();
  }
  return result;
}