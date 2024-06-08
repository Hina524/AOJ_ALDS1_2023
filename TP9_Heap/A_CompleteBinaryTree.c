#include <stdio.h>

int main(){
  int n,i,a[250];
  scanf("%d" ,&n);
  for(i = 0 ; i < n ; i++) scanf("%d" , &a[i]);

  for(i = 0 ; i < n ; i++){
    printf("node %d: key = %d, " ,i+1 ,a[i]);
    if(i) printf("parent key = %d, " ,a[(i+1)/2-1]);
    if(2*i+1 < n) printf("left key = %d, " ,a[2*i+1]);
    if(2*i+2 < n) printf("right key = %d, " ,a[2*i+2]);
    printf("\n");
  }
  return 0;
}