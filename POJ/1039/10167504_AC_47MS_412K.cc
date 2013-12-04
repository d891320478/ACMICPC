#include <cstdio>
const double inf=1e-10;
int n;
struct point
{
	double x,y;
}a[21],b[21],s,t,poi;
double ans;
double cross(point p0,point p1,point p2)
{
	double x1=p1.x-p0.x,x2=p2.x-p0.x,y1=p1.y-p0.y,y2=p2.y-p0.y;
	return x1*y2-x2*y1;
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
bool f(point s,point t,int k)
{
	point ret;
	int anp,i;
	for(i=1;i<n;i++)
	{
		if(cross(s,a[i],t)>inf || cross(s,a[i+1],t)>inf){anp=1;break;}
		if(cross(s,t,b[i])>inf || cross(s,t,b[i+1])>inf){anp=2;break;}
	}
	if(i>=n)return 1;
	if(i<k)return 0;
	if(anp==1) ret=intersection(s,t,a[i],a[i+1]);
	else ret=intersection(s,t,b[i],b[i+1]);
	if(ret.x>ans)ans=ret.x;
	return 0;
}
int main ()
{
	while (scanf("%d",&n) && n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&a[i].x,&a[i].y);
			b[i]=a[i];
			b[i].y-=1.0;
		}
		if(n<3)
		{
			puts("Through all the pipe.");
			continue;
		}
		ans=-1e8;
		bool flag=0;
		for(int i=1;i<n && !flag;i++)
		for(int j=i+1;j<=n;j++)
		{
			flag=f(a[i],b[j],j);
			if(flag)break;
			flag=f(b[i],a[j],j);
			if(flag)break;
		}
		if(flag)puts("Through all the pipe.");
		else printf("%.2f\n",ans);
	}
	
	return 0;
}
