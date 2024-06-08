/*
入力
１行目と２行目に10^6個の整数が書かれたファイル A.txt

出力
１行目と２行目の整数配列の要素が一致する個数
*/
#include <stdio.h>
#define MAX_SIZE 1000000
#define N 1000000
#define M 1000000

int linearSearch(int[], int);

int main() {
  int i, cnt, S[MAX_SIZE], T[MAX_SIZE];
  cnt = 0;

  // ファイルを読み取りモードで開く
  FILE *file = fopen("A.txt", "r");

  // ファイルから配列Sの要素を読み取る
  for (i = 0; i < N; i++) {
    fscanf(file, "%d", &S[i]);
  }

  // ファイルから配列Tの要素を読み取る
  for (i = 0; i < M; i++) {
    fscanf(file, "%d", &T[i]);
  }

  // 読み取り後にファイルを閉じる
  fclose(file);

  // 配列Tの各要素に対して線形探索を行う
  for (i = 0; i < M; i++) {
    // linearSearch関数を呼び出して、要素が配列Sに存在するか確認
    if (linearSearch(S, T[i]) == 1) {
      cnt++; // 要素が見つかればカウンタをインクリメント
    }
  }

  // 一致する要素の最終的なカウントを表示
  printf("%d\n", cnt);

  return 0;
}

// 配列A内で指定されたキーを線形探索する関数
int linearSearch(int A[], int key) {
  int i = 0;
  A[N] = key; // 境界チェックのために、Aの末尾にキーを追加

  // キーが見つかるか、末尾に到達するまでAをイテレート
  while (A[i] != key) {
    i++;
    if (i == N) {
      return 0; // キーがA内に見つからない場合は0を返す
    }
  }

  return 1; // キーがA内に見つかった場合は1を返す
}
