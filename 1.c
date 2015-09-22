#include <stdio.h>

int main() {
  char * aa = "patrickaa";
  printf("%d\n", (int)*aa);
  printf("%c\n", (int)*aa);
  printf("%f\n", (double)*aa);
  printf("%f\n", (float)*aa);
  printf("%lu\n", sizeof(aa));
  printf("%d\n", -5%2);
  return 0;
}
