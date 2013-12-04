#include <cstdio>
#include <iostream>
using namespace std;
struct point
{
    double x,y;
}a1,b1,a2,b2,poi;
int n;
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
bool col(point u1,point u2,point v1,point v2)
{
	return mul(u1,v1,u2)*mul(u1,u2,v2)==0 && mul(v1,u1,v2)*mul(v1,v2,u2)==0;
}
point intersection(point u1,point u2,point v1,point v2)
{
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
			 ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}
int main()
{
	scanf("%d",&n);
	printf("INTERSECTING LINES OUTPUT\n");
	while(n--)
	{
		scanf("%lf%lf%lf%lf",&a1.x,&a1.y,&a2.x,&a2.y);
		scanf("%lf%lf%lf%lf",&b1.x,&b1.y,&b2.x,&b2.y);
		if(col(a1,a2,b1,b2))
		{
			printf("LINE\n");
			continue;
		}
		if(! intersect(a1,a2,b1,b2))
		{
			printf("NONE\n");
			continue;
		}
		poi=intersection(a1,a2,b1,b2);
		printf("POINT %.2lf %.2lf\n",poi.x,poi.y);
	}
	printf("END OF OUTPUT\n");
	return 0;
}
