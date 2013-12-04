#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define INF 1<<30
#define EPS 1e-8
#define SET(a,b) memset(a,b,sizeof(a))
#define N 40
int n,ans,sum,i,j,k;
int l[4];
double a[4][N];
struct point
{
	double x,y;
}p[N],q[N],z,w;
double mul(point p0,point p1,point p2) 
{    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y); }
bool intersect(point u1,point u2,point v1,point v2)
{
	return (max(u1.x,u2.x)>=min(v1.x,v2.x) && max(v1.x,v2.x)>=min(u1.x,u2.x) && 
			max(u1.y,u2.y)>=min(v1.y,v2.y) && max(v1.y,v2.y)>=min(u1.y,u2.y) && 
			mul(u1,v1,u2)*mul(u1,u2,v2)>EPS && mul(v1,u1,v2)*mul(v1,v2,u2)>EPS);
}
int main ()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf%lf%lf",&p[i].x,&p[i].y,&q[i].x,&q[i].y);
		if(p[i].x==0.0)a[0][l[0]++]=p[i].y;
		if(p[i].x==100.0)a[1][l[1]++]=p[i].y;
		if(p[i].y==0.0)a[2][l[2]++]=p[i].x;
		if(p[i].y==100.0)a[3][l[3]++]=p[i].x;
		if(q[i].x==0.0)a[0][l[0]++]=q[i].y;
		if(q[i].x==100.0)a[1][l[1]++]=q[i].y;
		if(q[i].y==0.0)a[2][l[2]++]=q[i].x;
		if(q[i].y==100.0)a[3][l[3]++]=q[i].x;
	}
	for(i=0;i<4;i++)
	{
		a[i][l[i]++]=0.0;
		a[i][l[i]++]=100.0;
		sort(a[i],a[i]+l[i]);
	}
	scanf("%lf%lf",&z.x,&z.y);
	ans=100;
	for(i=0;i<4;i++)
	for(j=1;j<l[i];j++)
	{
		sum=1;
		if(i==0)w.x=0.0,w.y=(a[i][j]+a[i][j-1])/2.0;
		if(i==1)w.x=100.0,w.y=(a[i][j]+a[i][j-1])/2.0;
		if(i==2)w.y=0.0,w.x=(a[i][j]+a[i][j-1])/2.0;
		if(i==3)w.y=100.0,w.x=(a[i][j]+a[i][j-1])/2.0;
		//printf("%.2f %.2f\n",w.x,w.y);
		for(k=0;k<n;k++)
			if(intersect(w,z,p[k],q[k]))sum++;
		if(sum<ans)ans=sum;
	}
	printf("Number of doors = %d\n",ans);
	
	return 0;
}