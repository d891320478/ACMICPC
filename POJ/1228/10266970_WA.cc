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
		p[i].dis=Dis(p0,p[i]);
	sort(pt+1,pt+n,Cmp);
	top=1;
	stack[0]=p[0];
	stack[1]=p[1];
	for(i=2;i<n;i++)
	{
		while (top>1 && ! Is_LeftTurn(p[i],stack[top],stack[top-1])) top--;
		stack[++top]=p[i];
	}
	stack[++top]=p0;
	for(i=2;i<=top;i++)
	{
		int j=i;
		while(xmult(stack[j],stack[j-1],stack[j-2])==0.0 && j<top)j++;
		if(j==i)
		{
			printf("NO\n");
			return;
		}
		i=j;
	}
	printf("YES\n");
}
int main ()
{
	int i,k,t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		p0.x=p0.y=INF;
		memset(stack,0,sizeof(stack));
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
			if(p[i].y<p0.y)
			{
				p0=p[i];
				k=i;
			}
			else
			if(p[i].y==p0.y && p[i].x<p0.x)
			{
				p0=p[i];
				k=i;
			}
		}
		p[k]=p[0];
		p[0]=p0;
		Solve(n);
	}
	
	return 0;
}