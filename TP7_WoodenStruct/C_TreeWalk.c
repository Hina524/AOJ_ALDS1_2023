/*
入力
id left right

出力
Preorder：先行順巡回：根、左部分木、右部分木の順
Inorder：中間順巡回：左部分木、根、右部分木の順
Postorder：後行順巡回：左部分木、右部分木、根の順
*/
#include <stdio.h>
#define NIL -1

typedef struct{
  int id, left, right, parent;
} Tree;

int n, k;
Tree A[100000] = {0};

void preorder(int);
void inorder(int);
void postorder(int);

int main(){
  int i, p, id, left, right;

  scanf("%d", &n);

  for(i = 0 ; i < n ; i++){
    A[i].parent = A[i].left = A[i].right = NIL;
  }

  for(i=0; i<n; i++){
    scanf("%d %d %d", &id, &left, &right);
    if(left != NIL){
      A[id].left = left;
      A[left].parent = id;
    }
    if(right != NIL){
      A[id].right = right;
      A[right].parent = id;
    }
  }

  for(i = 0 ; i < n ; i++){
    if(A[i].parent == NIL){
      p = i;
      break;
    }
  }

  printf("Preorder\n"); // puts() だと改行が入る
  preorder(p);
  printf("\n");

  printf("Inorder\n");
  inorder(p);
  printf("\n");

  printf("Postorder\n");
  postorder(p);
  printf("\n");

  return 0;
}

void preorder(int p){
  if(p != NIL){
    printf(" %d", p);
    preorder(A[p].left);
    preorder(A[p].right);
  }
}

void inorder(int p){
  if(p != NIL){
    inorder(A[p].left);
    printf(" %d", p);
    inorder(A[p].right);
  }
}

void postorder(int p){
  if(p != -1){
    postorder(A[p].left);
    postorder(A[p].right);
    printf(" %d", p);
  }
}