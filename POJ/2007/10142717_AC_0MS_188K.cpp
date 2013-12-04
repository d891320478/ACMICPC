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
}pt[1005];

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

int Cmp(const Point &a1, const Point &a2)
{
	int type=Cmp_PolarAngel(a1, a2, pt[0]);
	if (type<0) return 1;
	else
	if (type==0)
		if (a1.dis<a2.dis) return 1;
		else return 0;
	else return 0;
}

void Solve(int n)
{
	int i;
	for (i=1;i<n;i++)
		pt[i].dis=Dis(pt[i].x,pt[i].y, pt[0].x,pt[0].y);
	sort(pt+1, pt+n, Cmp);
	for(i=0;i<n;i++)
		printf("(%.0lf,%.0lf)\n",pt[i].x,pt[i].y);
}
int main ()
{
	int n=0;
	//freopen("1.in","r",stdin);
	while (scanf("%lf%lf",&pt[n].x,&pt[n].y)!=EOF)
		n++;
	Solve(n);

	return 0;
}