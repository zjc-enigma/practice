#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
     char s[MAX_SIZE];
     scanf("%s", s);



     int len = strlen(s);


     char rep[MAX_SIZE];
     int p = 0;

     int i;
     for(i=0; i<len; i++) {

          printf("%d\t%ld\n", p, strlen(rep));

          if(p > 0 && p >= strlen(rep)) {
               printf("min rep str : %s\n", rep);
               break;
          }

          if(rep[p] == s[i]) {
               p++;
          }
          else {
               p = 0;
               rep[strlen(rep)] = s[i];
               rep[strlen(rep)] = '\0';
          }
     }
     return 0;
}
