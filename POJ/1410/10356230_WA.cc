#include <cstdio>
#include <iostream>
using namespace std;
struct point
{
	int x,y;
}a,b,c,d,e,f;
double mul(point p0,point p1,point p2) 
{    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y); }
bool intersect(point u1,point u2,point v1,point v2)
{
	return (max(u1.x,u2.x)>=min(v1.x,v2.x) && max(v1.x,v2.x)>=min(u1.x,u2.x) && 
			max(u1.y,u2.y)>=min(v1.y,v2.y) && max(v1.y,v2.y)>=min(u1.y,u2.y) && 
			mul(u1,v1,u2)*mul(u1,u2,v2)>=0 && mul(v1,u1,v2)*mul(v1,v2,u2)>=0);
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y);
		scanf("%d%d%d%d",&f.x,&f.y,&d.x,&d.y);
		c.x=f.x,c.y=d.y;
		e.x=d.x,e.y=f.y;
		if(intersect(a,b,c,d) && intersect(a,b,e,d) && intersect(a,b,e,f) && intersect(a,b,c,f))
			printf("T\n");
		else printf("F\n");
	}
	
	return 0;
}