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
double a,b,c,l,m,n,v,t1,t2,t3;
int main()
{
	while (scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&l,&n,&m)!=-1)
	{
		t2=
		v=sqrt(4*a*a*b*b*c*c
			-a*a*pow(b*b+c*c-m*m,2.0)
			-b*b*pow(c*c+a*a-n*n,2.0)
			-c*c*pow(a*a+b*b-l*l,2.0)
			+(a*a+b*b-l*l)*(b*b+c*c-m*m)*(c*c+a*a-n*n))/12;
		printf("%f\n",v);
	}
	return 0;
}