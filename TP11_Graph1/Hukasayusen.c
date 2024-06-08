/*
入力
グラフG=(V,E)の頂点数nと各頂点uの出次数kとその出次数の頂点番号v1,v2,...,vk
１行目：頂点数n
２行目：頂点uの出次数kとその出次数の頂点番号v1,v2,...,vk
→u k v1 v2 ... vk
0<=n<=100

出力
id d f
...
頂点の番号順で出力

id:頂点番号
d:その頂点を最初に発見した発見時刻
f:その頂点の隣接リストを調べ終えた完了時刻
*/
#include<stdio.h>
#define N 4

int MAP[101][101], f[101], d[101], color[101], time;

void visit(int);

int main(){
  FILE *fp;
  int i, j, v, v2, m;

  // ファイルを開く
  fp = fopen("A.txt", "r");

  // 初期化
  for(i = 0; i < N; i++){
    color[i] = 0;
    for(j = 0; j < N; j++)
      MAP[i][j] = 0;
  }

  time = 0;

  // グラフの情報を読み取る
  for(i = 0; i < N; i++){
    fscanf(fp, "%d%d", &v, &m);
    for(j = 0; j < m; j++){
      fscanf(fp, "%d", &v2);
      MAP[v-1][v2-1] = 1;
    }
  }

  // 各頂点に対して未訪問の場合 visit 関数を呼ぶ
  for(i = 0; i < N; i++)
    if(color[i] == 0)
      visit(i);

  // 結果を出力
  for(i = 0; i < N; i++)
    printf("%d %d %d\n", i + 1, d[i], f[i]);

  // ファイルを閉じる
  fclose(fp);

  return 0;
}

void visit(int u){
  int i;
  color[u] = 1;
  d[u] = ++time;
  for(i = 0; i < N; i++){
    if(MAP[u][i] == 1){
      if(color[i] == 0)
        visit(i);
    }
  }
  color[u] = 2;
  f[u] = ++time;
}
