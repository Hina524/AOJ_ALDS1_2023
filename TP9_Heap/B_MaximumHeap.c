/*
最大ヒープ
接点のキーがその親のキー以下であるような二分木
最大の要素が根

入力
１行目 ヒープのサイズ n
２行目 整数列 A

出力
接点の値を接点の番号が１からnにかけて出力

eg.
10
4 1 3 2 16 9 10 14 8 7

 16 14 10 8 7 9 3 2 4 1
*/
#include <stdio.h>
#define MAX 500000

int A[MAX+1], n;  // 配列A、および要素の数n

// 要素の入れ替えを行う関数
void swap(int*, int*);

// Max Heapの性質を維持するための再帰関数
void maxHeapify(int);

// 配列AをMax Heapに変換する関数
void buildMaxHeap(void);

int main(){
  int i;

  // 要素数nの入力と配列Aの初期化
  scanf("%d", &n);
  for(i=1; i<=n; i++) scanf("%d", &A[i]);

  // 配列AをMax Heapに変換
  buildMaxHeap();

  // Max Heapに変換された配列Aを出力
  for(i=1; i<=n; i++) printf(" %d", A[i]);
  printf("\n");

  return 0;
}

// 2つの要素の値を入れ替える関数
void swap(int* a, int* b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// Max Heapの性質を維持するための再帰関数
void maxHeapify(int i){
  int l = 2*i;       // 左の子の添字
  int r = 2*i+1;     // 右の子の添字
  int largest;

  // 左の子と比較して最大の値を選ぶ
  if(l <= n && A[l] > A[i]) largest = l;
  else largest = i;

  // 右の子と比較して最大の値を選ぶ
  if(r <= n && A[r] > A[largest]) largest = r;

  // 最大の値が親ではない場合、入れ替えて再帰的にMax Heapの性質を維持
  if(largest != i){
    swap(&A[i], &A[largest]);
    maxHeapify(largest);
  }
}

// 配列AをMax Heapに変換する関数
void buildMaxHeap(){
  int i;
  // 配列の中央から順にmaxHeapifyを適用していくことで、配列全体がMax Heapになる
  for(i = n/2; i > 0; i--) maxHeapify(i);
}
