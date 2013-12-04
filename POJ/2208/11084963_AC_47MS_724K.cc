#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
double a,b,c,l,m,n,v,t1,t2,t3,t;
int main()
{
	while (scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&l,&m,&n)!=-1)
	{
		t1=acos((b*b+c*c-n*n)/(2*b*c));
		t2=acos((a*a+c*c-m*m)/(2*a*c));
		t3=acos((a*a+b*b-l*l)/(2*a*b));
		t=(t1+t2+t3)/2;
		v=1.0/3.0*a*b*c*sqrt(sin(t)*sin(t-t1)*sin(t-t2)*sin(t-t3));
		printf("%f\n",v);
	}
	return 0;
}