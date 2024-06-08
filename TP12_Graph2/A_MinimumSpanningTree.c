/*
最小全域木

入力
N 行に隣接行列が与えられる。
i 行目の j 列目には辺 (i, j) のコストが与えられる。
辺が存在しない場合は -1 が与えられる。

出力
最小全域木の重み
*/
#include <stdio.h>
#include <limits.h>
#define N 5

#define INF INT_MAX/2

// 関数プロトタイプ
int prim(int, int[100][100]);

int main() {
    int i, j, a[100][100];

    // ファイルを開く
    FILE *fp = fopen("A.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "ファイルを開けませんでした\n");
        return 1;
    }

    // 隣接行列を読み取る
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            fscanf(fp, "%d", &a[i][j]);
        }
    }

    // ファイルを閉じる
    fclose(fp);

    // Prim's アルゴリズムを実行し、最小全域木の重みを出力
    printf("%d\n", prim(N, a));

    return 0;
}

// Prim's アルゴリズムを実行する関数
int prim(int n, int a[100][100]) {
    int i, v, cost[100], used[100], res = 0;

    // 各頂点のコストと使用状態を初期化
    for (i = 0; i < n; i++) {
        cost[i] = INF;
        used[i] = 0;
    }

    // 開始点を0とし、最小全域木を構築
    cost[0] = 0;
    while (1) {
        v = -1;

        // 未使用かつ最小のコストを持つ頂点を選択
        for (i = 0; i < n; i++) {
            if (!used[i] && (v == -1 || cost[i] < cost[v])) {
                v = i;
            }
        }

        // 全ての頂点が使用済みの場合、終了
        if (v == -1) {
            break;
        }

        used[v] = 1;  // 頂点を使用済みとマーク
        res += cost[v];  // 選択された辺のコストを加算

        // 未使用の頂点への辺が最小コストなら更新
        for (i = 0; i < n; i++) {
            if (a[v][i] == -1) {
                continue;  // 辺が存在しない場合はスキップ
            }
            cost[i] = cost[i] < a[v][i] ? cost[i] : a[v][i];
        }
    }

    return res;
}
