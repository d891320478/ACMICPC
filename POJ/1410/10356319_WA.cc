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
bool intersect(point u1,point u2,point v1,point v2)
{
	return (max(u1.x,u2.x)>=min(v1.x,v2.x) && max(v1.x,v2.x)>=min(u1.x,u2.x) && 
			max(u1.y,u2.y)>=min(v1.y,v2.y) && max(v1.y,v2.y)>=min(u1.y,u2.y) && 
			mul(u1,v1,u2)*mul(u1,u2,v2)>0 && mul(v1,u1,v2)*mul(v1,v2,u2)>0);
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
		if(mul(a,c[0],c[1])>=0 && mul(a,c[1],c[2])>=0 && mul(a,c[2],c[3])>=0 && mul(a,c[3],c[4])>=0)flag=1;
		if(mul(b,c[0],c[1])>=0 && mul(b,c[1],c[2])>=0 && mul(b,c[2],c[3])>=0 && mul(b,c[3],c[4])>=0)flag=1;
		if(intersect(a,b,c[0],c[1]) || intersect(a,b,c[2],c[1]) || intersect(a,b,c[2],c[3]) || intersect(a,b,c[0],c[3]))flag=1;
		if(flag)printf("T\n");
		else printf("F\n");
	}
	
	return 0;
}