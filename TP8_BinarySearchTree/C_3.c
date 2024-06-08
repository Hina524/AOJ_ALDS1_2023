/*
二分探索技

入力
１行目 命令の数n
２行目以降 命令
  ・insert k
  Tにkを挿入する
  ・find k
  Tにkが存在するかを出力(yes or no)
  ・delete k
  Tからkを削除する
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
  struct node *ch;
  struct node *r;
  struct node *l;
};

typedef struct node *Node;
Node root;

void Insert(int);
int Find(int);
void Delete(int);
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
    }else if(com[0]=='f'){
      scanf("%d",&key);
      if(Find(key)==1)printf("yes\n");
      else printf("no\n");
    }else{
      Inorder(root);
      printf("\n");
      Preorder(root);
      printf("\n");
    }
  }
  return 0;
}

void Insert(int key){
  Node y,x,z;
  y=NULL;
  x=root;
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
    root=z;
  } else if(z->key<y->key){
    y->l=z;
  } else {
    y->r=z;
  }
}

int Find(int key){
  Node now = root;

  while(now) {
    if(now->key == key) return 1;
    else if(now->key > key) now = now->l;
    else now = now->r;
  }
  return 0;
}

void Delete(int key){
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