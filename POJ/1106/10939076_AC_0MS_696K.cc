#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define PI acos(-1)
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
struct circle
{
	double x,y,r;
	int init(){return scanf("%lf %lf %lf",&x,&y,&r);}
}c;
struct point
{
	double x,y,k,dis;
	void init(){scanf("%lf %lf",&x,&y);}
}p[N],q[N];
int n,m;
double dist(circle a,point b)
{
	return sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0));
}
double xmult(circle a,point b,point c)
{
	return (c.x-a.x)*(b.y-a.y)-(c.y-a.y)*(b.x-a.x);
}
int main ()
{
	while (c.init())
	{
		if(c.r<=0) return 0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			q[i].init();
			q[i].dis=dist(c,q[i]);
		}
		m=0;
		for(int i=0;i<n;i++)
			if(c.r>=q[i].dis) p[m++]=q[i];
		int sum1,sum2,ans=0;
		for(int i=0;i<m;i++)
		{
			sum1=sum2=0;
			for(int j=0;j<m;j++)
			{
				if(xmult(c,p[i],p[j])>=0) sum1++;
				if(xmult(c,p[i],p[j])<=0) sum2++;
			}
			//printf("%d %D\n",sum1,sum2);
			ans=max(ans,max(sum1,sum2));
		}
		printf("%d\n",ans);
	}
	
	return 0;
}