#include<stdio.h>

void swap(int * a, int * b){
    int t;
    if(a != b) {
        t = *a;
        *a = *b;
        *b = t;
    }
}


int partition(int array[], int begin, int end) {
    if(begin >= end) {
        return -1;
    }

    int var;

    var = array[end];
    int l = begin - 1;
    int r = end;
    for(;;) {
        while(array[--r] > var);
        while(array[++l] < var);

        if(l < r) {
            swap(&array[l], &array[r]);
        }
        else {
            break;
        }
    }
    swap(&array[l], &array[end]);
    return l;
}


void qsort(int array[], int begin, int end) {
    if(begin < end) {

        int i = partition(array, begin, end);

        if(i != -1) {
            qsort(array, begin, i-1);
            qsort(array, i+1, end);
        }
    }
}


int main() {
    int array[] = {3,1,5,5,1,2,5,2,6,9,0,7};

    int len = sizeof(array)/sizeof(int);

    qsort(array, 0, len-1);

    for(int i = 0; i < len; i++) {
        printf("%d\t", array[i]);
    }
    return 0;
}
