/*
入力
英語小文字のみからなる文字列XとY

出力
最長共通部分列の長さ
*/
#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
  FILE *file;
  char X[MAX + 1], Y[MAX + 1];

  // ファイルを読み込みモードで開く
  file = fopen("A.txt", "r");

  // ファイルが開けなかった場合
  if (file == NULL) {
    printf("File not found or could not be opened.\n");
    return 1; // プログラムをエラーコード1で終了
  }

  // ファイルから文字列Xを読み込む
  fscanf(file, "%s", X);

  // ファイルから文字列Yを読み込む
  fscanf(file, "%s", Y);

  // ファイルを閉じる
  fclose(file);

  int l1 = strlen(X);
  int l2 = strlen(Y);
  int A[MAX + 1][MAX + 1];

  // 2次元配列Aをゼロで初期化
  memset(A, 0, sizeof(A));

  // 動的計画法を使用して、最長共通部分列（LCS）の長さを見つける
  for (int i = 0; i < l1; i++) {
    for (int j = 0; j < l2; j++) {
      // 現在の位置の文字が一致する場合
      if (X[i] == Y[j]) {
        A[i + 1][j + 1] = A[i][j] + 1;
      } else {
        // 文字が一致しない場合、隣接するセルから最大値を取得する
        A[i + 1][j + 1] = (A[i + 1][j] < A[i][j + 1] ? A[i][j + 1] : A[i + 1][j]);
      }
    }
  }

  // 最長共通部分列の長さを出力
  printf("Len %d\n", A[l1][l2]);

  return 0;
}
