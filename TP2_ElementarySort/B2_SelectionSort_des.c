/*
入力
１行目 整数N
２行目 N個の整数

出力
降順で選択ソートされたN個の整数
*/
#include <stdio.h>

int main(){
  int i, j, temp, min, cnt, N, A[100];
  cnt = 0;

  scanf("%d", &N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i<N-1; i++){
    min = i;
    for(j=i+1; j<N; j++){
      if(A[j] > A[min]){
        min = j;
      }
    }
    if(min != i){
      temp = A[i];
      A[i] = A[min];
      A[min] = temp;
      cnt++;
    }
  }

  for(j=0; j<N-1; j++){
    printf("%d ",A[j]);
  }
  printf("%d\n%d\n",A[N-1],cnt);

  return 0;
}