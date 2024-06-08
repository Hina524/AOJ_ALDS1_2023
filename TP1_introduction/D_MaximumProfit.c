/*
最大利益
１行目 n
２行目 n個の整数 R_1, R_2, ..., R_n

出力
価格差の最大値
*/
#include <stdio.h>

int main(){
  int i, n, R[200000], min, max;
  scanf("%d",&n);
  scanf("%d %d", &R[0], &R[1]);
  if(R[0]<R[1]){
    min=R[0];
  } else {
    min=R[1];
  }
  max = R[1] - R[0];
  for(i=2; i<n; i++){
    scanf("%d", &R[i]);
    if(max<R[i]-min){
      max = R[i]-min;
    }
    if(min>R[i]){
      min = R[i];
    }
  }
  printf("%d\n",max);

  return 0;
}
