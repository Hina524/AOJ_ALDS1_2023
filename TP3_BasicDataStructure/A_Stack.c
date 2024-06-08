#include <stdio.h>
#include <stdlib.h>
#define MAX 200

void initialize(void);
void push(int);
int pop(void);

int top, s[MAX];

int main(){
  int x, num1, num2;
  char data[100];

  initialize();

  while( scanf(" %s", data) != EOF ){
    if ( data[0] == '+' ){
      num1 = pop();
      num2 = pop();
      push(num1 + num2);
    } else if ( data[0] == '-' ){
      num1 = pop();
      num2 = pop();
      push(num2 - num1);
    } else if ( data[0] == '*' ){
      num1 = pop();
      num2 = pop();
      push(num1 * num2);
    } else {
      x = atoi(data);
      push(x);
    }
  }
  printf("%d\n",s[top]);

  return 0;
}

void initialize(void){
  top = 0;
}

void push(int x){
  if(top >= MAX-1){
    printf("stack is full!");
    exit(1);
  }
  top++;
  s[top] = x;
}

int pop(void){
  if(top == 0){
    printf("stack is Empty!");
    exit(2);
  }
  top--;
  return s[top+1];
}