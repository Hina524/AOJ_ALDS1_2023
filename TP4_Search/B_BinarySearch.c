#include <stdio.h>

int i, cnt, n, q, S[100000], T[50000];

int binarySearch(int key);

int main(){
  int cnt = 0;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i<q; i++){
    if(binarySearch(T[i]) == 1) cnt++;
  }

  printf("%d\n",cnt);

  return 0;
}

int binarySearch(int key){
  int left =0;
  int right = n;
  while(left < right){
    int mid = (left + right) / 2;
    if(S[mid] == key){
      return 1;
    } else if (key < S[mid]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return 0;
}