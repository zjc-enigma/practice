#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef char treeElementT;

typedef struct treeNodeTag {
  treeElementT element;
  struct treeNodeTag *left, *right;

} treeNodeT;

typedef struct treeCDT {
  treeNodeT *root;
} treeCDT;

typedef struct treeCDT *treeADT;


void TreeInit(treeADT t){
  //  t->root = (treeNodeT *)malloc(sizeof )
}

void TreeAdd(treeADT t, treeElementT elem){

}

void TreeRemove(treeADT t, treeElementT elem){

}

int TreeIsMember(treeADT tree, treeElementT elem){
  return RecTreeIsMember(tree->root, elem);
}

static int RecTreeIsMember(treeNodeT t, treeElementT elem){

  if(!t) return FALSE;

  if(t->element == elem) {
    return TRUE;
  }

  if(RecTreeIsMember(t->left, elem)){
    return TRUE;
  }

  return RecTreeIsMember(t->right, elem)}
}

void TreeDestory(treeADT t){

}
