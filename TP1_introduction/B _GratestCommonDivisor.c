/*
最大公約数

入力
２つの整数 x, y (1 ≤ x, y ≤ 10^9)

出力
x と y の最大公約数
*/
#include <stdio.h>

int GCD(int, int);

int main(){
  int x, y;

  scanf("%d %d",&x, &y);
  printf("%d\n",GCD(x,y));

  return 0;
}

int GCD(int x, int y){
  int temp;
  if(x < y){
    temp = x;
    x = y;
    y = temp;
    while(y > 0){
      temp = x % y;
      x = y;
      y = temp;
    }
  } else {
    while(y > 0){
      temp = x % y;
      x = y;
      y = temp;
    }
  }
  return x;
}