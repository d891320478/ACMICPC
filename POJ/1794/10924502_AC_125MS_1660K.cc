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
#define N 600010
#define M 10010
int a[N],n,m,ans,b[N],c[N];
struct ddd
{
	int x,y;
	void init(){scanf("%d%d",&x,&y);}
}p[N];
int cmp(ddd a,ddd b)
{
	return a.y==b.y && a.x>b.x || a.y<b.y;
}
void mergesort(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	b[0]=c[0]=0;
	for(int i=l;i<=mid;i++) b[++b[0]]=a[i];
	for(int i=mid+1;i<=r;i++) c[++c[0]]=a[i];
	b[++b[0]]=c[++c[0]]=INF;
	int lb=1,lc=1;
	for(int i=l;i<=r;i++)
	{
		if(b[lb]<c[lc])
		{
			ans+=lc-1;
			a[i]=b[lb++];
		}
		else a[i]=c[lc++];
	}
}
int main ()
{
	int tt,ttt=0;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) p[i].init();
		for(int i=n;i<m+n;i++) p[i].init();
		sort(p,p+n+m,cmp);
		for(int i=1;i<=n+m;i++) a[i]=p[i-1].x;
		ans=0;
		mergesort(1,n+m);
		printf("Scenario #%d:\n%d\n\n",++ttt,ans);
	}
	
	return 0;
}