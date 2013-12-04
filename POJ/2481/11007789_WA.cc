#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define PI acos(-1)
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 100010
#define M 15010
int n;
int a[N],ans[N];
struct cow
{
	int s,e,id;
	void init(){scanf("%d%d",&s,&e);}
}c[N];
int lowbit(int x)
{
	return x & (-x);
}
int sum(int x)
{
	int ans=0;
	while (x)
	{
		ans+=a[x];
		x-=lowbit(x);
	}
	return ans;
}
int update(int x)
{
	while (x<=100001)
	{
		a[x]++;
		x+=lowbit(x);
	}
}
int cmp(cow a,cow b)
{
	return a.e>b.e || a.e==b.e && a.s<b.s;
}
int main ()
{
	int i;
	while(scanf("%d",&n) && n)
	{
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		{
			c[i].init();
			c[i].id=i+1;
		}
		sort(c,c+n,cmp);
		ans[c[0].id]=0;
		update(c[0].s+1);
		for(i=1;i<n;i++)
		{
			if(c[i].e==c[i-1].e && c[i].s==c[i-1].s) ans[c[i].id]=ans[c[i-1].id];
			else if(c[i].e==c[i-1].e) ans[c[i].id]=sum(c[i].s);
			else ans[c[i].id]=sum(c[i].s+1);
			update(c[i].s+1);
		}
		printf("%d",ans[1]);
		for(i=2;i<=n;i++) printf(" %d",ans[i]);
		printf("\n");
	}
	
	return 0;
}