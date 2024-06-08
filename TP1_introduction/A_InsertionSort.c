#include <stdio.h>

int main(){
  int i, j, k, key, N;
  int A[100];

  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i+1]);
  }

  for(j=1; j<=N; j++)
  {
    key = A[j];
    i = j-1;
    while(i>0 && A[i]>key)
    {
      A[i+1]=A[i];
      i --;
    }
    A[i+1] = key;
    for(k=1; k<=N; k++){
      if(k == N) printf("%d\n",A[k]);
    else printf("%d ",A[k]);
    }
  }

  return 0;
}