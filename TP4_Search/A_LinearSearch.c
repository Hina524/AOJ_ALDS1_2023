#include <stdio.h>

int linearSearch(int[], int);

int n;

int main(){
  int i, cnt, q, S[10000], T[500];
  cnt = 0;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i<q; i++){
    if(linearSearch(S, T[i]) == 1) cnt++;
  }

  printf("%d\n",cnt);

  return 0;
}

int linearSearch(int A[], int key){
  int i = 0;
  A[n] = key;
  while(A[i] != key){
    i++;
    if(i == n){
      return 0;
    }
  }
  return 1;
}