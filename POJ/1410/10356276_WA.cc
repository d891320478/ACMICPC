#include <cstdio>
#include <iostream>
using namespace std;
struct point
{
	int x,y;
}a,b,c[5];
int u,v,w,x;
double mul(point p0,point p1,point p2) 
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		bool flag=0;
		scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y);
		scanf("%d%d%d%d",&u,&v,&w,&x);
		c[0].x=min(u,w),c[0].y=min(v,x);
		c[1].x=max(u,w),c[1].y=min(v,x);
		c[2].x=max(u,w),c[2].y=max(v,x);
		c[3].x=min(u,w),c[3].y=max(v,x);
		c[4]=c[0];
		if(mul(a,c[0],c[1])>0 && mul(a,c[1],c[2])>0 && mul(a,c[2],c[3])>0 && mul(a,c[3],c[4])>0)flag=1;
		if(mul(b,c[0],c[1])>0 && mul(b,c[1],c[2])>0 && mul(b,c[2],c[3])>0 && mul(b,c[3],c[4])>0)flag=1;
		if(flag)printf("T\n");
		else printf("F\n");
	}
	
	return 0;
}