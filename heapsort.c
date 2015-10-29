#include <stdio.h>

#define SWAP(A, B)                         \
  do {                                      \
    typeof(A) t;                            \
    t = (A);                                \
    (A) = (B);                              \
    (B) = t;                                \
 } while(0)

void heapify(int *array, int size, int i){
  int child;
  while((child = 2*i + 1) < size){

    if(child < size - 1){
      if(array[child] < array[child+1]) { // compare left & right
        child++;
      }
    }
    if(array[i] >= array[child]){
      break;
    }
    SWAP(array[i], array[child]);
    i = child;
  }
}

void heapsort(int *array, int size){
  int i;
  for(i=size/2; i>=0; i--){
    heapify(array, size, i);
  }
  while(size > 1){
    SWAP(array[0], array[size-1]);
    heapify(array, --size, 0);
  }
}




int main(){

  int array[] = {1,4,-3,0,5,8};
  heapsort(array, 6);
  int i;
  for(i=5;i>=0;i--){
    printf("%d\t", array[i]);
  }
  return 0;
}
