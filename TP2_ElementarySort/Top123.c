/*
入力
空白区切りの1000個の整数が書かれたファイル A.txt

出力
ファイルの中で最も大きい3つの整数
*/
#include <stdio.h>
#include <stdlib.h>
#define N 1000

int compare(const void *a, const void *b) {
  return (*(int*)b - *(int*)a);
}

int main() {
  FILE *file;
  int i, n;
  int numbers[10];

  file = fopen("A.txt", "r");
  for(i = 0; i < N; i++) {
    fscanf(file, "%d", &numbers[i]);
  }
  fclose(file);

  // 降順ソート
  qsort(numbers, n, sizeof(int), compare);

  // 出力
  printf("1: %d\n", numbers[0]);
  printf("2: %d\n", numbers[1]);
  printf("3: %d\n", numbers[2]);

  return 0;
}