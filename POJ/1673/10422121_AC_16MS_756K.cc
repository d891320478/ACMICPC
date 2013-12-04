#include <iostream>
#include <cstdio>

using namespace std;
struct point
{
	double x,y;
}a,b,c,d;
struct line
{
	point a,b;
};
point intersection(point u1,point u2,point v1,point v2)
{
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
			 ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}
point perpencenter(point a,point b,point c)
{
	line u,v;
	u.a=c;
	u.b.x=u.a.x-a.y+b.y;
	u.b.y=u.a.y+a.x-b.x;
	v.a=b;
	v.b.x=v.a.x-a.y+c.y;
	v.b.y=v.a.y+a.x-c.x;
	return intersection(u.a,u.b,v.a,v.b);
}
int main ()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
		d=perpencenter(a,b,c);
		printf("%.4f %.4f\n",d.x,d.y);
	}
	
	return 0;
}