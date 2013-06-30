#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 10010
#define INF (1<<30)
struct node
{
	int key,mx,dep;
	node *p,*ch[2];
}nodes[N],*cur,*null;
inline void init()
{
	null=nodes;
	null->p=null->ch[0]=null->ch[1]=null;
	null->key=null->mx=-INF;
	cur=nodes+1;
}
inline node *newnode()
{
	cur->p=cur->ch[0]=cur->ch[1]=null;
	cur->key=cur->mx=-INF;
	return cur++;
}
struct dynamictree
{
	inline bool isroot(node *x)
	{
		return x==null || x->p->ch[0]!=x && x->p->ch[1]!=x;
	}
	inline void pushup(node *x)
	{
		x->mx=max(x->key,max(x->ch[0]->mx,x->ch[1]->mx));
	}
	inline void rotate(node *x,int f)
	{
		if(isroot(x)) return;
		node *y=x->p;
		y->ch[!f]=x->ch[f];
		x->p=y->p;
		if(x->ch[f]!=null) x->ch[f]->p=y;
		if(y!=null)
		{
			if(y==y->p->ch[1]) y->p->ch[1]=x;
			else if(y==y->p->ch[0]) y->p->ch[0]=x;
		}
		x->ch[f]=y;
		y->p=x;
		pushup(y);
	}
	inline void splay(node *x)
	{
		while (! isroot(x))
		{
			node *y=x->p;
			if(isroot(y)) rotate(x,x==y->ch[0]);
			else
			{
				int f=y->p->ch[0]==y;
				if(y->ch[f]==x) rotate(x,!f);
				else rotate(y,f);
				rotate(x,f);
			}
		}
		pushup(x);
	}
	inline node *access(node *u)
	{
		node *v=null;
		while (u!=null)
		{
			splay(u);
			v->p=u;
			u->ch[1]=v;
			pushup(u);
			v=u;
			u=u->p;
		}
		return v;
	}
	inline void link(node *u,node *v,int val)
	{
		access(u);
		splay(u);
		u->p=v;
		u->key=u->mx=val;
		pushup(u);
	}
	inline void change(node *v,int w)
	{
		v->key=w;
		splay(v);
	}
	inline void query(node *u,node *v)
	{
		if(v->dep<u->dep) swap(u,v);
		access(v);
		access(u);
		splay(v);
		int ans=v->mx;
		if(v->p==u)
		{
			printf("%d\n",ans);
			return;
		}
		access(v);
		splay(u);
		ans=max(ans,u->mx);
		printf("%d\n",ans);
		
	}
}splay;
int n;
int head[N],cnt;
int eu[N],ev[N];
struct edge
{
	int u,v,w,next;
}e[N<<1];
inline void addedge(int u,int v,int w)
{
	e[cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
inline void dfs(int u,int f,int d)
{
	(nodes+u)->dep=d;
	for(int i=head[u];i!=-1;i=e[i].next)
		if(e[i].v!=f)
		{
			eu[i/2+1]=u;
			ev[i/2+1]=e[i].v;
			splay.link(nodes+e[i].v,nodes+u,e[i].w);
			dfs(e[i].v,u,d+1);
		}
}
char s[8];
int main ()
{
freopen("1.in","r",stdin);
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d",&n);
		memset(head,-1,sizeof(head));
		cnt=0;
		init();
		for(int i=1;i<=n;i++) newnode();
		for(int i=1;i<n;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		dfs(1,0,1);
		while (1)
		{
			scanf("%s",s);
			if(s[0]=='D') break;
			if(s[0]=='C')
			{
				int u,v;
				scanf("%d%d",&u,&v);
				splay.change(nodes+ev[u],v);
			}
			else
			{
				int u,v;
				scanf("%d%d",&u,&v);
				splay.query(nodes+u,nodes+v);
			}
		}
	}
	return 0;
}
