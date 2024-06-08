#include <stdio.h>

typedef struct{
  char id;
  int num;
} Card;

Card BubbleSort(int, Card *);
Card SelectionSort(int, Card *);

int main(){
  int i, j, temp, N, cnt, stable = 1;
  Card B[36], S[36];

  scanf("%d", &N);
  for(i=0; i<N; i++){
    scanf(" %c%d", &B[i].id, &B[i].num);
    S[i] = B[i];
  }

  BubbleSort(N, B);
  SelectionSort(N, S);

  for(j=0; j<N-1; j++){
    printf("%c%d ", B[j].id, B[j].num);
  }
  printf("%c%d\nStable\n",B[N-1].id, B[N-1].num);
  for(j=0; j<N-1; j++){
    printf("%c%d ", S[j].id, S[j].num);
  }

  // judge & print Stable
  for(j=0; j<N; j++){
    if(B[j].id!=S[j].id || B[j].num!=S[j].num){
      stable = 0;
    }
  }

  if(stable){
    printf("%c%d\nStable\n", S[N-1].id, S[N-1].num);
  } else {
    printf("%c%d\nNot stable\n", S[N-1].id, S[N-1].num);
  }

  return 0;
}

Card BubbleSort(int N, Card B[]){
  Card temp;
  int i, j, flag;
  i = 0;
  flag = 1;

  while(flag){
    flag = 0;
    for(j = N-1; j>i; j--){
      if(B[j].num < B[j-1].num){
        temp = B[j];
        B[j] = B[j-1];
        B[j-1] = temp;
        flag = 1;
      }
    }
    i++;
  }

  return *B;
}

Card SelectionSort(int N, Card S[]){
  Card temp;
  int i, j, min;
  i = 0;

  for(i=0; i<N-1; i++){
    min = i;
    for(j=i+1; j<N; j++){
      if(S[j].num < S[min].num){
        min = j;
      }
    }
    if(min != i){
      temp = S[i];
      S[i] = S[min];
      S[min] = temp;
    }
  }

  return *S;
}