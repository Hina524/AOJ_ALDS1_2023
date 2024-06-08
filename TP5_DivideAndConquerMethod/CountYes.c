/*
入力
２行目 A1, A2, ..., An（N個）
３行目 q
４行目 M1, M2, ..., Mq

出力
Aを足しあわせて500が作れるかどうか
作れるならyes, 作れないならno
*/
#include <stdio.h>

#define N 12

int solve(int i, int m, int A[], int n);

int main() {
    FILE *file = fopen("A.txt", "r");

    int A[N];
    for (int i = 0; i < N; i++) {
        fscanf(file, "%d", &A[i]);
    }

    fclose(file);

    int M = 500; // 作りたい合計値

    // solve関数を呼び出してMを作る方法の数を計算
    int ways = solve(0, M, A, N);

    // 結果を出力
    printf("Mを作る方法の数: %d\n", ways);

    return 0;
}

// 作りたい合計値を作る方法の数を再帰的に計算する関数
int solve(int i, int m, int A[], int n) {
    int sum = 0;
    if (m == 0) return 1;
    if (i >= n) return 0;
    else {
        sum += solve(i + 1, m, A, n);       // i番目の要素を使わない場合
        sum += solve(i + 1, m - A[i], A, n); // i番目の要素を使う場合
    }
    return sum;
}
