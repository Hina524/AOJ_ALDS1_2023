/*
入力
１行目 データ数 n
続くn行に以下のコマンドが入力される
insert str
find str
strは長さが12以下の英大文字のみからなる文字列

出力
findコマンドに対してyesかnoを出力する
*/
#include <stdio.h>
#include <string.h>
#define M 1000010
#define L 14

char H[M][L];

int getChar(char);
long long getKey(char[]);
int h1(int);
int h2(int);
int find(char[]);
void insert(char[]);

int main(){
  int i, n, h, a = 0;
  char str[L], com[9], ans[1000000][12];
  char Y[4] = {"yes"};
  char N[3] = {"no"};
  for ( i = 0; i < M; i++ ) H[i][0] = '\0';

  scanf("%d", &n);

  for ( i = 0; i < n; i++ ){
    scanf("%s %s", com, str);

    if ( com[0] == 'i' ){
      insert(str);
    } else {
      if (find(str)){
        strcpy(ans[a],Y);
        a++;
      } else {
        strcpy(ans[a],N);
        a++;
      }
    }
  }

  for(i=0; i<a; i++){
    printf("%s\n",ans[i]);
  }
  return 0;
}

int getChar(char ch){
  if ( ch == 'A') return 1;
  else if ( ch == 'C') return 2;
  else if ( ch == 'G') return 3;
  else if ( ch == 'T') return 4;
  else return 0;
}

/* convert a string into an integer value */
long long getKey(char str[]){
  long long sum = 0, p = 1, i;
  for ( i = 0; i < strlen(str); i++ ){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key){
  return key%M;
}

int h2(int key){
  return 1+key%(M-1);
}

// hash method(open-address method)
int find(char str[]){
  int i=0,k,n=0,sum;
  sum=getKey(str);
  while(i<M){
    k=(h1(sum)+i*h2(sum))%M;
    if(H[k][0]=='\0'){ // hash tableが空=>見つからなかった
      break;
    }
    if(strcmp(H[k],str)==0){
      n=1;
      break;
    }
    i++; //hash衝突したらこれでほかの値を試す
  }
  return n;
}

void insert(char str[]){
  int sum,i=0,k;
  sum=getKey(str);
  while(i<M){
    k=(h1(sum)+i*h2(sum))%M;
    if(H[k][0]=='\0'){
      strcpy(H[k],str);
      break;
    }
    i++;
  }
}