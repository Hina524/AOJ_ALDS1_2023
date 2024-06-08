/*
入力
30000個の整数を含むファイルA.txt

出力
A.txtに含まれる偶数の個数
*/
#include <stdio.h>
#include <math.h>
#define N 30000

int main(){
  FILE *file;
  int i, n, evenCount;
  double A[10000];
  evenCount = 0;

  file = fopen("A.txt", "r");
  for(i = 0; i < N; i++){
    fscanf(file, "%lf", &A[i]);
    if((int)A[i] % 2 == 0){
      evenCount++;
    }
  }
  fclose(file);

  // 偶数出力
  printf("偶数: %d\n", evenCount);

  return 0;
}