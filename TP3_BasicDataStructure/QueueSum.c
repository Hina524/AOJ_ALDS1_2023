/*
読み込み
A.txt
MAX1000個の整数

A.txtの値を一つづつ読み込み、a>0の場合はキューに挿入、a=0の場合はキューから整数を取り出す

出力
popされた値
残りの値の合計
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

typedef struct {
  int array[MAX_SIZE];
  int front;
  int rear;
} Queue;

// キューの初期化
void initializeQueue(Queue *q) {
  q->front = q->rear = -1;
}

// キューへの要素の挿入
void enqueue(Queue *q, int value) {
  if ((q->rear + 1) % MAX_SIZE != q->front) {
    if (q->front == -1) {
      q->front = q->rear = 0;
    } else {
      q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->array[q->rear] = value;
  } else {
    printf("Queue is full!\n");
    exit(1);
  }
}

// キューからの要素の取り出し
int dequeue(Queue *q) {
  int value;
  if (q->front != -1) {
    value = q->array[q->front];
    if (q->front == q->rear) {
      q->front = q->rear = -1;
    } else {
      q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
  } else {
    printf("Queue is empty!\n");
    exit(2);
  }
}

int main(){
  int value;
  // ファイルのオープン
  FILE *file = fopen("A.txt", "r");

  // キューの初期化
  Queue queue;
  initializeQueue(&queue);

  // ファイルから整数を読み取り、処理
  while (fscanf(file, "%d", &value) == 1) {
    if (value > 0) {
      // a > 0 の場合、キューに挿入
      enqueue(&queue, value);
    } else if (value == 0) {
      // a = 0 の場合、キューの先頭から整数を取り出す
      int poppedValue = dequeue(&queue);
      // 出力
      printf("Popped value: %d\n", poppedValue);
    }
  }

  fclose(file);

  // キューに残っている整数の合計を計算
  int sum = 0;
  while (queue.front != -1) {
    sum += dequeue(&queue);
  }

  // 出力
  printf("Sum: %d\n", sum);

  return 0;
}
