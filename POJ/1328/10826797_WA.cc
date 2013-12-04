#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 10010
#define M 10010
struct point
{
	double x;
	int idx;
}p[N];
double d,x,y;
int n;
bool operator< (const point &a,const point &b)
{
	return a.x<b.x;
}
int main ()
{
	int tttt=0,i;
	while (scanf("%d%lf",&n,&d))
	{
		int cnt=0,flag=1;
		if(n==0 && d==0)break;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&x,&y);
			if(y>d){flag=0; continue;}
			p[cnt].idx=1;
			p[cnt++].x=x-sqrt(d*d-y*y);
			p[cnt].idx=-1;
			p[cnt++].x=x+sqrt(d*d-y*y);
		}
		if(! flag)printf("Case %d: -1\n",++tttt);
		else
		{
			sort(p,p+cnt);
			int ans=0;
			for(i=1;i<=cnt;i++)
				if(p[i].idx==-1 && p[i-1].idx==1)ans++;
			printf("Case %d: %d\n",++tttt,ans);
		}
	}
	
	return 0;
}