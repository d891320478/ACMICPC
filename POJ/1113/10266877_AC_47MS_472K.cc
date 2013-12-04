#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF 999999999.9
#define PI 3.141592653
struct point
{
	double x,y,dis;
}pt[1005],p[1005],stack[1005],p0;
int tot,top;
int n,L;
double Dis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int Cmp_PolarAngel(point p1,point p2,point p0)
{
	double delta=xmult(p1,p2,p0);
	if(delta<0.0)return 1;
	if(delta==0.0)return 0;
	return -1;
}
bool Is_LeftTurn(point p3,point p2,point p1)
{
	int type=Cmp_PolarAngel(p3,p1,p2);
	return type<0;
}
int Cmp(const point &a,const point &b)
{
	int type=Cmp_PolarAngel(a,b,p0);
	if(type<0)return 1;
	if(type==0)
		if(a.dis<b.dis)return 1;
		else return 0;
	return 0;
}
void Solve(int n)
{
	int i;
	for(i=1;i<n;i++)
		pt[i].dis=Dis(p0,pt[i]);
	sort(pt+1,pt+n,Cmp);
	tot=1; p[0]=p0;
	for(i=2;i<n;i++)
		if(Cmp_PolarAngel(pt[i],pt[i-1],p0))p[tot++]=pt[i-1];
	p[tot++]=pt[n-1];
	top=1;
	stack[0]=p[0];
	stack[1]=p[1];
	for(i=2;i<tot;i++)
	{
		while (top>1 && ! Is_LeftTurn(p[i],stack[top],stack[top-1])) top--;
		stack[++top]=p[i];
	}
	stack[++top]=p0;
	double ans=0.0;
	for(i=0;i<top;i++)
		ans+=Dis(stack[i],stack[i+1]);
	ans+=2*PI*L;
	printf("%d\n",(int)(ans+0.5));
}
int main ()
{
	int i,k;
	while (scanf("%d%d",&n,&L)!=EOF)
	{
		p0.x=p0.y=INF;
		memset(stack,0,sizeof(stack));
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&pt[i].x,&pt[i].y);
			if(pt[i].y<p0.y)
			{
				p0=pt[i];
				k=i;
			}
			else
			if(pt[i].y==p0.y && pt[i].x<p0.x)
			{
				p0=pt[i];
				k=i;
			}
		}
		pt[k]=pt[0];
		pt[0]=p0;
		Solve(n);
	}
	
	return 0;
}