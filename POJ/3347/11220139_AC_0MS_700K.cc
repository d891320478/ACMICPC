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
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
int a[N],n;
struct segment
{
	int l,r;
}p[N];
int main()
{
	while (scanf("%d",&n) && n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			p[i].l=0;
			for(int j=1;j<i;j++)
				p[i].l=max(p[i].l,p[j].r-ABS(a[i]-a[j]));
			p[i].r=a[i]*2+p[i].l;
		}
		for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
		if(p[j].l<p[j].r)
		{
			if(p[j].r>p[i].l && a[j]<a[i])
				p[j].r=p[i].l;
			if(p[j].r>p[i].l && a[j]>a[i])
				p[i].l=p[j].r;
		}
		int flag=0;
		for(int i=1;i<=n;i++)
			if(p[i].l<p[i].r)
			{
				if(! flag) flag=1;
				else printf(" ");
				printf("%d",i);
			}
		printf("\n");
	}
	return 0;
}