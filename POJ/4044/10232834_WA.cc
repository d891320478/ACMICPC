#include <cstdio>
#include <iostream>
using namespace std;
struct point
{
	long long x,y;
};
struct line
{
	point a,b;
};
double mul(point p0,point p1,point p2) 
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int intersect(point u1,point u2,point v1,point v2)
{
	return (max(u1.x,u2.x)>=min(v1.x,v2.x) && max(v1.x,v2.x)>=min(u1.x,u2.x) && 
			max(u1.y,u2.y)>=min(v1.y,v2.y) && max(v1.y,v2.y)>=min(u1.y,u2.y) && 
			mul(u1,v1,u2)*mul(u1,u2,v2)>=0 && mul(v1,u1,v2)*mul(v1,v2,u2)>=0);
}
int main()
{
	line l[1501],z1,z2,z;
	/*while (scanf("%ld%ld%ld%ld",&z1.a.x,&z1.a.y,&z1.b.x,&z1.b.y)!=EOF)
	{
		scanf("%ld%ld%ld%ld",&z2.a.x,&z2.a.y,&z2.b.x,&z2.b.y);
		printf("%d\n",intersect(z1.a,z1.b,z2.a,z2.b));
	}*/
	int t,n,i,j;
	long ans,ma;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lld%lld%lld%lld",&l[i].a.x,&l[i].a.y,&l[i].b.x,&l[i].b.y);
		scanf("%lld%lld",&z.a.x,&z.a.y);
		ans=0;
		for(i=0;i<n;i++)
		{
			z.b.x=200000*(l[i].a.x-z.a.x)+z.a.x;
			z.b.y=200000*(l[i].a.y-z.a.y)+z.a.y;
			ma=0;
			for(j=0;j<n;j++)
				if(intersect(z.a,z.b,l[j].a,l[j].b))ma++;
			ans=ans>ma?ans:ma;
			z.b.x=200000*(l[i].b.x-z.a.x)+z.a.x;
			z.b.y=200000*(l[i].b.y-z.a.y)+z.a.y;
			ma=0;
			for(j=0;j<n;j++)
				if(intersect(z.a,z.b,l[j].a,l[j].b))ma++;
			ans=ans>ma?ans:ma;
		}
		printf("%ld\n",ans);
	}
	
	return 0;
}