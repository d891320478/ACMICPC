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
int a[N],n,i,j,rmax,la;
struct line
{
	int l,r,mid;
	int a;
}sq[55];
int main ()
{
	while (scanf("%d",&n) && n)
	{
		memset(sq,0,sizeof(sq));
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++) scanf("%d",&sq[i].a);
		sq[1].mid=sq[1].a;
		sq[1].l=0;
		sq[1].r=sq[1].a*2;
		rmax=sq[1].r;
		for(i=sq[1].l;i<=sq[1].r;i++) a[i]=1;
		for(i=2;i<=n;i++)
		{
			int flag,mx=sq[i-1].mid;
			for(j=1;j<i;j++)
			{
				if(sq[i].a<sq[j].a)
				{
					if(mx<sq[j].mid+2*sq[i].a)
					{
						mx=sq[j].mid+2*sq[i].a;
						flag=-1;
					}
				}
				else
				{
					if(mx<sq[j].mid+2*sq[j].a)
					{
						mx=sq[j].mid+2*sq[j].a;
						flag=1;
					}
				}
			}
			sq[i].mid=mx;
			sq[i].l=mx-sq[i].a;
			sq[i].r=mx+sq[i].a;
			if(flag==1)
			{
				for(j=sq[i].l;j<=sq[i].r;j++)
					a[j]=i;
				rmax=sq[i].r;
			}
			else
			if(flag==-1)
			{
				for(j=rmax;j<=sq[i].r;j++)
					a[j]=i;
				rmax=sq[i].r>rmax?sq[i].r:rmax;
			}
		}
		la=0;
		for(i=1;i<=rmax;i++)
			if(a[i]!=a[la]) a[++la]=a[i];
		for(i=0;i<=la;i++)
		{
			printf("%d",a[i]);
			if (i<la) printf(" ");
			else printf("\n");
		}
	}
	
	return 0;
}