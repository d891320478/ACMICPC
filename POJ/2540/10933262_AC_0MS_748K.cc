//POJ-2540
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
#define EPS 1e-10
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
struct point
{
	double x,y;
}p[N],q[N],a,b,c,d;
string s;
int cnt,curcnt;
double ans=INF;
inline double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
inline point intersect(point u1,point u2,point v1,point v2)
{
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
			((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}
inline void cut(point p1,point p2)
{
	curcnt=0;
	for(int i=1;i<=cnt;i++)
	{
		//printf("%f %f\n",p[4].x,p[4].y);
		if(xmult(p[i],p2,p1)>-EPS) q[++curcnt]=p[i];//,printf("- %f %f\n",p[i].x,p[i].y);
		else
		{
			if(xmult(p[i-1],p2,p1)>EPS) q[++curcnt]=intersect(p[i-1],p[i],p1,p2);
			if(xmult(p[i+1],p2,p1)>EPS) q[++curcnt]=intersect(p[i+1],p[i],p1,p2);
		}
	}
	for(int i=1;i<=curcnt;i++) p[i]=q[i];
	p[curcnt+1]=q[1]; p[0]=q[curcnt];
	cnt=curcnt;
}
double area()
{
	double sum=0;
	for(int i=2;i<cnt;i++)
		sum+=xmult(p[i],p[i+1],p[1]);
	return fabs(sum)/2.0;
}
int main ()
{
	int tt=0;
	p[1].x=0; p[1].y=0;
	p[2].x=0; p[2].y=10;
	p[3].x=10; p[3].y=10;
	p[4].x=10; p[4].y=0;
	p[0]=p[4]; p[5]=p[1];
	cnt=4;
	while (cin>>b.x>>b.y>>s)
	{
		++tt;
		if(s=="Same") ans=0;
		if(ans==0.0)
		{
			printf("0.00\n");
			continue;
		}
		c.x=(a.x+b.x)/2;
		c.y=(a.y+b.y)/2;
		d.x=c.x-a.y+b.y;
		d.y=c.y+a.x-b.x;
		//printf("%f %f %f %f\n",c.x,c.y,d.x,d.y);
		if(s=="Colder")
		{
			if(xmult(a,d,c)>0) cut(c,d);
			else cut(d,c);
		}
		else
		{
			if(xmult(b,d,c)>0) cut(c,d);
			else cut(d,c);
		}
		//printf("%d\n",cnt);
		//for(int i=1;i<=cnt;i++) printf("%f %f\n",p[i].x,p[i].y);
		//printf("\n");
		ans=area();
		printf("%.2f\n",ans);
		a=b;
	}
	
	return 0;
}