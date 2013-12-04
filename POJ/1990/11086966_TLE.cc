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
#define N 10010
#define M 10010
struct cow
{
	int v,x;
}c[N];
int a[N],s1[N],s2[N],n,ans,sn;
map<int,int> ha;
int cmp(cow a,cow b)
{
	return a.v<b.v;
}
int lowbit(int x)
{
	return x & (-x);
}
void sum(int v,int &sl,int &sm)
{
	sl=sm=0;
	while (v>0)
	{
		sl+=s1[v];
		sm+=s2[v];
		v-=lowbit(v);
	}
}
void update(int v,int key)
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
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&c[i].v,&c[i].x);
		a[i]=c[i].x;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++) ha[a[i]]=i+1;
	sort(c,c+n,cmp);
	for(int i=0;i<n;i++)
	{
		int v=ha[c[i].x],sl,sm;
		sum(v,sl,sm);
		ans+=(c[i].x*sm-sl)*c[i].v+(sn-sl-c[i].x*(i-sm))*c[i].v;
		sn+=c[i].x;
		update(v,c[i].x);
	}
	printf("%d\n",ans);
	return 0;
}