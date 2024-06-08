/*
n=20 6765
n=90 2880067194370816120
*/
#include<stdio.h>

long long fibonacci(long long);

long long F[95];

int main(){
  int n, i;

  scanf("%d",&n);
  printf("%lld\n",fibonacci(n-1));

  return 0;
}

long long int fibonacci(long long n){
  if(n==0 || n==1) return F[n] = 1;
  if(F[n]!=0) return F[n];
  return F[n] = fibonacci(n-1) + fibonacci(n-2);
}

// #include<stdio.h>

// int main(){
//   int n,i;
//   int F[50];

//   F[0]=1;
//   F[1]=1;

//   scanf("%d",&n);

//   for(i=2;i<=n;i++){
//     F[i]=F[i-1]+F[i-2];
//   }

//   printf("%d\n",F[n]);

//   return 0;
// }