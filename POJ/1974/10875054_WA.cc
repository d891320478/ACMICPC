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
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 140010
#define M 10010
int n,m,k,ans;
int vis[N];
struct stone
{
	int x,y;
}a[N];
int cmp1(stone a,stone b)
{
	return a.x<b.x || a.x==b.x && a.y<b.y;
}
int cmp2(stone a,stone b)
{
	return a.y<b.y || a.y==b.y && a.x<b.x;
}
int main ()
{
	int ttt,i;
	scanf("%d",&ttt);
	while (ttt--)
	{
		scanf("%d%d%d",&m,&n,&k);
		for(i=0;i<k;i++) scanf("%d%d",&a[i].x,&a[i].y);
		ans=0;
		sort(a,a+k,cmp1);
		memset(vis,0,sizeof(vis));
		for(i=0;i<k;i++) vis[a[i].x]=1;
		for(i=1;i<=n;i++) ans+=1-vis[i];
		if(k>0)
		{
			if(a[0].y>2) ans++;
			for(i=1;i<k;i++)
			{
				if(a[i].x==a[i-1].x)
				{
					if(a[i].y-a[i-1].y>2) ans++;
				}
				else
				{
					if(n-a[i-1].y>=2) ans++;
					if(a[i].y>2) ans++;
				}
			}
			if(n-a[k-1].y>=2) ans++;
		}
		sort(a,a+k,cmp2);
		memset(vis,0,sizeof(vis));
		for(i=0;i<k;i++) vis[a[i].y]=1;
		for(i=1;i<=m;i++) ans+=1-vis[i];
		if(k>0)
		{
			if(a[0].x>2) ans++;
			for(i=1;i<k;i++)
			{
				if(a[i].y==a[i-1].y)
				{
					if(a[i].x-a[i-1].x>2) ans++;
				}
				else
				{
					if(m-a[i-1].x>=2) ans++;
					if(a[i].x>2) ans++;
				}
			}
			if(m-a[k-1].x>=2) ans++;	
		}
		printf("%d\n",ans);
	}
	
	return 0;
}