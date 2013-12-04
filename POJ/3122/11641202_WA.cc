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
#define EPS 1e-4
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 40
#define MM 10010
int n,f;
double r[MM];
int main()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d %d",&n,&f);
		f++;
		double l0=0,r0=0,mid;
		for(int i=1;i<=n;i++) scanf("%lf",&r[i]),r0+=r[i]*r[i]*PI;
		while(fabs(r0-l0)>EPS)
		{
			mid=(l0+r0)/2;
			int sum=0;
			for(int i=1;i<=n;i++)
				sum+=(int)(r[i]*r[i]*PI/mid+EPS);
			if(sum>=f) l0=mid;
			else r0=mid;
		}
		printf("%.4f\n",l0);
	}
	return 0;
}