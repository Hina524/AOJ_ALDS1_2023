#include<stdio.h>
#include<stdlib.h>

void Solve(int);

int row[20],column[20],U[20],V[20];
char ans[8][8];

int main(){
	int i,n,y,x;	scanf("%d",&n);
	for(y=0;y<8;y++) for(x=0;x<8;x++)ans[y][x]='.';
	for(i=0;i<n;i++){
		scanf("%d%d",&y,&x);
		ans[y][x]='Q';
		row[y]=column[x]=1;
		U[y+x]=V[y+(7-x)]=1;
	}
	Solve(0);
	return 0;
}

void Solve(int y){
	int x,i,j;
	if(y==8){
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				printf("%c",ans[i][j]);
			}
			printf("\n");
		}

		exit(0);
	}

	if(row[y]==1){
		Solve(y+1);
	}
	for(x=0;x<8;x++){
		if(column[x]==0 && U[y+x]==0 && V[y+(7-x)]==0){
			ans[y][x]='Q';
			column[x]=U[y+x]=V[y+(7-x)]=1;
			Solve(y+1);
			ans[y][x]='.';
			column[x]=U[y+x]=V[y+(7-x)]=0;
		}
	}
}
