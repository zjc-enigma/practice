#include<stdio.h>
#define TRUE 1
#define FALSE 0

int array[] = {1,12,4,9,-1,0,8};

typedef struct {
  int value;
  node *left;
  node *right;

} node;

int insertnode(node *root, node *t){
  if(t == NULL) {return FALSE;}

  if(root == NULL) {
    root = t;
    return TRUE;
  }



}

int main() {


}
