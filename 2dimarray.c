#include<stdio.h>


int a[3][2] = {1, 3, 2, 3, 5, 6};

void p(int c[]) {
  printf("in p : %d\n", c[0]);
}
int main() {
  printf("%d\n", a[2][0]);
  p(a[1]);
  return 0;
}
