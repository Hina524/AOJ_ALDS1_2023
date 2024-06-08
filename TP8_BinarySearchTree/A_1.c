/*
二分探索技

入力
１行目 命令の数n
２行目以降 命令
  ・insert k
  Tにkを挿入する
  ・print

出力
１行目 中間順巡回Inorder
２行目 先行順巡回Preorder
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
  int key;
  struct node *par;
  struct node *r;
  struct node *l;
};

typedef struct node *Node;
Node T;

void Insert(int);
void Preorder(Node);
void Inorder(Node);

int main(){
  int n,i,key;
  char com[7];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s",com);
    if(com[0]=='i'){
      scanf("%d",&key);
      Insert(key);
    }else{
      Inorder(T);
      printf("\n");
      Preorder(T);
      printf("\n");
    }
  }
  return 0;
}

void Insert(int key){
  Node y,x,z;
  y=NULL;
  x=T;
  z=malloc(sizeof(struct node));
  z->key=key;
  z->l=NULL;
  z->r=NULL;

  while(x!=NULL){
    y=x;
    if( z->key < x->key )x=x->l;
    else x=x->r;
  }

  z->par=y;

  if(y==NULL){
    T=z;
  } else if(z->key<y->key){
    y->l=z;
  } else {
    y->r=z;
  }
}

void Preorder(Node T){
  printf(" %d",T->key);
  if(T->l!=NULL) Preorder(T->l);
  if(T->r!=NULL) Preorder(T->r);
}

void Inorder(Node T){
  if(T->l!=NULL && T->r!=NULL){
    Inorder(T->l);
    printf(" %d",T->key);
    Inorder(T->r);
  }
  if(T->l!=NULL && T->r==NULL){
    Inorder(T->l);
    printf(" %d",T->key);
  }

  if(T->r!=NULL && T->l==NULL){
    printf(" %d",T->key);
    Inorder(T->r);
  }
  if(T->l==NULL && T->r==NULL)printf(" %d",T->key);
}
