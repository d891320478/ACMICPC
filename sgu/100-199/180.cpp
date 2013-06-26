#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
#include<vector>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 66000
long long ans;
int n,a[NN],b[NN],s[NN];
int search(int x)
{
	int l=1,r=b[0],mid;
	while (l<r)
	{
		mid=l+r>>1;
		if(b[mid]<x) l=mid+1;
		else r=mid;
	}
	return l;
}
void update(int x)
{
	while (x<=b[0])
	{
		s[x]++;
		x+=lowbit(x);
	}
}
int sum(int x)
{
	int ans=0;
	while (x>0)
	{
		ans+=s[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	b[0]=1;
	for(int i=2;i<=n;i++)
		if(b[i]!=b[b[0]]) b[++b[0]]=b[i];
	for(int i=1;i<=n;i++)
		a[i]=search(a[i]);
	for(int i=1;i<=n;i++)
	{
		update(a[i]);
		ans+=sum(b[0])-sum(a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
