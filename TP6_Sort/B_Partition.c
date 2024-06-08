/*
入力
１行目 n
２行目 整数列 S

出力
分割された数列
基準に[]をつける
*/
#include <stdio.h>

int n, x, A[100000], p=0;

void swap(int* a,int* b);
int Partition(int r);

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d",&A[i]);
  }

  x = Partition(n-1);

  for(int i=0;i<n;i++){
    if(i)printf(" ");
    if(i==x)printf("[");
    printf("%d",A[i]);
    if(i==x)printf("]");
  }
  printf("\n");

  return 0;
}

void swap(int* a,int* b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

int Partition(int r){
  int x = A[r];
  int i = p - 1;
  for(int j=p; j<r; j++){
    if(A[j]<=x){
      i++;
      swap(&A[j], &A[i]);
    }
  }
  swap(&A[i+1], &A[r]);
  return i+1;
}