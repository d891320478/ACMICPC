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
#define N 20010
#define M 10010
struct cow
{
	long long v,x;
}c[N];
long long a[N],s1[N],s2[N],ans,sn;
int n;
map<long long,int> ha;
int cmp(cow a,cow b)
{
	return a.v<b.v;
}
int lowbit(int x)
{
	return x & (-x);
}
void sum(int v,long long &sl,long long &sm)
{
	sl=sm=0;
	while (v>0)
	{
		sl+=s1[v];
		sm+=s2[v];
		v-=lowbit(v);
	}
}
void update(int v,long long key)
{
	while (v<=n)
	{
		s1[v]+=key;
		s2[v]++;
		v+=lowbit(v);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&c[i].v,&c[i].x);
		a[i]=c[i].x;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) ha[a[i]]=i;
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int v=ha[c[i].x];
		long long sl,sm;
		sum(v,sl,sm);
		ans+=(c[i].x*sm-sl)*c[i].v+(sn-sl-c[i].x*(i-1-sm))*c[i].v;
		sn+=c[i].x;
		update(v,c[i].x);
	}
	printf("%lld\n",ans);
	return 0;
}