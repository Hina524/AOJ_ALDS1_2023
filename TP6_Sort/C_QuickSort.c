/*
クイックソート

入力
１行目 カードの枚数n
２行目以降 カードのスートと数字

eg.
3
D 3
H 2
D 1

出力
安定なソートかどうか
ソート後のカードのスートと数字

eg.
Not stable
D 1
H 2
D 3
*/
#include <stdio.h>

typedef struct{
  char suit;
  int value;
  int id;
} Card;

int n, x, p;
Card A[100000];

void swap(Card* a, Card* b);
int Partition(int p, int r);
void QuickSort(int p, int r);

int main(){
  int i;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf(" %c%d",&A[i].suit, &A[i].value);
    A[i].id = i;
  }

  QuickSort(0, n-1);

  for(i=1;i<n;i++){
    if(A[i-1].value==A[i].value && A[i-1].id>A[i].id){
      printf("Not stable\n");
      break;
    }
  }
  if(i==n) printf("Stable\n");

  for(i=0;i<n;i++){
    if(i)printf("\n");
    printf("%c %d",A[i].suit, A[i].value);
  }
  printf("\n");

  return 0;
}

void swap(Card* a,Card* b){
  Card tmp=*a;
  *a=*b;
  *b=tmp;
}

int Partition(int p, int r){
  int x = A[r].value;
  int i = p - 1;
  for(int j=p; j<r; j++){
    if(A[j].value<=x){
      i++;
      swap(&A[j], &A[i]);
    }
  }
  swap(&A[i+1], &A[r]);
  return i+1;
}

void QuickSort(int p, int r){
  if(p<r){
    x = Partition(p, r);
    QuickSort(p, x-1);
    QuickSort(x+1, r);
  }
}