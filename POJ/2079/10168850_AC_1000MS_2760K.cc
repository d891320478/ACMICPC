#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF 999999999.9
#define PI 3.141592653
struct point
{
	double x, y, dis;
}pt[50005], stack[50005], p0;
int top, tot;

double Dis(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int Cmp_PolarAngel(point p1, point p2, point pb)
{
	double delta=(p1.x-pb.x)*(p2.y-pb.y)-(p2.x-pb.x)*(p1.y-pb.y);
	if (delta<0.0) return 1;
	else if (delta==0.0) return 0;
		else return -1;
}

bool Is_LeftTurn(point p3, point p2, point p1)
{
	int type=Cmp_PolarAngel(p3, p1, p2);
	if (type<0) return true;
	return false;
}

int Cmp(const point &a1, const point &a2)
{
	int type=Cmp_PolarAngel(a1, a2, p0);
	if (type<0) return 1;
	else
	if (type==0)
		if (a1.dis<a2.dis) return 1;
		else return 0;
	else return 0;
}

void Solve(int n)
{
	int i, k;
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
}
double s(point p1,point p2,point p3)
{
	return fabs((p1.x-p3.x)*(p2.y-p3.y)-(p2.x-p3.x)*(p1.y-p3.y));
}
void Rotate(point *ch,int m)
{
	if(m<3)
	{
		printf("0.00\n");
		return;
	}
	int i,j,k;
	double ans=0.0,tmp;
	ch[m]=ch[0];
	for(i=0;i<m;i++)
	{
		j=(i+1)%m; k=(j+1)%m;
		while(j!=k && i!=k)
		{
			while(s(ch[i],ch[j],ch[k+1])>s(ch[i],ch[j],ch[k])) k=(k+1)%m;
			tmp=s(ch[i],ch[j],ch[k]);
			ans=ans>tmp?ans:tmp;
			j=(j+1)%m;
		}
	}
	printf("%.2f\n",ans/2.0);
}
int main ()
{
	int n;
	while (scanf("%d",&n) && n!=-1)
	{
		Solve(n);
		Rotate(stack,top+1);
	}
	return 0;
}