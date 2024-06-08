#include <stdio.h>

int main() {
  int n,A[101][101];
  int i,j,k,u,a;

  scanf("%d",&n);

  for(i=0;i<n+1;i++)
    for(j=0;j<n+1;j++) {
      A[i][j] = 0;
    }
  for(i=0;i<n;i++){
    scanf("%d %d ",&k,&u);
    for(j=0;j<u;j++) {
      scanf("%d",&a);
      A[k -1][a-1] = 1;
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++) {
      printf("%d",A[i][j]);
      if(j != n-1) printf(" ");
    }
    printf("\n");
  }

  return 0;
}
