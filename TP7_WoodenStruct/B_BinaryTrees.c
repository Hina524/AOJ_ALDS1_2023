/*
入力
id left right

出力
id, parent, sibling, degree, depth, height, type
節点番号, 親の節点番号, 兄弟の節点番号, 子の数, 深さ, 高さ, 節点の種類
*/
#include <stdio.h>
#define NIL -1

typedef struct{
  int parent, left, right, sibling, degree, height;
} Tree;

int n, k;
Tree A[100000] = {0};

int getDepth(int p);
int getHeight(int i);

int main(){
  int i, j, temp, id, left, right;

  scanf("%d", &n);

  for (i=0; i<n; i++){
    A[i].parent = NIL;
    A[i].sibling = NIL;
  }

  for(i=0; i<n; i++){
    scanf("%d %d %d", &id, &left, &right);
    A[id].left = left;
    A[id].right = right;
    if(left!=NIL && right!=NIL){
      A[left].parent = id;
      A[right].parent = id;
      A[left].sibling = right;
      A[right].sibling = left;
      A[id].degree = 2;
    } else if(left!=NIL){
      A[left].parent = id;
      A[id].degree = 1;
    } else if(right!=NIL){
      A[right].parent = id;
      A[id].degree = 1;
    }
  }

  for(i=0; i<n; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, A[i].parent, A[i].sibling, A[i].degree, getDepth(i), getHeight(i));
    if(A[i].parent==NIL) printf("root\n");
    else if(A[i].left==NIL && A[i].right==NIL) printf("leaf\n");
    else printf("internal node\n");
  }

  return 0;
}

int getDepth(int p) {
  if(A[p].parent==NIL) return 0;
  return getDepth(A[p].parent) + 1;
}

int getHeight(int i){
  int s=0,t=0;
  if(A[i].left==NIL && A[i].right==NIL)return 0;
  if(A[i].left!=NIL) s=getHeight(A[i].left)+1;
  if(A[i].right!=NIL) t=getHeight(A[i].right)+1;
  if(s>t) return s;
  else return t;
}