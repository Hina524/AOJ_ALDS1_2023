/*
入力
30000個の整数を含むファイルA.txt

出力
A.txtに含まれる奇数の個数
*/
#include <stdio.h>
#include <math.h>
#define N 30000

int main(){
  FILE *file;
  int i, n, oddCount;
  double A[10000];
  oddCount = 0;

  file = fopen("A.txt", "r");
  for(i = 0; i < N; i++){
    fscanf(file, "%lf", &A[i]);
    if((int)A[i] % 2 != 0){
      oddCount++;
    }
  }
  fclose(file);

  // 奇数出力
  printf("奇数の数: %d\n", oddCount);

  return 0;
}