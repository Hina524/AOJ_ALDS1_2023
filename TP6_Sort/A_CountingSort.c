/*
計数ソート
１行目 n
２行目 整数列 A

出力
整列列 B
計数ソートで昇順に並び替える
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10001

void CountingSort(unsigned short[], unsigned short[], int);

unsigned short *A, *B;
int n, k=0;

int main(){
  scanf("%d", &n);
  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
  for(int i=0; i<n; i++){
    scanf("%hd",&A[i]);
    if(A[i]>k) k = A[i];
  }

  CountingSort(A, B, k);

  for(int i=0; i<n-1; i++) printf("%d ",B[i]);
  printf("%d\n",B[n-1]);

  free(A);
  free(B);

  return 0;
}

void CountingSort(unsigned short A[], unsigned short B[], int k){
  int i, j, C[VMAX+1];
  for(i=0; i<=k; i++) C[i] = 0;
  for(j=0; j<n; j++) C[A[j]]++;
  for(i=1; i<=k; i++) C[i] += C[i-1];
  for(j=n-1; j>=0; j--){
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
  }
}