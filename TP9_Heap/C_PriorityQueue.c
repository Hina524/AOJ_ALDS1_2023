/*
優先度付きキューSへ命令を与える
insert k: Sにキーkを挿入する
extract: Sから最大のキーを持つ要素を削除し、そのキーを出力する
end: 終了する
*/
#include <stdio.h>
#include <limits.h>
#include <string.h>
#define MAX_H 2000000
#define INF INT_MIN

int H;

int heapExtractMax(int *A){
  int max;
  if(H < 1) return -1;
  max = A[0];
  A[0] = A[H-1]; H--;
  maxHeapify(A,0);
  return max;
}

void maxHeapify(int *A,int i){
  int l = i*2+1, r = i*2+2;
  int largest;
  if(l <= H && A[l] > A[i]) largest = l;
  else largest = i;

  if(r <= H && A[r] > A[largest]) largest = r;
  if(largest != i){
    swap(&A[i],&A[largest]);
    maxHeapify(A,largest);
  }
}

void maxHeapInsert(int *A,int val){
  H++;
  A[H-1] = INF;
  heapIncreseKey(A,H-1,val);
}

void heapIncreseKey(int *A,int i,int val){
  int j;
  if(val < A[i]){ return; }
  A[i] = val;
  j = (i & 1 ? i/2 : (i-1)/2);
  while(i > 0 && A[j] < A[i]){
    swap(&A[i],&A[j]);
    i = j;
    j = (i & 1 ? i/2 : (i-1)/2);
  }
}

void swap(int *a,int *b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(){
  static int a[MAX_H];
  char command[8];
  int val;
  H = 0;
  while(1){
    scanf("%s",command);
    if(!strcmp(command,"end")){
      break;
    }else if(!strcmp(command,"insert")){
      scanf("%d",&val);
      maxHeapInsert(a,val);
    }else{
      printf("%d\n",heapExtractMax(a));
    }
  }

  return 0;
}
