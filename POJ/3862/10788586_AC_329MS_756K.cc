#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
#define N 110
#define EPS 1e-10
inline int sgn(double a)
{
	if(a>EPS)return 1;
	if(a<-EPS)return -1;
	return 0;
}
struct point
{
	double x,y,z;
	void init(){scanf("%lf%lf%lf",&x,&y,&z);}
}p[N],a[N];
int lp,la;
struct STPT
{
    point pt;
    double mt;
} stpt[N];
point operator -(point a,point b)
{
    point c;
    c.x=a.x-b.x; c.y=a.y-b.y; c.z=a.z-b.z;
    return c;
}
point operator +(point a,point b)
{
    point c;
    c.x=a.x+b.x; c.y=a.y+b.y; c.z=a.z+b.z;
    return c;
}
point operator *(point a,double d)
{
    a.x*=d; a.y*=d; a.z*=d;
    return a;
}
point operator /(point a,double d)
{
    a.x/=d; a.y/=d; a.z/=d;
    return a;
}
int operator <(STPT a,STPT b)
{
    return a.mt<b.mt;
}
double len(point a)
{
	return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}
point multi(point a,point b)//叉积
{
	point r;
	r.x=a.y*b.z-a.z*b.y;
	r.y=a.z*b.x-a.x*b.z;
	r.z=a.x*b.y-a.y*b.x;
	return r;
}
double dj(point a,point b)//点积
{
	return a.x*b.x+a.y*b.y+a.z*b.z;
}
double area(point a,point b,point c)//三角形面积
{
	double d1=len(b-c),d2=len(c-a),d3=len(a-b);
	double p=(d1+d2+d3)/2.0;
	return sqrt(p*(p-d1)*(p-d2)*(p-d3));
}
double volume(point a,point b,point c,point d)//四棱锥体积
{
	return dj(multi(a-c,b-c),d-c)/6.0;
}
void doht(point *a,int la,point &ht,double &totv,point pzx)
{
	point zx;
	zx.x=zx.y=zx.z=0;
	int i;
	for(i=0;i<la;i++) zx=zx+a[i];
	zx=zx/la;
	for(i=1;i<la;i++)
	{
		point xj=multi(a[1]-a[0],a[i]-a[0]);
		double l1=len(a[1]-a[0]),l2=len(a[i]-a[0]),l3=len(a[i]-a[1]);
		stpt[i].pt=a[i];
		stpt[i].mt=acos((l1*l1+l2*l2-l3*l3)/(2*l1*l2));
		if(sgn(dj(xj,multi(a[1]-a[0],a[2]-a[0])))==-1) stpt[i].mt*=-1;
	}
	sort(stpt+1,stpt+la);
	for(i=1;i<la;i++) a[i]=stpt[i].pt;
	a[la]=a[0];
	double thisv=0;
	for(i=0;i<la;i++)
	{
		double tiji=fabs(volume(a[i],a[i+1],zx,pzx));
		thisv+=tiji;
		ht=ht+(a[i]+a[i+1]+zx+pzx)*tiji/4.0;
	}
	totv+=thisv;
}
double mind(point *p,int n)
{
	int i,j,k,t;
	point ht;//重心坐标
	ht.x=ht.y=ht.z=0;
	double mindis=-1,totv=0;//最小距离、体积
	point pzx=p[n-1];
	for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
	for(k=j+1;k<n;k++)
	{
		int sg=0;
		la=0;
		for(t=0;t<n;t++)
		{
			double v=volume(p[i],p[j],p[k],p[t]);
			if(sg==0) sg=sgn(v);
			if(sgn(v)==0 && t!=i && t!=j && t<k)break;
			if(sg*sgn(v)==-1)break;
			if(sgn(v)==0)a[la++]=p[t];
		}
		if(t>=n) doht(a,la,ht,totv,pzx);
	}
	ht=ht/totv;
	for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
	for(k=j+1;k<n;k++)
	{
		int sg=0;
		la=0;
		for(t=0;t<n;t++)
		{
			double v=volume(p[i],p[j],p[k],p[t]);
            if (sg==0) sg=sgn(v);
            if (sgn(v)==0 && t!=i && t!=j && t<k) break;
            if (sgn(v)*sgn(sg)==-1) break;
		}
		if(t>=n)
		{
			double ds=fabs(volume(p[i],p[j],p[k],ht))*3.0/area(p[i],p[j],p[k]);
			if (mindis<0 || mindis>ds) mindis=ds;
		}
	}
	return mindis;
}
int main ()
{
	while (scanf("%d",&lp)!=-1)
	{
		double d1,d2;
		for(int i=0;i<lp;i++) p[i].init();
		d1=mind(p,lp);
		scanf("%d",&lp);
		for(int i=0;i<lp;i++) p[i].init();
		d2=mind(p,lp);
		printf("%f\n",d1+d2);
	}
	
	return 0;
}