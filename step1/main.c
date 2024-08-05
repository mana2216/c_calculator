#include <stdio.h>

int main(void) {
  printf("整数を入力してください >> ");
  char buf[40];
  int value;
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &value);
  printf("%d\n", value);
  return 0;
}