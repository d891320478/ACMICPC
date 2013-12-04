#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INF 999999999.9
#define PI acos(-1.0)
struct Point
{
	double x, y, dis;
}pt[1005], stack[1005], p0;
int top, tot;
double Dis(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int Cmp_PolarAngel(struct Point p1, struct Point p2, struct Point pb)
{
	double delta=(p1.x-pb.x)*(p2.y-pb.y)-(p2.x-pb.x)*(p1.y-pb.y);
	if (delta<0.0) return 1;
	else if (delta==0.0) return 0;
		else return -1;
}
bool Is_LeftTurn(struct Point p3, struct Point p2, struct Point p1)
{
	int type=Cmp_PolarAngel(p3, p1, p2);
	if (type<0) return true;
		return false;
}
int Cmp(const void*p1, const void*p2)
{
	struct Point*a1=(struct Point*)p1;
	struct Point*a2=(struct Point*)p2;
	int type=Cmp_PolarAngel(*a1, *a2, p0);
	if (type<0) return -1;
	else 
	if (type==0)
	{
		if (a1->dis<a2->dis) return -1;
		else if (a1->dis==a2->dis) return 0;
			else return 1;
	}
	else return 1;
}
void Solve(int n,int start)
{
	int i, k=start;
	
	pt[k]=pt[0];
	pt[0]=p0;
	for (i=1;i<n;i++)
		pt[i].dis=Dis(pt[i].x,pt[i].y, p0.x,p0.y);
	qsort(pt+1, n-1, sizeof(struct Point), Cmp);
	tot=1;
	for (i=2;i<n;i++)
		if (Cmp_PolarAngel(pt[i], pt[i-1], p0)) pt[tot++]=pt[i-1];
	pt[tot++]=pt[n-1];
	top=1;
	stack[0]=pt[0];
	stack[1]=pt[1];
	for (i=2;i<tot;i++)
	{
		while (top>=1 && Is_LeftTurn(pt[i], stack[top], stack[top-1])==false) top--;
		stack[++top]=pt[i];
	}
	for(i=0;i<=top;i++)
		printf("(%.0lf,%.0lf)\n",stack[i].x,stack[i].y);
}
int main ()
{
	int n=0,k;
	p0.x=p0.y=0;
	freopen("1.in","r",stdin);
	while (scanf("%lf %lf",&pt[n].x, &pt[n].y)!=EOF)
	{
		n++;
	}
	Solve(n,0);
	return 0;
}