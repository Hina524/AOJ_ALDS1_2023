#include <stdio.h>
#include <stdlib.h>
#define LEN 100005

typedef struct{
  char name[100];
  int t;
}P;

P Q[LEN+1];
int head, tail, n;

void initialize(void);
void enqueue(P);
P dequeue(void);

int main(){
  int laps = 0;
  int i, q;
  P u;

  initialize();

  scanf("%d %d", &n, &q);

  for ( i = 1; i <= n; i++){
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].t);
    enqueue(Q[i]);
  }

  while(head != tail){
    u = dequeue();
    if(u.t > q){
      u.t -= q;
      laps += q;
      enqueue(u);
    } else {
      laps += u.t;
      printf("%s %d\n", u.name, laps);
    }
  }

  return 0;
}

void initialize(void){
  head = tail = 0;
}

void enqueue(P x){
  if(head == (tail + 1)%LEN){
    printf("queue is full!");
    exit(1);
  }
  Q[tail] = x;
  if(tail + 1 ==LEN){
    tail = 0;
  } else {
    tail++;
  }
}

P dequeue(){
  if(head == tail){
    printf("queue is empty!");
    exit(2);
  }
  P x = Q[head];
  if(head + 1 == LEN){
    head = 0;
  } else {
    head++;
  }
  return x;
}