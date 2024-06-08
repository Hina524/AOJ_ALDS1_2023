/*
入力
１行目と２行目に10^6個の整数が”昇順”で書かれたファイル A.txt

出力
１行目と２行目の整数配列の要素が一致する個数
*/
#include <stdio.h>
#define N 10
#define M 10

int binarySearch(int key, int S[], int n);

int main(){
  FILE *file = fopen("A.txt", "r");

  int S[N];
  for (int i = 0; i < N; i++) {
    fscanf(file, "%d", &S[i]); // A.txtの２行目から昇順整数リストSを読み込む
  }

  int T[M];
  for (int i = 0; i < M; i++) {
    fscanf(file, "%d", &T[i]); // A.txtの４行目から整数リストTを読み込む
  }

  fclose(file);

  int cnt = 0;

  // Tに含まれる各整数に対して二分探索を行い、１行目に含まれるものの個数をカウント
  for (int i = 0; i < M; i++) {
    if (binarySearch(T[i], S, N) == 1) cnt++;
  }

  // 結果を出力
  printf("%d\n", cnt);

  return 0;
}

// 二分探索関数
int binarySearch(int key, int S[], int n) {
  int left = 0;
  int right = n;
  while (left < right) {
    int mid = (left + right) / 2;
    if (S[mid] == key) {
      return 1; // キーが見つかった場合は1を返す
    } else if (key < S[mid]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return 0; // キーが見つからない場合は0を返す
}
