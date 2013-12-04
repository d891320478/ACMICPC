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
#define N 250010
#define M 10010
int n,m,la;
struct fff
{
	int key,sum;
}a[N];
int c1(fff a,fff b)
{
	return a.key<b.key;
}
int c2(fff a,fff b)
{
	return a.sum>b.sum || a.sum==b.sum && a.key<b.key;
}
int main()
{
	while (scanf("%d%d",&n,&m) && n+m)
	{
		n=n*m;
		for(int i=0;i<n;i++) scanf("%d",&a[i].key),a[i].sum=1;
		sort(a,a+n,c1);
		la=0;
		for(int i=1;i<n;i++)
		{
			if(a[i].key!=a[la].key) a[++la]=a[i];
			else a[la].sum++;
		}
		sort(a,a+la+1,c2);
		printf("%d",a[1].key);
		for(int i=2;i<=la;i++)
		{
			if(a[i].sum==a[1].sum) printf(" %d",a[i].key);
			else break;
		}
		printf("\n");
	}
	return 0;
}