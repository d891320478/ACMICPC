#include <cstdio>
#include <algorithm>
using namespace std;
int n;
struct point
{
	double x,y;
}p[100001],q[100001];
int a[1001],la;
double mul(point p0,point p1,point p2) 
{    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y); }
bool intersect(point u1,point u2,point v1,point v2)
{
	return (max(u1.x,u2.x)>=min(v1.x,v2.x) && max(v1.x,v2.x)>=min(u1.x,u2.x) && 
			max(u1.y,u2.y)>=min(v1.y,v2.y) && max(v1.y,v2.y)>=min(u1.y,u2.y) && 
			mul(u1,v1,u2)*mul(u1,u2,v2)>0 && mul(v1,u1,v2)*mul(v1,v2,u2)>0);
}

int main ()
{
	while (scanf("%d",&n) && n)
	{
		for(int i=1;i<=n;i++)
			scanf("%lf%lf%lf%lf",&p[i].x,&p[i].y,&q[i].x,&q[i].y);
		a[0]=la=1;
		for(int i=2;i<=n;i++)
		{
			a[la++]=i;
			for(int j=la-1;j>=0;j--)
				if(intersect(p[a[j]],q[a[j]],p[i],q[i]))
				{
					a[j]=a[la-1];
					a[la-1]=0;
					la--;
				}
		}
		sort(a,a+la);
		printf("Top sticks:");
		for(int i=0;i<la;i++)
		{
			printf(" %d",a[i]);
			if(i!=la-1)printf(",");
			else printf(".");
		}
		printf("\n");
	}
	
	return 0;
}