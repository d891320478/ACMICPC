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
#define EPS 1e-6
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 50010
#define M 10010
#define INF (1<<30)
int tree[N<<2][2];
int n,q;
int a[N];
int a1,a2;
int ans,lc;
char ch[30];
void build(int l,int r,int rt)
{
	if(l==r)
	{
		tree[rt][0]=tree[rt][1]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	tree[rt][0]=max(tree[rt<<1][0],tree[rt<<1|1][0]);
	tree[rt][1]=min(tree[rt<<1][1],tree[rt<<1|1][1]);
}
void query(int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r)
	{
		a1=max(a1,tree[rt][0]);
		a2=min(a2,tree[rt][1]);
		return;
	}
	int m=(l+r)>>1;
	if(L<=m)query(L,R,l,m,rt<<1);
	if(R>m) query(L,R,m+1,r,rt<<1|1);
}
int fastget()
{
	char c;
	int a=0;
	while (c=getchar()) if(c>='0' && c<='9') break;
	a=c-'0';
	while (c=getchar())
		if(c>='0' && c<='9') a=a*10+c-'0';
		else break;
	return a;
}
int main()
{
	n=fastget();
	q=fastget();
		for(int i=1;i<=n;i++) a[i]=fastget();
		build(1,n,1);
		while (q--)
		{
			int u,v,ans;
			scanf("%d%d",&u,&v);
			a1=-1;
			a2=INF;
			query(u,v,1,n,1);
			ans=a1-a2;
			lc=0;
			while (ans)
			{
				ch[lc++]=ans%10+'0';
				ans/=10;
			}
			for(int i=lc-1;i>=0;i--) putchar(ch[i]);
			if(! lc) putchar('0');
			putchar('\n');
		}
	return 0;
}