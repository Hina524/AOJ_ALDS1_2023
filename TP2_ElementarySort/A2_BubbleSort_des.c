/*
入力
１行目 整数N
２行目 N個の整数

出力
降順でバブルソートされたN個の整数
*/
#include <stdio.h>

int main(){
  int i, j, cnt, flag, temp, N, A[100];
  flag = 1;
  i = 0;
  cnt = 0;

  scanf("%d", &N);
  for(j=0; j<N; j++){
    scanf("%d",&A[j]);
  }

  while(flag){
    flag = 0;
    for(j = N-1; j>i; j--){
      if(A[j] > A[j-1]){
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
        flag = 1;
        cnt++;
      }
    }
    i++;
  }

  for(j=0; j<N-1; j++){
    printf("%d ",A[j]);
  }
  printf("%d\n%d\n",A[N-1],cnt);

  return 0;
}