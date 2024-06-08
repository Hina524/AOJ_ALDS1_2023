/*
入力
１行目 n
２行目 整数列 S

出力
１行目 マージソートされた整列列 S
２行目 比較回数
*/
#include <stdio.h>
#include <limits.h>
#define INF INT_MAX

void merge( int[], int, int, int);
void mergeSort( int[], int, int);

int i, n, S[500000], cnt = 0;

int main(){
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

	mergeSort(S,0,n);

	for(int i = 0; i < n-1; i++){
    printf("%d ",S[i]);
  }
	printf("%d\n",S[n-1]);
	printf("%d\n",cnt);

  return 0;
}

void merge( int A[], int left, int mid, int right){
  int i = 0, j = 0, k;
	int n1 = mid - left;
	int n2 = right - mid;
	int L[n1+1],R[n2+1];
	for(int i=0; i<n1; i++) L[i] = A[left+i];
	for(int i=0; i<n2; i++) R[i] = A[mid+i];
	L[n1] = R[n2] =  INF;

	for(k=left; k<right; k++){
		if(L[i] <= R[j]){
			A[k] = L[i++];
			cnt++;
		}else{
			A[k] = R[j++];
			cnt++;
		}
	}
}

void mergeSort( int A[], int left, int right){
	if(left+1 < right){
		int mid = (left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}