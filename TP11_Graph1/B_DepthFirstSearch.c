/*
入力
グラフG=(V,E)の頂点数nと各頂点uの出次数kとその出次数の頂点番号v1,v2,...,vk
１行目：頂点数n
２行目：頂点uの出次数kとその出次数の頂点番号v1,v2,...,vk
→u k v1 v2 ... vk
0<=n<=100

出力
id d f
...
頂点の番号順で出力

id:頂点番号
d:その頂点を最初に発見した発見時刻
f:その頂点の隣接リストを調べ終えた完了時刻
*/
#include<stdio.h>

int MAP[101][101], f[101], d[101], color[101], time, n;

void visit(int);

int main(){
  int i, j, v, v2, m;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    color[i]=0;
    for(j=0;j<n;j++)  MAP[i][j]=0;
  }
  time=0;
  for(i=0;i<n;i++){
    scanf("%d%d",&v,&m);
    for(j=0;j<m;j++){
      scanf("%d",&v2);
      MAP[v-1][v2-1]=1;
    }
  }
  for(i=0;i<n;i++) if(color[i]==0) visit(i);
  for(i=0;i<n;i++) printf("%d %d %d\n",i+1,d[i],f[i]);

  return 0;
}

void visit(int u){
  int i;
  color[u]=1;
  d[u]=++time;
  for(i=0;i<n;i++){
    if(MAP[u][i]==1){
      if(color[i]==0)visit(i);
    }
  }
  color[u]=2;
  f[u]=++time;
}
