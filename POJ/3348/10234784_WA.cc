#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF 999999999.9
#define PI 3.141592653
struct Point
{
	double x, y, dis;
}pt[1005], stack[1005], p0;
long top, tot;

double Dis(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

long Cmp_PolarAngel(Point p1, Point p2, Point pb)
{
	double delta=(p1.x-pb.x)*(p2.y-pb.y)-(p2.x-pb.x)*(p1.y-pb.y);
	if (delta<0.0) return 1;
	else if (delta==0.0) return 0;
		else return -1;
}

bool Is_LeftTurn(Point p3, Point p2, Point p1)
{
	long type=Cmp_PolarAngel(p3, p1, p2);
	if (type<0) return true;
	return false;
}

long Cmp(const Point &a1, const Point &a2)
{
	long type=Cmp_PolarAngel(a1, a2, p0);
	if (type<0) return 1;
	else
	if (type==0)
		if (a1.dis<a2.dis) return 1;
		else return 0;
	else return 0;
}
long xmult(Point p1,Point p2,Point p0)
{
	long ans=(p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
	return ans>0?ans:-ans;
}
void Solve(long n)
{
	long i, k;
	p0.x=p0.y=INF;
	memset(stack,0,sizeof(stack));
	for (i=0;i<n;i++)
	{
		scanf("%lf %lf",&pt[i].x, &pt[i].y);
		if (pt[i].y < p0.y)
		{
			p0.y=pt[i].y;
			p0.x=pt[i].x;
			k=i;
		}
		else 
		if (pt[i].y==p0.y) 
		if (pt[i].x<p0.x)
		{
			p0.x=pt[i].x;
			k=i;
		}
	}
	pt[k]=pt[0];
	pt[0]=p0;
	for (i=1;i<n;i++)
		pt[i].dis=Dis(pt[i].x,pt[i].y, p0.x,p0.y);
	sort(pt+1, pt+n, Cmp);
	tot=1;
	for (i=2;i<n;i++)
	if (Cmp_PolarAngel(pt[i], pt[i-1], p0))
		pt[tot++]=pt[i-1];
	pt[tot++]=pt[n-1];
	top=1;
	stack[0]=pt[0];
	stack[1]=pt[1];
	for (i=2;i<tot;i++)
	{
		while (top>=1 && Is_LeftTurn(pt[i], stack[top], stack[top-1])==false) top--;
		stack[++top]=pt[i];
	}
	long s=0;
	for(i=0;i+1<top;i++)
		s+=xmult(stack[i+1],stack[i+2],stack[i]);
	printf("%ld\n",s/100);
}
int main ()
{
	long n;
	while (scanf("%ld",&n)!=EOF)
		Solve(n);
	return 0;
}