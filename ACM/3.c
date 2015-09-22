#include <stdio.h>

int isPrime(int x) {
     int i;

     for(i=2; i*i<=x; i++)
          if(x % i == 0) return 0;

     return 1;
}

int main() {

     int m;
     scanf("%d", &m);

     int i;
     for(i=m-2; i>=3; i--) {
          if(isPrime(i) && isPrime(i+2)) {
               printf("two prime num is : %d\t%d\n", i+2, i);
               break;
          }
     }
     return 0;
}
