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
#define N 10010
#define M 10010
int n,c[N],a[N],ans[N],sums;
int lowbit(int x)
{
	return x & (-x);
}
int sum(int x)
{
	int ans=0;
	while (x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
void update(int x,int val)
{
	while (x<=n)
	{
		c[x]+=val;
		x+=lowbit(x);
	}
}
int search(int l,int r,int x)
{
	int mid;
	while (l<r)
	{
		mid=(l+r+1)>>1;
		if(sum(mid)>x) r=mid-1;
		else l=mid;
	}
	return l;
}
int main ()
{
	scanf("%d",&n);
	sums=(n+1)*n/2;
	for(int i=1;i<=n;i++) update(i,1);
	for(int i=1;i<n;i++) scanf("%d",&a[i]);
	for(int i=n-1;i>0;i--)
	{
		int k=search(0,n,a[i]);
		ans[i+1]=k+1;
		sums-=k+1;
		update(k+1,-1);
	}
	ans[1]=sums;
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	
	return 0;
}