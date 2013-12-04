#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define INF 1e20
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 10010
#define M 10010
int n;
double d,w,l0,r0;
struct point
{
	double x,y;
	void init(){scanf("%lf%lf",&x,&y);}
}p[N];
struct line
{
	double l,r;
}q[N];
int cmp(const line &a,const line &b)
{
	if(a.l<b.l)return 1;
	if(a.l>b.l)return 0;
	if(a.r<b.r)return 1;
	return 0;
}
int main ()
{

	int tttt=0,i;
	while (scanf("%d%lf",&n,&d))
	{
		if(n==0 && d==0.0)break;
		for(i=0;i<n;i++)
		{
			p[i].init();
			if(p[i].y<0) p[i].y=-p[i].y;
		}
		for(i=0;i<n;i++)
		{
			if(d*d-p[i].y*p[i].y<0)break;
			q[i].l=p[i].x-sqrt(d*d-p[i].y*p[i].y);
			q[i].r=p[i].x+sqrt(d*d-p[i].y*p[i].y);
		}
		if(i<n)
		{
			printf("Casr %d: -1\n",++tttt);
			continue;
		}
		sort(q,q+n,cmp);
		int sum=0;
		for(i=0;i<n;)
		{
			sum++;
			l0=q[i].l; r0=q[i].r;
			i++;
			while (q[i].l>=l0 && q[i].l<=r0 && i<n)
			{
				l0=q[i].l;
				r0=q[i].r<r0?q[i].r:r0;
				i++;
			}
		}
		printf("Casr %d: %d\n",++tttt,sum);
	}
	
	return 0;
}