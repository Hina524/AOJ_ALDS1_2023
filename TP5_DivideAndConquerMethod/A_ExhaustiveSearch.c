/*
入力
１行目 n
２行目 A1, A2, ..., An
３行目 q
４行目 M1, M2, ..., Mq

出力
Aを足しあわせてMが作れるかどうか
作れるならyes, 作れないならno
*/
#include <stdio.h>

int i, n, q, A[2000], M[2000];

int solve(int i, int);

int main(){
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d",&M[i]);
  }

  for(i=0;i<q;i++){
    if(solve(0,M[i])){
      printf("yes\n");
    }
    else printf("no\n");
  }

  return 0;
}

int solve(int i,int m){
  int sum=0;
  if(m==0)return 1;
  if(i>=n)return 0;
  else{
  sum+=solve(i+1,m);
  sum+=solve(i+1,m-A[i]);
  }
  return sum;
}