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
#define N 30010
#define M 10010
double l,ans,c[N],p[N],d[N],sum,w;
int n,m;
int search(int l,int r,double x)
{
	int mid;
	while (l<r)
	{
		mid=(l+r+1)>>1;
		if(d[mid]>x) r=mid-1;
		else l=mid;
	}
	return l;
}
int main()
{
	while (scanf("%lf",&l)!=-1)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lf",&p[i]);
		scanf("%d",&m);
		c[1]=0;
		for(int i=2;i<=m;i++) scanf("%lf",&c[i]);
		ans=-1;
		for(double k=0;k+c[m]<=l;k+=0.5)
		{
			for(int i=1;i<=m;i++)
				d[i]=k+c[i];
			sum=0;
			for(int i=1;i<=n;i++)
			{
				if(p[i]<=d[1])
				{
					sum+=fabs(p[i]-d[1]);
					continue;
				}
				if(p[i]>=d[m])
				{
					sum+=fabs(p[i]-d[m]);
					continue;
				}
				int x=search(1,m,p[i]);
				sum+=min(fabs(p[i]-d[x]),fabs(p[i]-d[x+1]));
			}
			if(ans<sum)
			{
				ans=sum;
				w=k;
			}
		}
		printf("%f %f\n",w,ans);
	}
	return 0;
}
