/*
入力
整数 n (0 ≤ n ≤ 6)

出力
コッホ曲線の各頂点の座標
*/
#include <stdio.h>
#include <math.h>

int n;

typedef struct{
  double x;
  double y;
}P;

void kock(int, P, P);

int main(){
  P p1, p2;
  p1.x = p1.y = p2.y = 0;
  p2.x = 100;

  scanf("%d",&n);

  printf("%lf %lf\n", p1.x, p1.y);
  kock(n, p1, p2);
  printf("%lf %lf\n", p2.x, p2.y);

  return 0;
}

void kock(int n, P p1, P p2){
  P s, t, u;
  if(n==0) return;
  s.x = (2 * p1.x + p2.x) / 3;
  s.y = (2 * p1.y + p2.y) / 3;
  t.x = (p1.x + 2 * p2.x) / 3;
  t.y = (p1.y + 2 * p2.y) / 3;
  u.x = (t.x - s.x) * cos(M_PI / 3) - (t.y - s.y) * sin(M_PI / 3) + s.x;
  u.y = (t.x - s.x) * sin(M_PI / 3) + (t.y - s.y) * cos(M_PI / 3) + s.y;
  kock(n-1, p1, s);
  printf("%lf %lf\n", s.x, s.y);
  kock(n-1, s, u);
  printf("%lf %lf\n", u.x, u.y);
  kock(n-1, u, t);
  printf("%lf %lf\n", t.x, t.y);
  kock(n-1, t, p2);
}