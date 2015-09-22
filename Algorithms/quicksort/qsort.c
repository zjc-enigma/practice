#include <stdio.h>

#define SWAP1(A, B)                             \
    do {                                        \
        (A)=(A)^(B);                            \
        (B)=(A)^(B);                            \
        (A)=(A)^(B);                            \
    } while(0)

#define SWAP2(A, B)                             \
    do {                                        \
        typeof(A) t;                            \
        t = (A);                                \
        (A) = (B);                              \
        (B) = t;                                \
    } while(0)


#define SWAP3(A, B)                             \
    do {                                        \
        (A) = (A)+(B);                          \
        (B) = (A)-(B);                          \
        (A) = (A)-(B);                          \
    } while(0)


int test_array[]={16,31,22,9,71,88,0,-1,10,5};


int partition(int a[], int begin, int end) {

    if(begin < end) {
        int i, j, v;
        i = begin - 1;
        j = end;
        v = a[end];

        for(;;){
            while(a[++i] < v);
            while(a[--j] > v);
            if(i >= j) break;

            SWAP2(a[i], a[j]);
        }
        SWAP2(a[i], a[end]);
        return i;
    }
    else
        return -1;
}



/* void qsort_norecursive(int a[], int size) { */
/*     int begin = 0; */
/*     int end = size; */
/*     stackinit(); */

/* } */



void qsort_basic(int a[], int begin, int end) {

    if(begin < end) {
        int i = partition(a, begin, end);

        if(i > begin && i < end) {
            qsort_basic(a, begin, i-1);
            qsort_basic(a, i+1, end);
        }
    }
}



void test_case() {
    int ccc = 10;
    SWAP1(ccc, ccc);
    printf("%d\n", ccc);

    ccc = 20;
    SWAP2(ccc, ccc);
    printf("%d\n", ccc);

    ccc = 30;
    SWAP3(ccc, ccc);
    printf("%d\n", ccc);
}

int main(){

    int len = sizeof(test_array)/sizeof(int);

    qsort_basic(test_array, 0, len - 1);

    for(int i=0; i < len; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");
}
