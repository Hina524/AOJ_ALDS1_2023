#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAX 362880 //9の階乗
#define N 3
#define N2 9

typedef struct puzzle{
	int f[N2];
	int space;
	int path;
}Puzzle;

static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, -1, 0, 1};

int V[MAX];

Puzzle Q[MAX];
int head, tail;

int empty(){
	return head == tail;
}

void push(Puzzle x){
	Q[tail] = x;
	tail = (tail+1)%MAX;
}

Puzzle front(){
	Puzzle x;
	x = Q[head];
	head = (head+1)%MAX;
	return x;
}

/*
1から9までの数を並び替えた数列をすべて列挙して辞書順に並び替えたとき以下の数列
p.f[8],p.f[7],p.f[6].......p.[0]
が前から何番目にあるかを返す関数
*/
int cheak(Puzzle p){
	int i, j, fac, count, res = 0;
	for(i = 0, fac = 1; i < N2; fac*= ++i){
		for(j = 0, count = 0; j < i; j++){
			if(p.f[j] < p.f[i]) count++;
		}
		res += count*fac;
	}

	return res;
}

int isTarget(Puzzle p){
	int i;
	for(i = 0; i < N2; i++ )
		if(p.f[i] != (i + 1) ) return 0;
	return 1;
}

int bfs(Puzzle s){
	int sx, sy, tx, ty, r, temp;
	Puzzle u, v;

	s.path = 0;

	push(s);

	V[cheak(s)] = 1;

	while(!empty()){
		u = front();
		if( isTarget(u)) return u.path;
		sx = u.space / N;
		sy = u.space % N;

		for ( r = 0; r < 4; r++ ) {
			tx = sx + dx[r];
			ty = sy + dy[r];
			if(tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
			v = u;

			temp = v.f[u.space];
			v.f[u.space] = v.f[tx * N + ty];
			v.f[tx * N + ty] = temp;

			v.space = tx * N + ty;

			if( !V[cheak(v)] ){
				V[cheak(v)] = 1;
				v.path++;
				push(v);
			}
		}
	}

	return -1;
}

int main(){
	int i, ans;
	Puzzle in;

	for( i = 0; i < N2; i++ ) {
		scanf("%d", &in.f[i]);
		if( in.f[i] == 0) {
			in.f[i] = N2;
			in.space = i;
		}
	}

	ans = bfs(in);
	printf("%d\n", ans);

	return 0;
}
