/*
入力
有向グラフG=(V,E)の頂点数nと各頂点uの出次数kとその出次数の頂点番号v1,v2,...,vk
１行目：頂点数n
２行目：頂点uの出次数kとその出次数の頂点番号v1,v2,...,vk
→u k v1 v2 ... vk
0<=n<=100

出力
i d[i]
...

i:頂点番号
d[i]:頂点1からその頂点までの距離
頂点iに到達不可能な場合は-1
*/
#include<stdio.h>

// グローバル変数
int map[101][101], Q[101], n, head=0, tail=0, color[101], d[101];

// 関数プロトタイプ
void visit(int);
void enqueue(int);
int dequeue(void);

int main(){
  int i, j, v, v2, m, u, k;

  // 頂点の数を入力
  scanf("%d", &n);

  // 初期化
  for(i = 0; i < n; i++){
    color[i] = 0;
    for(j = 0; j < n; j++)
      map[i][j] = 0;
  }

  // グラフの情報を入力
  for(i = 0; i < n; i++){
    scanf("%d%d", &v, &m);
    for(j = 0; j < m; j++){
      scanf("%d", &v2);
      map[v-1][v2-1] = 1;  // 隣接行列の更新
    }
  }

  // 幅優先探索（BFS）の開始
  for(j = 0; j < n; j++){
    if(map[0][j] == 1)
      color[j] = 0;
  }
  color[0] = 1;
  d[0] = 0;
  enqueue(0);

  while(head != tail){
    u = dequeue();

    for(k = 0; k < n; k++){
      if(map[u][k] == 1 && color[k] == 0){
        color[k] = 1;
        d[k] = d[u] + 1;
        enqueue(k);
      }
      color[u] = 2;
    }
  }

  // 結果の出力
  for(i = 0; i < n; i++){
    if(color[i] == 2)
      printf("%d %d\n", i + 1, d[i]);  // 各頂点とその最短距離を出力
    else
      printf("%d -1\n", i + 1);  // 頂点に到達不可能な場合は-1を出力
  }

  return 0;
}

// キューに要素を追加する関数
void enqueue(int x){
  Q[tail] = x;
  if(tail + 1 == 100)
    tail = 0;
  else
    tail = tail + 1;
}

// キューから要素を取り出す関数
int dequeue(){
  int x;
  x = Q[head];

  if(head + 1 == 100)
    head = 0;
  else
    head = head + 1;

  return x;
}
