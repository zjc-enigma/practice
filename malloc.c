#include <stdio.h>
#include <stdlib.h>

char *getMem(char t)
{
    char *p = (char *)malloc(sizeof(char)*3);
    p[0] = t;
    p[1] = 'a';
    p[2] = '5';
    return p;
}


int main()
{
    int *a = (int *)malloc(sizeof(int));
    *a = 1;
    a = (int *)realloc(a, 3*sizeof(int));
    printf("sizeof a* %lu\n",sizeof(a));
    a[1] = 2;
    a[2] = 3;
    printf("sizeof int %lu\n", sizeof(int));
    printf("sizeof pointer %lu\n", sizeof(int *));
    int *p = a + 2;
    printf("p %d\n", *p);
//    free(p);
    a = realloc(a, 2*sizeof(int));
    printf("p %d\n", *p);

    printf("get mem :%s\n", getMem('r'));

    return 0;

}
