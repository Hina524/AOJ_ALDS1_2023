/*
入力
グラフG=(V,E)の頂点数nと各頂点uの出次数kとその出次数の頂点番号v1,v2,...,vk
２行目：頂点uの出次数kとその出次数の頂点番号v1,v2,...,vk
→u k v1 v2 ... vk
頂点の数N！!!

出力
グラフGの隣接行列
*/
#include <stdio.h>
#define N 4

int main() {
  FILE *fp;
  int  A[101][101];
  int i, j, k, u, a;

  // ファイルを開く
  fp = fopen("A.txt", "r");

  // 隣接行列を初期化
  for (i = 0; i < N + 1; i++)
    for (j = 0; j < N + 1; j++) {
      A[i][j] = 0;
    }

  // グラフの情報を読み取る
  for (i = 0; i < N; i++) {
    fscanf(fp, "%d %d", &k, &u);
    for (j = 0; j < u; j++) {
      fscanf(fp, "%d", &a);
      A[k - 1][a - 1] = 1;
    }
  }

  // 隣接行列を出力
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%d", A[i][j]);
      if (j != N - 1)
        printf(" ");
    }
    printf("\n");
  }

  // ファイルを閉じる
  fclose(fp);

  return 0;
}