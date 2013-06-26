#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
double a,b,c,l,m,n;
int main()
{
	while (scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&l,&m,&n)!=-1)
	{
		double t1=acos((b*b+c*c-n*n)/(2*b*c));
		double t2=acos((a*a+c*c-m*m)/(2*a*c));
		double t3=acos((a*a+b*b-l*l)/(2*a*b));
		double t=(t1+t2+t3)/2.0;
		double v=1.0/3.0*a*b*c*sqrt(sin(t)*sin(t-t1)*sin(t-t2)*sin(t-t3));
		printf("%.4f\n",v);
	}
	return 0;
}
