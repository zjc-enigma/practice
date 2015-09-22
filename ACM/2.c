#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


#define MAX_SIZE 10000

int main() {
     char s[MAX_SIZE];
     char buf[MAX_SIZE];

     fgets(s, MAX_SIZE, stdin);

     printf("read in : %ld\n", strlen(s));

     // all char to upper
     int i;
     int m = 0;
     for(i=0; i<strlen(s); i++) {
          if(isalpha(s[i]))
               buf[m++] = toupper(s[i]);
     }

     printf("alpha num : %ld\n", strlen(buf));

     int begin;
     int end;
     int max_len = 0;
     char max_str[MAX_SIZE];

     for(begin=0; begin < strlen(buf); begin++) {
          for(end=strlen(buf)-1; end>begin; end--) {

               if(max_len > end - begin + 1)
                    break;

               int p = begin;
               int q = end;
               while(p < q) {
                    if(buf[p] != buf[q])
                         break;
                    p++;
                    q--;
               }
               if(p < q)
                    continue;

               max_len = end - begin + 1;
               int r;
               for(r=0; r<max_len; r++) {
                    max_str[r] = buf[begin+r];
               }
               max_str[r] = '\0';
               break;
          }
     }

     printf("max string len : %d\n%s\n", max_len, max_str);
     printf("time use : %.4lf\n", (double)clock() / CLOCKS_PER_SEC);
     printf("clock per time : %d\n", CLOCKS_PER_SEC);
     return 0;

}
