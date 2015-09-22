#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100

typedef struct node{
  int val;
  struct node *next;
} *pNode;


typedef int elem_t;

typedef struct stack{
  int top;
  elem_t *base;
  int size;

} *pStack;


int stackIsEmpty(pStack s){
  return (s->top < 0);

}

int stackIsFull(pStack s){
  return (s->top >= s->size - 1);
}

void stackInit(pStack s, int maxsize){
  s->base = (elem_t *)malloc(sizeof(elem_t)*maxsize);
  if(s->base == NULL) {
    fprintf(stderr, "malloc failed\n");
    exit(-1);
  }

  s->top = -1;
  s->size = maxsize;
}


void push(pStack s, elem_t n) {
  if(stackIsFull(s)) {
    fprintf(stderr, "stack full\n");
    exit(-2);
  }

  s->base[++s->top] = n;
  s->size--;
}

elem_t pop(pStack s){

  if(stackIsEmpty(s)) {

    fprintf(stderr, "stack empty\n");
    exit(-1);
  }
  elem_t e = s->base[s->top--];
  s->size++;
  return e;
}

int stackDestory(pStack s){
  free(s->base);
  s->base = NULL;
  s->top = -1;
  s->size = 0;
  return 0;
}


int main(){

  stack s;
  stackInit(&s, 10);
  push(&s, 5);
  push(&s, 6);

  printf("%d\n", pop(&s));
  printf("%d\n", pop(&s));
  return 0;
}
