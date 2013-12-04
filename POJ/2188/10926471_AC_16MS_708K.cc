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
#define N 10010
#define M 10010
int hash[N],n,a[N],b[N],c[N],ans;
void mergesort(int l,int r)
{
	if(l==r) return;
	int lb=1,lc=1,i,mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	b[0]=c[0]=0;
	for(i=l;i<=mid;i++) b[++b[0]]=a[i];
	for(i=mid+1;i<=r;i++) c[++c[0]]=a[i];
	b[++b[0]]=c[++c[0]]=INF;
	for(i=l;i<=r;i++)
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
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&b[i],&c[i]);
		hash[b[i]]=i;
	}
	for(int i=1;i<=n;i++) a[i]=hash[c[i]];
	ans=0;
	mergesort(1,n);
	printf("%d\n",ans);
	
	return 0;
}