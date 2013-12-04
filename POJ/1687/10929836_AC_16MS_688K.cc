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
#define N 30
#define M 10010
double area,sum;
int n,ans,m;
struct point
{
	double x,y;
	void init(){scanf("%lf%lf",&x,&y);}
}p[N],a;
double xmult(point p0,point p1,point p2)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int main ()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) p[i].init();
		scanf("%d",&m);
		area=0;
		for(int mm=1;mm<=m;mm++)
		{
			int o,z[N],i;
			scanf("%d",&o);
			for(i=0;i<o;i++)
				scanf("%d",&z[i]);
			z[o]=z[0];	
			sum=0;
			for(i=0;i<o;i++)
				sum+=xmult(a,p[z[i]],p[z[i+1]]);
			if(fabs(sum)-area>EPS) ans=mm,area=fabs(sum);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}