/*
入力
1000001個の整数

出力
中央値
*/
#include <stdio.h>
#include <stdlib.h>
#define N 1000001

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *file;
    int i, n;
    int numbers[1000001];

    file = fopen("A.txt", "r");
    for(i = 0; i < N; i++) {
        fscanf(file, "%d", &numbers[i]);
    }
    fclose(file);

    // ソート
    qsort(numbers, n, sizeof(int), compare);

    // 出力
    if (n % 2 == 1) {
        printf("%d\n", numbers[n / 2]);
    } else {
        int middle1 = numbers[n / 2 - 1];
        int middle2 = numbers[n / 2];
        printf("%d, %d\n", middle1, middle2);
        printf("%f\n", (float)(middle1 + middle2) / 2);
    }

    return 0;
}
