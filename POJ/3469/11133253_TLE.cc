/*
ID: dd.ener1
PROG: ditch
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=20010,OO=1000000000;
struct edge{
	int x,y;//Á½¸ö¶¥µã 
	int w;//ÈÝÁ¿ 
	int f;
	edge *next,*back;
	edge(){}
	edge(int x,int y,int w,edge* next):x(x),y(y),w(w),f(0),next(next),back(0){}
	void* operator new(size_t, void* p){
		return p;
	}
}*E[maxn],*cur[maxn];

int H[maxn];//¸ß¶Èº¯Êý
int P[maxn];//preflow
int N,S,T;
template <class T>
const T& min(const T& a,const T& b){
	return a<b?a:b;
}
void push(edge* e){
	int u=e->x,v=e->y;
	int delta=min(P[u],e->w);
	e->w -= delta;
	e->back->w += delta;
	e->f += delta;
	e->back->f = -(e->f);
	P[u]-=delta;
	P[v]+=delta;
}
void relabel(int u){
	int minlabel=OO;
	for(edge* e=E[u];e;e=e->next){
		if(e->w==0)continue;
		int v=e->y;
		if(H[v]<minlabel){
			minlabel=H[v];
			cur[u]=e;
		}
	}
	H[u]=minlabel+1;
}
void discharge(int u){
	while(P[u]>0){
		if(!cur[u]){
			relabel(u);
		}
		int v=cur[u]->y;
		if(cur[u]->w >0 && H[u]==H[v]+1)
			push(cur[u]);
		cur[u]=cur[u]->next;
	}
}
void init_preflow(){
	memset(H,0,sizeof(H));
	memset(P,0,sizeof(P));
	H[S]=N;
	P[S]=OO;
	for(edge* e=E[S];e;e=e->next)
		push(e);
}
struct vertex{
	int x;
	vertex* next;
	vertex(int x,vertex* next):x(x),next(next){}
	vertex(){}
	void* operator new(size_t, void* p){
		return p;
	}
};
vertex* build_list(){
	vertex* data=new vertex[N-2];
	vertex* L=0;
	for(int i=N;i>=1;--i)
		if(i!=S&&i!=T)
			L=new((void*)data++) vertex(i,L);
	return L;
}
int maxflow(){
	memcpy(cur,E,sizeof(E));
	init_preflow();
	vertex* L=build_list();//list
	vertex *v=L,*pre=0;
	while(v){
		int old_height=H[v->x];
		discharge(v->x);
		if(H[v->x]>old_height){
			if(pre){
				pre->next = v->next;
				v->next = L;
				L = v;
			}
			else;//±¾À´¾ÍÔÚ±íÍ· 
		}
		pre = v;
		v = v->next;
	}
	return P[T];
}
int main ()
{
	int m;
	while(scanf("%d%d",&N,&m)!=-1)
	{
		memset(E,0,sizeof(E));
		edge* data=new edge[2*m+4*N];
		S=N+1; T=N+2;
		for(int i=1;i<=N;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			E[S]=new((void*)data++) edge(S,i,x,E[S]);
			E[i]=new((void*)data++) edge(i,S,0,E[i]);
			E[S]->back = E[i];
			E[i]->back = E[S];
			E[i]=new((void*)data++) edge(i,T,y,E[i]);
			E[T]=new((void*)data++) edge(T,i,0,E[T]);
			E[i]->back = E[T];
			E[T]->back = E[i];
		}
		while(m--){
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);
			E[x]=new((void*)data++) edge(x,y,w,E[x]);
			E[y]=new((void*)data++) edge(y,x,w,E[y]);
			E[x]->back = E[y];
			E[y]->back = E[x];
		}
		printf("%d\n",maxflow());
	}
	
	return 0;
}