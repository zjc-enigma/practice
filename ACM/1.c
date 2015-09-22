// 竖式问题
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

int main() {
     char s[MAX_SIZE];
     scanf("%s", s);

     //解析输入的数字集合
     int numSet[MAX_SIZE];
     int i=0;
     memset(numSet, -1, sizeof(numSet));

     while(s[i] != '\0'){
          numSet[i] = s[i] - 48;
          i++;
     }


     int abc, de;
     int p, q, r;
     for(p=0; p<i; p++) {
          for(q=0; q<i; q++) {
               for(r=0; r<i; r++) {
                    abc = numSet[p]*100 + numSet[q]*10 + numSet[r];

                    int m, n;
                    for(m=0; m<i; m++) {
                         for(n=0; n<i; n++) {
                              de = numSet[m]*10 + numSet[n];
                              int res = abc*de;
                              char buf[MAX_SIZE];
                              sprintf(buf, "%d", res);

                              int w;
                              int match = 1;
                              for(w=0; w<strlen(buf); w++) {
                                   if(strchr(s, buf[w]) == NULL) match = 0;
                              }

                              if(match) {
                                   printf("solution : %d * %d\n res : %d\n---------------------\n", abc, de, res);
                              }

                         }
                    }
               }
          }
     }

     return 0;
}
