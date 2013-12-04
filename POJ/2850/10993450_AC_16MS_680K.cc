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
#define PI acos(-1)
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
struct point
{
	double x,y;
}p[N];
int n;
double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int cmp(point a,point b)
{
	return a.x<b.x;
}
int main ()
{
	int tt=0,cs;
	scanf("%d",&cs);
	while (cs--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&p[i].x);
			p[i].y=1;
		}
		sort(p+1,p+1+n,cmp);
		while (n>1)
		{
			for(int i=1;i<n;i++)
			{
				double a=dist(p[i],p[i+1]);
				double cosa=a/4.0,sina=sqrt(16.0-a*a)/4.0;
				double x0=p[i+1].x-p[i].x,y0=p[i+1].y-p[i].y;
				x0=x0/a*2; y0=y0/a*2;
				p[i].x+=x0*cosa-y0*sina;
				p[i].y+=x0*sina+y0*cosa;
			}
			//printf("\n");
			n--;
		}
		printf("%d: %.4f %.4f\n",++tt,p[1].x,p[1].y);
	}
	
	return 0;
}