#include <stdio.h>

void swap(int * a, int * b){
    int t;
    if(a != b) {
        t = *a;
        *a = *b;
        *b = t;
    }
}



void bubsort(int array[], int size){
    int i = 0;

    while(i < size - 1) {
        int j = i + 1;
        while(j < size) {
            if(array[i] > array[j]) {
                swap(&array[i], &array[j]);
            }
            j++;
        }
        i++;
    }
}






int main() {
    int array[] = {3,1,5,5,1,2,5,2,6,9,0,7};

    int len = sizeof(array)/sizeof(int);

    bubsort(array, len);

    for(int i = 0; i < len; i++) {
        printf("%d\t", array[i]);
    }
    return 0;
}
