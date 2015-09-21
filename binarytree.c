#include<stdio.h>
#define TRUE 1
#define FALSE 0

int array[] = {1,12,4,9,-1,0,8};

struct treeNode{
  int value;
  struct treeNode *left;
  struct treeNode *right;

};

typedef struct treeNode *pTreeNode;


/*
insertion rules:
smaller --> left
bigger --> right
*/

int insertNode(pTreeNode root, pTreeNode node) {
  
  if(root == NULL) {
    root = node;
    return TRUE;
  }

  if(root->value > node->value) {
    return(insertNode(root->left, node));
  }
  else {
    return(insertNode(root->right, node));
  }
}

int deleteNode(pTreeNode root, pTreeNode node) {
  
  if(root == NULL) {
    return FALSE;
  }

  if(root->value == node-> value) {
    root = NULL;
    return TRUE;
  }
  if(root->value > node->value) {
    return(deleteNode(root->left, node));
  }
  else {
    return(deleteNode(root->right, node));
  }
}

int getTreeDepth(pTreeNode root){
  
  if(root == NULL) {return 0;}
  
  int leftDepth = getTreeDepth(root->left);
  int rightDepth = getTreeDepth(root->right);
  return((leftDepth > rightDepth ? leftDepth : rightDepth) + 1);
}



int main() {


}
