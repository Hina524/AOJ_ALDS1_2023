/*
単一始点最短経路1

入力
頂点の数 N
拡張店の隣接リストが与えられる
u k v1 c1 v2 c2 ... vk ck
u: 頂点の番号
k: uの出次数
v1, v2, ..., vk: uから出る辺の先の頂点の番号

出力
v d[v]
v: 頂点の番号
d[v]: 頂点vに到達する最短距離
*/
#include <stdio.h>
#define INF 100000000
#define N 5

// 関数プロトタイプ
void dfs(int, int);

int size[100], to[100][100], cost[100][100], dist[100];

int main() {
    int i, j;

    // ファイルを開く
    FILE *fp = fopen("A.txt", "r");

    // グラフの情報を読み取る
    for (i = 0; i < N; i++) {
        int u;
        fscanf(fp, "%d", &u);
        fscanf(fp, "%d", &size[u]);
        for (j = 0; j < size[u]; j++) {
            fscanf(fp, "%d", &to[u][j]);
            fscanf(fp, "%d", &cost[u][j]);
        }
    }

    // 初期化
    for (i = 0; i < N; i++) dist[i] = INF;

    // 開始点を0としてDFSを実行
    dfs(0, 0);

    // 結果を出力
    for (i = 0; i < N; i++) printf("%d %d\n", i, dist[i]);

    // ファイルを閉じる
    fclose(fp);

    return 0;
}

// 深さ優先探索を再帰的に実行
void dfs(int p, int c) {
    int i;

    // 現在の頂点に到達する最短距離を更新
    dist[p] = c;

    // 隣接する頂点に対してDFSを再帰的に実行
    for (i = 0; i < size[p]; i++) {
        if (dist[to[p][i]] > c + cost[p][i]) {
            dfs(to[p][i], c + cost[p][i]);
        }
    }
}
