#include <cstdio>
#include <cmath>
struct point
{
	double x,y;
};
struct line
{
	point a,b;
};
double Dis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
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
point circumcenter(point a,point b,point c)
{
	line u,v;
	u.a.x=(a.x+b.x)/2; u.a.y=(a.y+b.y)/2;
	u.b.x=u.a.x-a.y+b.y; u.b.y=u.a.y+a.x-b.x;
	v.a.x=(a.x+c.x)/2; v.a.y=(a.y+c.y)/2;
	v.b.x=v.a.x-a.y+c.y; v.b.y=v.a.y+a.x-c.x;
	return intersection(u.a,u.b,v.a,v.b);
}
int main()
{
	char ch1,ch2,ch3;
	double r,z;
	point a,b,c,cir;
	bool flag=0;
	while (scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y)!=EOF)
	{
		cir=circumcenter(a,b,c);
		r=Dis(a,cir);
		if(flag)printf("\n");
		flag=1;
		if(cir.x>1e-8)ch1='-';
		else ch1='+',cir.y=-cir.x;
		if(cir.y>1e-8)ch2='-';
		else ch2='+',cir.y=-cir.y;
		printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n",ch1,cir.x,ch2,cir.y,r);
		z=cir.x*cir.x+cir.y*cir.y-r*r;
		if(z<0)ch3='-',z=-z;
		else ch3='+';
		printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n",ch1,2*cir.x,ch2,2*cir.y,ch3,z);
	}
	
	return 0;
}
