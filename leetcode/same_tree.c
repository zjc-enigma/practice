#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define bool int
typedef struct treeNode{
  int val;
  struct treeNode *left;
  struct treeNode *right;
} *pTreeNode;


bool sameTree(struct treeNode *a, struct treeNode *b) {

  if((!a && b) || (a && !b)) {return FALSE;}

  if(!a && !b) {return TRUE;}

  if(a->val == b->val){
    return(sameTree(a->left, b->left) && sameTree(a->right, b->right));
  } else {
    return FALSE;
  }
}

int main(void){

  struct treeNode *a = NULL;
  struct treeNode *b = NULL;
  printf("%d\n", sameTree(a, b));
  return 0;
}
