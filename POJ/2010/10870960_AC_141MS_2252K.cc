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
#define N 20010
#define M 100010
int heap[N],lh,pre[M],suc[M];
int n,m,sum,z;
struct fff
{
	int s,m;
	void init(){scanf("%d%d",&s,&m);}
}a[M];
bool operator < (fff a,fff b)
{
	return a.s<b.s;
}
void build_down(int father)
{
	int son=father*2;
	while (son<=lh)
	{
		if(son+1<=lh && heap[son+1]>heap[son]) son++;
		if(heap[father]<heap[son])
		{
			swap(heap[father],heap[son]);
			father=son;
			son=father*2;
		}
		else return;
	}
}
int main ()
{
	int i;
	scanf("%d%d%d",&z,&n,&sum);
	m=z/2;
	for(i=1;i<=n;i++) a[i].init();
	sort(a+1,a+n+1);
	for(lh=1;lh<=m;lh++)
	{
		heap[lh]=a[lh].m;
		pre[m]+=a[lh].m;
	}
	lh--;
	for(i=lh/2;i>0;i--) build_down(i);
	for(i=m+1;i<=n;i++)
		if(a[i].m<heap[1])
		{
			pre[i]=pre[i-1]-heap[1]+a[i].m;
			heap[1]=a[i].m;
			build_down(1);
		}
		else pre[i]=pre[i-1];
	lh=1;
	for(i=n;lh<=m;i--,lh++)
	{
		heap[lh]=a[i].m;
		suc[n-m+1]+=a[i].m;
	}
	lh--;
	for(i=lh/2;i>0;i--) build_down(i);
	for(i=n-m;i>0;i--)
		if(a[i].m<heap[1])
		{
			suc[i]=suc[i+1]-heap[1]+a[i].m;
			heap[1]=a[i].m;
			build_down(1);
		}
		else suc[i]=suc[i+1];
	for(i=n-m;i>m;i--)
		if(pre[i-1]+a[i].m+suc[i+1]<=sum) break;
	if(i<=m) printf("-1\n");
	else printf("%d\n",a[i].s);
	
	return 0;
}