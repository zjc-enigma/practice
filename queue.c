#include <stdio.h>
typedef struct node {
  int val;
  struct node *next;
} *pNode;

typedef struct queue{

  pNode header;
  pNode tail;
  int size;
} *pQueue;

void initQueue(pQueue q) {
  q->size = 0;
  q->header = NULL;
  q->tail = NULL;
}

void enQueue(pQueue q, pNode n) {
  n->next = q->header;
  q->header = n;
  q->size++;
  if(q->size == 1) {
    q->tail = n;
  }
}

pNode deQueue(pQueue q) {
  if(q->size == 0) {
    return NULL;
  }
  pNode res = q->tail;


}

int main() {



}
