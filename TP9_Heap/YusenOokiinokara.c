/*
入力
10^6の整数を含むファイルA.txt
”大きいもの”から取り出す優先度付きキュー

0より大きい時は挿入
0の時はPから一つ取り出し

取り出された要素の合計値を出力
*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 1000000

int H;  // ヒープのサイズ
int heap[MAX_HEAP_SIZE];

// 関数プロトタイプ
void maxHeapify(int *A, int i);
void heapIncreaseKey(int *A, int i, int val);
void maxHeapInsert(int *A, int val);
int heapExtractMax(int *A);

int main() {
    FILE *fp;
    int val, sum = 0;

    // ファイルを開く
    fp = fopen("A.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "ファイルを開けませんでした\n");
        return 1;
    }

    H = 0;  // ヒープの初期サイズ

    while (fscanf(fp, "%d", &val) != EOF) {
        if (val > 0) {
            // 0より大きい場合は挿入
            maxHeapInsert(heap, val);
        } else if (val == 0) {
            // 0の場合はPから一つ取り出し
            int extracted = heapExtractMax(heap);
            if (extracted != -1) {
                sum += extracted;
            }
        }
    }

    // ファイルを閉じる
    fclose(fp);

    printf("合計値: %d\n", sum);

    return 0;
}

void maxHeapify(int *A, int i) {
    int l = i * 2 + 1, r = i * 2 + 2;
    int largest;

    if (l < H && A[l] > A[i]) {
        largest = l;
    } else {
        largest = i;
    }

    if (r < H && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        maxHeapify(A, largest);
    }
}

void heapIncreaseKey(int *A, int i, int val) {
    if (val < A[i]) {
        return;
    }

    A[i] = val;

    while (i > 0 && A[(i - 1) / 2] < A[i]) {
        int tmp = A[i];
        A[i] = A[(i - 1) / 2];
        A[(i - 1) / 2] = tmp;
        i = (i - 1) / 2;
    }
}

void maxHeapInsert(int *A, int val) {
    H++;
    A[H - 1] = INT_MIN;
    heapIncreaseKey(A, H - 1, val);
}

int heapExtractMax(int *A) {
    int max;

    if (H < 1) {
        return -1;
    }

    max = A[0];
    A[0] = A[H - 1];
    H--;
    maxHeapify(A, 0);

    return max;
}
