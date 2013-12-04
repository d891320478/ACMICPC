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
#define N 10010
#define M 10010
struct fff
{
	int p,d;
	void init(){scanf("%d%d",&p,&d);}
}a[N];
int n,pnt[N],sum;
bool operator < (fff a,fff b)
{
	return a.p<b.p;
}
int find(int x)
{
	if(x==pnt[x]) return x;
	return pnt[x]=find(pnt[x]);
}
int main ()
{
	int i;
	while (scanf("%d",&n)!=-1)
	{
		for(i=0;i<n;i++) a[i].init();
		sort(a,a+n);
		for(i=0;i<=10000;i++) pnt[i]=i;
		sum=0;
		for(i=n-1;i>=0;i--)
			if(find(a[i].d)>0) {sum+=a[i].p; pnt[pnt[a[i].d]]--;}
		printf("%d\n",sum);
	}
	
	return 0;
}