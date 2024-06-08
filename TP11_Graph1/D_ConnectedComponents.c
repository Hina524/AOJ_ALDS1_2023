#include<stdio.h>
#include<stdlib.h>

void connect(int, int);
void dfs_visit(int, int);
void dfs(void);

struct node{
  int id;
  struct node *next;
} *friend_ls[100000];

int n, m;
int group[100000] = {0};

int main( void ){
  scanf( "%d %d", &n, &m );
  for( int i = 0; i < n; i++ ) friend_ls[i] = NULL;

  int u, v;
  for( int i = 0; i < m; i++ ){
    scanf( "%d %d", &u, &v );
    connect( u, v );
  }

  dfs();

  int q;
  scanf( "%d", &q );
  while( q-- > 0 ){
    scanf( "%d %d", &u, &v );
    if( group[u] == group[v] ) printf( "yes\n" );
    else printf( "no\n" );
  }

  return 0;
}

void connect(int u, int v){
  struct node *new_u = ( struct node * )malloc( sizeof( struct node ) );
  struct node *new_v = ( struct node * )malloc( sizeof( struct node ) );
  new_u->id = u;
  new_v->id = v;

  new_u->next = friend_ls[v];
  new_v->next = friend_ls[u];
  friend_ls[u] = new_v;
  friend_ls[v] = new_u;
}

void dfs_visit( int u, int color ){
  group[u] = color;
  struct node *p = friend_ls[u];
  while(p != NULL){
    if( group[p->id] == 0 ) dfs_visit( p->id, color );
    p = p->next;
  }
}

void dfs( void ){
  int color = 1;
  for( int i = 0; i < n; i++ ){
    if( group[i] == 0 ) dfs_visit( i, color++ );
  }
}