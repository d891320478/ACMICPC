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
#define EPS 1e-4
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 10010
#define M 10010
int n,k;
double c[N],a[N],b[N];
double l,r,mid,sum;
int main ()
{
	int i;
	while (scanf("%d%d",&n,&k) && (n || k))
	{
		for(i=1;i<=n;i++) scanf("%lf",&a[i]);
		for(i=1;i<=n;i++) scanf("%lf",&b[i]);
		l=0; r=1;
		while (fabs(r-l)>EPS)
		{
			mid=(l+r)/2;
			for(i=1;i<=n;i++) c[i]=a[i]-b[i]*mid;
			sort(c+1,c+1+n);
			sum=0;
			for(i=k+1;i<=n;i++) sum+=c[i];
			//printf("sum  %.3f\n",sum);
			if(sum>=0) l=mid;
			else r=mid;
		}
		printf("%.0f\n",l*100);
	}
	
	return 0;
}