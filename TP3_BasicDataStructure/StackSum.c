/*
読み込み
A.txt
MAX1000個の整数

A.txtの値を一つづつ読み込み、a>0の場合はスタックに挿入、a=0の場合はスタックの頂点から整数を取り出す

出力
popされた値
残りの値の合計
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

typedef struct {
  int array[MAX_SIZE];
  int top;
} Stack;

// スタックの初期化
void initializeStack(Stack *s) {
  s->top = -1;
}

// スタックへの要素の挿入
void push(Stack *s, int value){
  if (s->top < MAX_SIZE - 1) s->array[++(s->top)] = value;
}

// スタックからの要素の取り出し
int pop(Stack *s){
  if (s->top >= 0) return s->array[(s->top)--];
}

int main(){
  int value;
  // ファイルのオープン
  FILE *file = fopen("A.txt", "r");

  // スタックの初期化
  Stack stack;
  initializeStack(&stack);

  // ファイルから整数を読み取り、処理
  while (fscanf(file, "%d", &value) == 1){
    if (value > 0) {
      // a > 0 の場合、スタックに挿入
      push(&stack, value);
    } else if (value == 0) {
      // a = 0 の場合、スタックの頂点から整数を取り出す
      int poppedValue = pop(&stack);
    }
  }

  fclose(file);

  // スタックに残っている整数の合計を計算
  int sum = 0;
  while (stack.top >= 0) {
    sum += pop(&stack);
  }

  // 結果の出力
  printf("Sum: %d\n", sum);

  return 0;
}
