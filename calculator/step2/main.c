#include <stdio.h>

int main(void) {
  printf("please input integer >> ");
  char buf[256];
  scanf("%255s", buf);
  for (int i = 0; buf[i] != '\0'; i++) {
    int num = buf[i] - '0';
    printf("%d", num);
  }
  printf("\n");
}