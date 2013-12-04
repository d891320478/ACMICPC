#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF 999999999.9
#define PI acos(-1.0)
struct Point
{
	double x, y, dis;
}pt[1005], stack[1005], p0;
int top, tot;
long l,l0;

double Dis(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int Cmp_PolarAngel(Point p1, Point p2, Point pb)
{
	double delta=(p1.x-pb.x)*(p2.y-pb.y)-(p2.x-pb.x)*(p1.y-pb.y);
	if (delta<0.0) return 1;
	else if (delta==0.0) return 0;
		else return -1;
}

bool Is_LeftTurn(Point p3, Point p2, Point p1)
{
	int type=Cmp_PolarAngel(p3, p1, p2);
	if (type<0) return true;
	return false;
}

int Cmp(const Point &a1, const Point &a2)
{
	int type=Cmp_PolarAngel(a1, a2, p0);
	if (type<0) return 1;
	else if (type==0)
	{
		if (a1.dis<a2.dis) return 1;
		else return 0;
	}
	else return 0;
}

double f(Point a1,Point a2,Point a3)
{
    double l1=sqrt((a1.x-a2.x)*(a1.x-a2.x)+(a1.y-a2.y)*(a1.y-a2.y));
    double l2=sqrt((a3.x-a2.x)*(a3.x-a2.x)+(a3.y-a2.y)*(a3.y-a2.y));
    double l3=(a1.x-a2.x)*(a3.x-a2.x)+(a1.y-a2.y)*(a3.y-a2.y);
    return acos(l3/l1/l2);
}

void Solve(int n)
{
	int i, k;
	p0.x=p0.y=INF;
	for (i=0;i<n;i++)
	{
		scanf("%lf %lf",&pt[i].x, &pt[i].y);
		if (pt[i].y < p0.y)
		{
			p0.y=pt[i].y;
			p0.x=pt[i].x;
			k=i;
		}
		else if (pt[i].y==p0.y)
		{
			if (pt[i].x<p0.x)
			{
				p0.x=pt[i].x;
				k=i;
			}
		}
	}
	pt[k]=pt[0];
	pt[0]=p0;
	for (i=1;i<n;i++)
		pt[i].dis=Dis(pt[i].x,pt[i].y, p0.x,p0.y);
	sort(pt+1, pt+n, Cmp);
	//去掉极角相同的点
	tot=1;
	for (i=2;i<n;i++)
	if (Cmp_PolarAngel(pt[i], pt[i-1], p0))
		pt[tot++]=pt[i-1];
	pt[tot++]=pt[n-1];
	//求凸包
	top=1;
	stack[0]=pt[0];
	stack[1]=pt[1];
	for (i=2;i<tot;i++)
	{
		while (top>=1 && Is_LeftTurn(pt[i], stack[top], stack[top-1])==false)
			top--;
		stack[++top]=pt[i];
	}
	l0=0;
	for(i=0;i<top;i++)
		l0+=(long)sqrt((stack[i+1].x-stack[i].x)*(stack[i+1].x-stack[i].x)+(stack[i+1].y-stack[i].y)*(stack[i+1].y-stack[i].y));
	l0+=(long)sqrt((stack[top].x-stack[0].x)*(stack[top].x-stack[0].x)+(stack[top].y-stack[0].y)*(stack[top].y-stack[0].y));
	for(i=0;i<top-1;i++)
		l0+=(long)(l*f(stack[i],stack[i+1],stack[i+2]));
	l0+=(long)(l*f(stack[top-1],stack[top],stack[0]))+(long)(l*f(stack[top],stack[0],stack[1]));
	printf("%ld\n",l0);
}
int main ()
{
	int n;
	while (scanf("%d%ld",&n,&l)!=EOF)
		Solve(n);

	return 0;
}