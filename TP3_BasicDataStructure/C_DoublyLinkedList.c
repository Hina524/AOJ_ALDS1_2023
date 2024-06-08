#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
  unsigned int key;
  struct node *next;
  struct node *prev;
};

typedef struct node * NodePointer;

NodePointer nil;

NodePointer listSearch(int);
void init(void);
void printList(void);
void deleteNode(NodePointer);
void deleteFirst(void);
void deleteLast(void);
void delete(int);
void insert(int);

int main(){
  int key, n, i;
  int size = 0;
  char com[20];
  int np = 0, nd = 0;
  scanf("%d", &n);
  init();
  for ( i = 0; i < n; i++ ){
    scanf("%s", com);
    if ( com[0] == 'i' ) {
      scanf("%d",&key);
      insert(key);
      np++;
      size++;
    } else if ( com[0] == 'd' ) {
      if (strlen(com) > 6){
        if ( com[6] == 'F' ) deleteFirst();
        else if ( com[6] == 'L' ) deleteLast();
      } else {
        scanf("%d",&key);
        delete(key);
        nd++;
      }
      size--;
    }
  }

  printList();
  return 0;
}

NodePointer listSearch(int key){
  NodePointer cur=nil->next;
  while(1){
    if(cur==nil)return cur;
    if(cur->key==key)return cur;
    cur=cur->next;
  }
}

void init(){
  nil = malloc(sizeof(struct node));
  nil->next = nil;
  nil->prev = nil;
}

void printList(){
  NodePointer cur = nil->next;
  int isf = 1;
  while(1){
    if ( cur == nil ) break;
    if ( isf == 0)  printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
    isf = 0;
  }
  printf("\n");
}

void deleteNode(NodePointer t){
  NodePointer cur ,prev;
  if(t!=nil){
        cur=t->next;
	prev=t->prev;
	prev->next=cur;
	cur->prev=prev;
	if(t->next==nil){
		nil->prev=prev;
		prev->next=nil;
	}
	free(t);
  }
}

void deleteFirst(){
  NodePointer t = nil->next;
  if ( t == nil ) return;
  deleteNode(t);
}

void deleteLast(){
  NodePointer cur=nil->prev;
  if(cur==nil) return;
  deleteNode(cur);
}

void delete(int key){
  NodePointer t;
  t=listSearch(key);
  if(t==nil)return ;
  deleteNode(t);
}


void insert(int key){
  NodePointer x;
  x = malloc(sizeof(struct node));
  x->key = key;
  if(nil->next==nil){
    nil->prev=x;
  }
  x->next=nil->next;
  x->prev=nil;
  nil->next->prev=x;
  nil->next=x;
}