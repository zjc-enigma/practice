#include<stdio.h>

#define GET_ARRAY_LEN(array, len) do {          \
    len = (sizeof(array)/sizeof(array[0]));     \
  }while(0)


int binSearch(int a[], int size, int value) {

  int left = 0;
  int right = size - 1;
  int mid;

  while(right >= left) {

    mid = (right + left)/2;

    /* printf("mid : %d\n", mid); */
    /* printf("left : %d\n", left); */
    /* printf("right : %d\n", right); */

    if(a[mid] > value){
      right = mid - 1;
      //      printf("a\n");
    }
    else if(a[mid] < value){
      left = mid + 1;
      //      printf("b\n");
    }
    else if(a[mid] == value){
      return mid;
    }

  }
  printf("can not found\n");
  return -1;
}


int main(){
  int len = 0;
  int a[] = {1, 2 ,3 ,9 , 42, 100, 200, 7000};
  GET_ARRAY_LEN(a, len);
  int value;
  printf("input value to search:");
  scanf("%d", &value);

  int i = binSearch(a, len, value);
  printf("find index is : %d\n", i);

  return 0;
}
