#include <stdio.h>
typedef long long ll;

int check(ll limit,ll w[],int n,int k){
  int i,kk = 0;
  ll sum = 0;

  for(i = 0 ; i < n ; i++){
    if(limit < w[i]) return 0;
    sum += w[i];
    if(sum == limit){
      kk++;
      sum = 0;
    }else if(sum > limit){
      kk++;
      sum = w[i];
    }
  }

  if(sum > 0) kk++;

  return kk <= k;
}

int main(){
  int n,k,i;
  ll lb,ub,mid,w[100000],sum = 0;

  scanf("%d%d" ,&n ,&k);
  for(i = 0 ; i < n ; i++){
    scanf("%lld" ,&w[i]);
    sum += w[i];
  }

  lb = 0, ub = sum;
  while(ub - lb > 0){
    mid = (lb + ub) / 2;
    if(check(mid,w,n,k)){
      ub = mid;
    }else{
      lb = mid+1;
    }
  }
  printf("%lld\n" ,ub);

  return 0;
}