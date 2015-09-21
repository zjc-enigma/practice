#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 3

#define GET_ARRAY_LEN(array, len) do {          \
    len = (sizeof(array)/sizeof(array[0]));     \
  }while(0)


typedef int elem_t;

typedef struct queue{
  int header;
  int size;
  elem_t *base;

} *pQueue;

typedef struct queue queue;

int queueIsFull(pQueue q) {
  //int len = sizeof(q->base)/sizeof(q->base[0]);
  //printf("len : %d\n", len);

  if(q->size >= MAXSIZE) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

int queueIsEmpty(pQueue q) {
  if(q->size == 0) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

void initQueue(pQueue q) {

  //  printf("init queue size : %d\n", len);

  q->base = (elem_t *)malloc(sizeof(elem_t)*MAXSIZE);
  if(!q->base) {

    fprintf(stderr, "error in malloc\n");
    exit(-1);
  }

  q->size = 0;
  q->header = -1;
}


void enQueue(pQueue q, elem_t e){

  if(queueIsFull(q)){
    fprintf(stderr, "queue is full\n");
    exit(-1);
  }

  if(q->size == 0){
    q->header = 0;
   }
  q->base[q->header] = e;
  q->header--;
  q->size++;
  q->header = (q->header + MAXSIZE) % MAXSIZE;
}

elem_t deQueue(pQueue q){

  if(queueIsEmpty(q)){
    fprintf(stderr, "queue is empty\n");
    exit(-2);
  }
  int tail = (q->header + q->size) % MAXSIZE;

  elem_t res = q->base[tail];

  q->size--;

  if(q->size ==  0){
    q->header = -1;
  }
  return res;
}

void deleteQueue(pQueue q){

  free(q->base);
  q->base = NULL;
  q->header = -1;
  q->size = 0;
}

int main(){
  elem_t aa[] = {2,1,5,6,7};
  queue q;
  //  char *cc = "abcde";
  //  int len = sizeof(cc)/sizeof(cc[0]);
  //  printf("string len : %d\n", len);
  //  len = strlen(cc);
  //  printf("strlen : %d\n", len);
  initQueue(&q);
  enQueue(&q, aa[2]);
  enQueue(&q, aa[1]);
  enQueue(&q, aa[0]);
  deQueue(&q);
  enQueue(&q, aa[0]);
  deQueue(&q);
  enQueue(&q, aa[0]);
  printf("%d\n", deQueue(&q));
  printf("%d\n", deQueue(&q));
  printf("%d\n", deQueue(&q));

  return 0;
}
