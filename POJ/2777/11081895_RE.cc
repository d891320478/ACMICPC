#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 200010
#define M 10010
int n,q,t,ans;
int tree[N<<2],lzy[N<<2];
char ch,s;
int vis[50];
void pushup(int rt)
{
	if(tree[rt<<1]==tree[rt<<1|1]) tree[rt]=tree[rt<<1];
	else tree[rt]=0;
}
void pushdown(int l,int r,int rt)
{
	if(lzy[rt])
	{
		lzy[rt<<1]=lzy[rt<<1|1]=lzy[rt];
		tree[rt<<1]=tree[rt<<1|1]=lzy[rt];
		lzy[rt]=0;
	}
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		tree[rt]=1;
		lzy[rt]=0;
		return;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}
void update(int L,int R,int c,int l,int r,int rt)
{
	if(L<=l && R>=r)
	{
		tree[rt]=lzy[rt]=c;
		return;
	}
	int m=(l+r)>>1;
	pushdown(l,r,rt);
	if(L<=m) update(L,R,c,l,m,rt<<1);
	if(R>m) update(L,R,c,m+1,r,rt<<1|1);
	pushup(rt);
}
void query(int L,int R,int l,int r,int rt)
{
	if(ans==t) return;
	if(L<=l && R>=r)
		if(tree[rt]!=0)
		{
			if(! vis[tree[rt]])
			{
				vis[tree[rt]]=1;
				ans++;
			}
			return;
		}
	int m=(l+r)>>1;
	pushdown(l,r,rt);
	if(L<=m) query(L,R,l,m,rt<<1);
	if(r>m) query(L,R,m+1,r,rt<<1|1);
	pushup(rt);
}
int main()
{
	while (scanf("%d%d%d%c",&n,&t,&q,&ch)!=-1)
	{
		build(1,n,1);
		while (q--)
		{
			int u,v,w;
			scanf("%c",&s);
			if(s=='C')
			{
				scanf("%d %d %d%c",&u,&v,&w,&ch);
				if(u>v) swap(u,v);
				update(u,v,w,1,n,1);
				//printf("%d\n",q);
			}
			else
			{
				scanf("%d %d%c",&u,&v,&ch);
				if(u>v) swap(u,v);
				SET(vis,0);
				ans=0;
				query(u,v,1,n,1);
				printf("%d\n",ans);
				//printf("%d\n",q);
			}
		}
	}
	return 0;
}