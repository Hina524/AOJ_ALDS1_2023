/*
データセットの数q
１行目：文字列X
２行目：文字列Y
英語小文字

出力
最長共通部分列の長さ
*/
#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
  int N, i, j, l1, l2, A[MAX + 1][MAX + 1];
  char X[MAX + 1], Y[MAX + 1];

  // テストケースの数を入力
  scanf("%d", &N);

  // 各テストケースに対して繰り返し処理
  while (N--) {
    // 二つの文字列XとYを入力
    scanf("%s %s", X, Y);

    // 入力文字列の長さを取得
    l1 = strlen(X);
    l2 = strlen(Y);

    // 2次元配列Aをゼロで初期化
    memset(A, 0, sizeof(A));

    // 動的計画法を使用して、最長共通部分列（LCS）の長さを見つける
    for (i = 0; i < l1; i++) {
      for (j = 0; j < l2; j++) {
        // 現在の位置の文字が一致する場合
        if (X[i] == Y[j]) {
          A[i + 1][j + 1] = A[i][j] + 1;
        } else {
          // 文字が一致しない場合、隣接するセルから最大値を取得する
          A[i + 1][j + 1] = (A[i + 1][j] < A[i][j + 1] ? A[i][j + 1] : A[i + 1][j]);
        }
      }
    }

    // 現在のテストケースにおける最長共通部分列の長さを出力
    printf("%d\n", A[l1][l2]);
  }

  return 0;
}
