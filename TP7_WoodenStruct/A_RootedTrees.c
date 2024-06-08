/*
根付き木

入力
１行目 木の節点数 n
２行目以降 i番目の節点の情報
  id k c_1 c_2 ... c_k
  id: 節点の番号
  k: 子の数
  c_i: i番目の子の番号

出力
node id: parent = p, depth = d, type, [c_1, c_2, ...]
節点番号、親の節点番号、深さ、節点の種類、子の節点番号
番号が小さい順に出力
*/
#include <stdio.h>

typedef struct{
  int parent, leaf, sibling;
} Tree;

int n, k;
Tree A[100000] = {0};

int getDepth(int p);

int main(){
  int i, j, temp, id, child;

  scanf("%d", &n);

  for (i=0; i<n; i++){
    A[i].parent = -1;
    A[i].leaf = -1;
    A[i].sibling = -1;
  }

  for(i=0; i<n; i++){
    scanf(" %d %d", &id, &k);
    for(j=0; j<k; j++){
      scanf("%d", &child);
      if(j==0) A[id].leaf = child;
      else A[temp].sibling = child;
      A[child].parent = id;
      temp = child;
    }
  }

  for(i=0; i<n; i++){
    printf("node %d: parent = %d, depth = %d, ", i, A[i].parent, getDepth(i));
    if(A[i].parent==-1) printf("root, ");
    else if(A[i].leaf==-1) printf("leaf, ");
    else printf("internal node, ");
    if(A[i].leaf==-1) printf("[]\n");
    else{
      printf("[%d", A[i].leaf);
      temp = A[i].leaf;
      while(A[temp].sibling!=-1){
        printf(", %d", A[temp].sibling);
        temp = A[temp].sibling;
      }
      printf("]\n");
    }
  }

  return 0;
}

int getDepth(int p) {
  if(A[p].parent==-1) return 0;
  return getDepth(A[p].parent) + 1;
}