#include <cstdio>
#include <iostream>
using namespace std;
#define N 10010
struct node
{
	node *p,*ch[2];
	bool rev;
}nodes[N],*cur,*null;
node * newnode()
{
	cur->p=cur->ch[0]=cur->ch[1]=null;
	cur->rev=0;
	return cur++;
}
void init()
{
	cur=nodes;
	null=newnode();
}
struct dynamictree
{
	bool isroot(node *x)
	{
		return x->p==null || x->p->ch[0]!=x && x->p->ch[1]!=x;
	}
	void pushup(node *x){}
	void pushdown(node *x)
	{
		if(x==null) return;
		if(x->rev)
		{
			x->rev=0;
			if(x->ch[0]!=null) x->ch[0]->rev^=1;
			if(x->ch[1]!=null) x->ch[1]->rev^=1;
			swap(x->ch[0],x->ch[1]);
		}
	}
	void rotate(node *x,int f)
	{
		if(isroot(x)) return;
		node *y=x->p;
		y->ch[f^1]=x->ch[f];
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
	void splay(node *x)
	{
		static node *sta[N];
		int top=1;
		sta[0]=x;
		for(node *y=x;!isroot(y);y=y->p)
			sta[top++]=y->p;
		while (top) pushdown(sta[--top]);
		while (! isroot(x))
		{
			node *y=x->p;
			if(isroot(y)) rotate(x,x==y->ch[0]);
			else
			{
				int f=y->p->ch[0]==y;
				if(y->ch[f]==x) rotate(x,f^1);
				else rotate(y,f);
				rotate(x,f);
			}
		}
		pushup(x);
	}
	node *access(node *u)
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
	node *link(node *u,node *v)
	{
		access(u);
		splay(u);
		u->rev=1;
		u->p=v;
	}
	node *cut(node *u)
	{
		access(u);
		splay(u);
		u->ch[0]=u->ch[0]->p=null;
		pushup(u);
	}
	void changeroot(node *u)
	{
		access(u)->rev^=1;
	}
	node *getroot(node *u)
	{
		access(u);
		splay(u);
		while(u->p!=null) u=u->p;
		splay(u);
		return u;
	}
	node *LCA(node *u,node *v)
	{
		access(u);
		return access(v);
	}
	bool query(node *u,node *v)
	{
		while (u->p!=null) u=u->p;
		while (v->p!=null) v=v->p;
		return u==v;
	}
}splay;
int n,m,u,v;
char s[12];
int main ()
{
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=n;i++) newnode();
	while (m--)
	{
		scanf("%s %d %d",s,&u,&v);
		if(s[0]=='Q') printf(splay.query(nodes+u,nodes+v)?"Yes\n":"No\n");
		else if(s[0]=='C') splay.link(nodes+u,nodes+v);
		else
		{
			splay.changeroot(nodes+u);
			splay.cut(nodes+v);
		}
	}
	return 0;
}
