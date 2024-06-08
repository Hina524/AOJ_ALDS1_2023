/*
入力
１行目 n
２行目以降 n 個の整数 A[i] (1 ≤ A[i] ≤ 10^9)

出力
nこの整数のうち、素数であるものの個数
*/
#include <stdio.h>
#include <math.h>

int main(){
  FILE *file;
  int i, j, n, cnt;
  double A[10000];
  cnt = 0;

  // ファイルを読み込む
  file = fopen("A.txt", "r");
  if (file == NULL) {
    printf("ファイルを開けませんでした。\n");
    return 1; // エラーコードを返す
  }

  // ファイルから整数の数を読み取る
  fscanf(file, "%d", &n);

  // ファイルから整数配列を読み取る
  for(i = 0; i < n; i++){
    fscanf(file, "%lf", &A[i]);
    if(A[i] == 2){
      cnt++;
    } else if(A[i] < 2 || (int)A[i] % 2 == 0) {
      continue;
    } else {
      j = 3;
      while(j <= sqrt(A[i])){
        if((int)A[i] % j == 0){
          break;
        }
        j = j + 2;
      }
      if(j > sqrt(A[i])){
        cnt++;
      }
    }
  }

  // ファイルを閉じる
  fclose(file);

  // 素数の数を出力
  printf("%d\n", cnt);

  return 0;
}
