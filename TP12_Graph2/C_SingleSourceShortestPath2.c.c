#include<stdio.h>
#include<stdlib.h>
#define N 1000000
#define INF 5000000

typedef struct node* NodePointer;

struct node{
  int id;
  int w;
  NodePointer next;
};

struct heap{
  int id;
  int d;
};

NodePointer g[N];
int d[N], color[N], size=0;
struct heap H[N];

NodePointer make_list(void);
void delete_list(NodePointer);
void clear_list(NodePointer);
void add_list(NodePointer,int,int);
NodePointer search(NodePointer);
void dicu(int);
void inq(struct heap);
struct heap deq(void);
void upk(struct heap);
void heap(struct heap);
void swap(struct heap*,struct heap*);
void minheap(int);


int main(){
  int n,i,j,k;
  int id,c,v;
  scanf("%d", &n);

  for(i=0;i<n;i++) g[i] = make_list();

  for(i=0;i<n;i++){
    scanf("%d %d",&id, &k);
    for(j=0;j<k;j++){
      scanf("%d %d", &v, &c);
      add_list(g[id],v,c);
    }
  }

  for(i=0;i<n;i++){
    color[i] = 0;
    d[i] = INF;
  }

  dicu(0);

  for(i=0;i<n;i++) printf("%d %d\n", i, d[i]);
  for(i=0;i<n;i++) delete_list(g[i]);

  return 0;
}

NodePointer make_list(){
  NodePointer head;
  head = (NodePointer)malloc(sizeof(struct node));
  head->id = 0;
  head->next = NULL;
  return head;
}

void delete_list(NodePointer g){
  clear_list(g);
  free(g);
}

void clear_list(NodePointer g){
  NodePointer p,prev;
  p = g->next;
  prev = g;
  while(p!=NULL){
    prev->next = p->next;
    free(p);
    p = prev->next;
  }
}

void add_list(NodePointer g, int id, int c){
  NodePointer tail = search(g);
  NodePointer new = (NodePointer)malloc(sizeof(struct node));
  new->id = id;
  new->w = c;
  new->next = NULL;
  tail->next = new;
}

NodePointer search(NodePointer g){
  NodePointer p = g;
  while(p->next!=NULL) p = p->next;

  return p;
}


void inq(struct heap h){
  size++;
  H[size].d = -1 * INF;
  upk(h);
}

void upk(struct heap h){
  int i;
  i = size;
  H[i] = h;
  while(i>1 && H[i/2].d>H[i].d){
    swap(&H[i],&H[i/2]);
    i = i/2;
  }
}

void swap(struct heap *a, struct heap *b){
  struct heap tmp;
  tmp = *a;
  *a = *b;
  *b =tmp;
}

struct heap deq(){
  struct heap min;
  min = H[1];
  H[1] = H[size];
  size--;
  minheap(1);

  return min;
}

void minheap(int i){
  int l,r,sm;
  l = 2*i;
  r = 2*i + 1;
  if(l<=size && H[l].d<H[i].d) sm = l;
  else sm = i;
  if(r<=size && H[r].d<H[sm].d) sm = r;
  if(sm!=i){
    swap(&H[i], &H[sm]);
    minheap(sm);
  }
}

void dicu(int s){
  struct heap h, u;
  NodePointer i;
  d[s] = 0;
  h.id = s;
  h.d = 0;
  inq(h);

  while(size!=0){
    u = deq();
    color[u.id] = 2;
    if(d[u.id] < u.d)continue;
    for(i=g[u.id]->next; i!=NULL; i=i->next){
      if(color[i->id] != 2){
        if(d[u.id]+(i->w) < d[i->id]){
          d[i->id] = d[u.id] + (i->w);
          color[i->id] = 1;
          h.id = i->id;
          h.d = d[i->id];
          inq(h);
        }
      }
    }
  }
}

