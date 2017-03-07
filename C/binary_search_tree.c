#include <stdio.h>

typedef int treeKey;
typedef char treeValue ;
typedef struct {
  treeKey key;
  treeValue value;
} treeElem;



typedef struct treeNode {
  treeElem elem;
  struct treeNode *left, *right;
} treeNode ;

typedef struct BSTCDT {
  treeNode *root;
}BSTCDT;

typedef BSTCDT *BSTADT;


BSTADT BSTCreat(){
  BSTADT t = (BSTADT) malloc(sizeof(BSTCDT));
  t->root->left = NULL;
  t->root->right = NULL;
  return t;
}

void BSTDestory(BSTADT t){


}

void BSTAdd(BSTADT t, treeElem e){
  RecBSTAdd(t->root, e);
}

static void RecBSTAdd(treeNode *root, treeElem e){

  if(root == NULL) {

    root = (treeNode *)malloc(sizeof(treeNode));
    root->elem = e;
    root->left = NULL;
    root->right = NULL;
  } else if(root->elem->key > e->key) {
    RecBSTAdd(root->left, e);

  } else if(root->elem->key < e->key) {
    RecBSTAdd(root->right, e);
  }
  else{
    fprintf(stderr, "same node key\n");
  }
}

void BSTDelete(){}

int BSTIsMember(BSTADT t, treeElem e){

}

static int RecBSTIsMember(treeNode *root, treeElem e){

  if(root == NULL) return FALSE;

  if(root->elem == e) return TRUE;


  if(root->elem->key > e->key) {
    return RecBSTIsMember(root->left, e);
  }
  return RecBSTIsMember(root->right, e);

}

void BSTPrint(){


}



int main(){

  return 0;
}
