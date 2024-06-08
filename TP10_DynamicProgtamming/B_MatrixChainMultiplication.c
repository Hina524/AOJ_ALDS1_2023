/*
連鎖行列式

入力
１行目 行列の数N
２行目以降 行の数r 列の数c

出力
最小の掛け算回数
*/
#include <stdio.h>
#define MAX 100

int main(){
  int N,i,j,k,l,q,r[MAX],c[MAX],p[MAX+1];
  int  A[MAX+1][MAX+1];

  scanf("%d",&N);
  for(i = 0 ; i < N ; i++) scanf("%d%d",&r[i],&c[i]);
  p[0] = r[0];
  for(i = 1 ; i <= N ; i++) p[i] = c[i-1];
  N++;
  for(i = 0 ; i < N ; i++)  A[i][i] = 0;
  for(l = 2 ; l < N ; l++){
    for(i = 1 ; i < N-l+1 ; i++){
      j = i + l - 1;
      A[i][j] = 1e8;
      for(k = i ; k <= j-1 ; k++){
        q =  A[i][k] +  A[k+1][j] + p[i-1]*p[k]*p[j];
        if(q <  A[i][j]) A[i][j] = q;
      }
    }
  }

  printf("%d\n", A[1][N-1]);

  return 0;
}
