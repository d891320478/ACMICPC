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
#include<vector>
#include<utility>
using namespace std;
#define INF (1<<30)
#define EPS 1e-12
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 40
#define MM 10010
double l,n,c,_l;
double delta;
int main()
{
	while (scanf("%lf%lf%lf",&l,&n,&c) && l!=-1)
	{
		_l=(1+n*c)*l;
		if(fabs(_l-l)<EPS)
		{
			printf("0.000\n");
			continue;
		}
		double l0=0,r0=PI,mid,r;
		while (fabs(r0-l0)>EPS)
		{
			mid=(l0+r0)/2.0;
			double nm=sin(mid)/mid-l/_l;
			if(nm>EPS) l0=mid;
			else r0=mid;
		}
		r=_l/2.0/l0;
		printf("%.3f\n",r-r*cos(l0));
	}
	return 0;
}