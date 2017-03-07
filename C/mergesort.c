#include <stdio.h>
#include <stdlib.h>

#define GET_ARRAY_LEN(array, len) do {          \
    len = (sizeof(array)/sizeof(array[0]));     \
  }while(0)

struct node{
  int key;
  struct node *next;
};

typedef struct node *pNode;

int a[] = {10, 8, 5, 3, 2, 7, 6, 1, 0};
pNode z;

void printList(pNode header){
  pNode p = header;

  while(p != NULL){
    printf("%d\n", p->key);
    p = p->next;
  }
}

// a, b is sorted
pNode merge(pNode a, pNode b) {

  pNode c = (pNode)malloc(sizeof(struct node));
  pNode header = c;
  do {
    if(a->key >= b->key) {
      c->next = a;
      a = a->next;
      c = c->next;
    }
    else {
      c->next = b;
      b = b->next;
      c = c->next;
    }
    printf("merge header:\n");
    printList(c);
  } while(a != NULL && b != NULL);


  if(a) {c = a;}
  else {c = b;}
  header = header->next;

  return header;
}

pNode mergeSort(pNode header) {

  if(header == NULL) {return header;}

  pNode a, b;

  if(header->next != NULL) {

    a = header;

    b = header;

    while(b->next != NULL && b->next->next != NULL) {
      a = a->next;
      b = b->next->next;
      if(b == NULL) {
        break;
      }
    }

    b = a->next;
    a->next = NULL;
    a = header;
    printf("--------------------\n");
    printf("list a :\n");
    printList(a);
    printf("********************\n");
    printf("list b :\n");
    printList(b);
    return merge(mergeSort(a), mergeSort(b));
  }
  return header;
}


pNode mkList(int a[], int size){

  pNode header = (pNode)malloc(sizeof(struct node));

  header->key = a[0];
  header->next = NULL;
  pNode p = header;

  for(int i=1; i<size; i++){

    pNode n = (pNode)malloc(sizeof(struct node));
    n->key = a[i];
    n->next = NULL;

    p->next = n;
    p = n;

  }

  return header;
}


int main() {
  int len = 0;
  GET_ARRAY_LEN(a, len);
  printf("array size : %d\n", len);
  pNode l = mkList(a, len);
  printList(l);

  pNode r = mergeSort(l);
  //  printf("res : \n");
  //  printList(r);
  return 0;
}
