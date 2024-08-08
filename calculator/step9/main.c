#include <stdio.h>
#include <stdbool.h>

char buf[256];
int i = 0;
char sign;

bool is_integer(char c);
int read_buf(char buf[]);
int my_calculator(int ans);

int main(void) {
  printf("please input integer >> ");
  scanf("%255s", buf);
  int ans = 0;
  ans = my_calculator(ans);
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
      sign = buf[i];
      i++;
      return result;
    }
    result = result * 10 + (buf[i] - '0');
  }
  return result;
}

int my_calculator(int ans)
{
  int result = read_buf(buf);
  ans += result;
  while (buf[i] != '\0')
  {
    if (sign == '+')
    {
      result = read_buf(buf);
      ans += result;
    }
    else if (sign == '-')
    {
      result = read_buf(buf);
      ans -= result;
    }
    else
    {
      break;
    }
  }
  return ans;
}