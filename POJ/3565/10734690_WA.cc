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
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 110
#define M 10010
int n;
struct point
{
	double x,y;
}p[N],q[N];
int a[N];
double xmult(point p0,point p1,point p2)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
bool intersection(point u1,point u2,point v1,point v2)
{
	return min(u1.x,u2.x)<=max(v1.x,v2.x) && min(v1.x,v2.x)<=max(u1.x,u2.x)
		&& min(u1.y,u2.y)<=max(v1.y,v2.y) && min(v1.y,v2.y)<=max(u1.y,u2.y)
		&& xmult(u1,v1,u2)*xmult(u1,u2,v2)>=0 && xmult(v1,u1,v2)*xmult(u1,v2,u2)>=0;
}
int cmp(const int &i,const int &j)
{
	return ~intersection(p[i],q[i],p[j],q[j]);
}
int main ()
{
	int i;
	while (scanf("%d",&n)!=-1)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%f%f",&p[i].x,&p[i].y);
			a[i]=i;
		}
		for(i=1;i<=n;i++)
			scanf("%f%f",&q[i].x,&q[i].y);
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=n;i++) printf("%d\n",a[i]);
	}
	
	return 0;
}