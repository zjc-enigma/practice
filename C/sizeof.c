#include <stdio.h>
#include <stdlib.h>

void sizeofParam(int *a, int *b){
    printf("sizeof a[10] in param : %lu\n", sizeof(a));
    printf("sizeof b[10] in param : %lu\n", sizeof(b));


}



int main(int argc, char *argv[]) {
  int a[10] = {3};
  int *b = (int*)malloc(sizeof(int)*10);
  void *c;
  char d;

  printf("%ul\n", a[5]);

  printf("size of a[10] : %lu\n", sizeof(a));
  printf("size of malloc b : %lu\n", sizeof(b));
//  printf("%lu\n", sizeof(*a));
  printf("sizeof char* : %lu\n", sizeof(char*));
  printf("size of int : %lu\n", sizeof(int));
  printf("size of double : %lu\n", sizeof(double));
  printf("sizeof long : %lu\n", sizeof(long));
  printf("sizeof float : %lu\n", sizeof(float));
  printf("sizeof void pointer c in 64bit: %lu\n", sizeof(c));
  printf("sizeof char d : %lu\n", sizeof(d));
  sizeofParam(a, b);
  return 0;
}
