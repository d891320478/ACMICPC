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
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 100010
#define M 22
long long val[N],mn[M][N];
long long sum[N];
int n,p[M],idx[N];
void init()
{	idx[0]=-1;
	for(int i=1;i<N;i++)	idx[i]=idx[i-1]+(!(i&(i-1)));
	for(int i=0;i<M;i++)	p[i]=1<<i;
}
void rmq()
{
	for(int i=1;i<=n;i++) mn[0][i]=val[i];
	for(int i=1;p[i]<=n;i++)
	for(int j=1;j+p[i]-1<=n;j++)
		mn[i][j]=min(mn[i-1][j],mn[i-1][j+p[i-1]]);
}
int main()
{
	scanf("%d",&n);
	sum[0]=0;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&val[i]);
		sum[i]=sum[i-1]+val[i];
	}
	init();	rmq();
	long long ans=-1,al,ar;
	int l,r,mid,il,ir,t;
	for(int i=1;i<=n;i++)
	{
		l=1,r=i;
		while (l<r)
		{
			mid=l+r>>1;
			t=idx[i-mid+1];
			if(val[i]>min(mn[t][mid],mn[t][i-p[t]+1])) l=mid+1;
			else r=mid;
		}
		il=l;
		l=i,r=n;
		while (l<r)
		{
			mid=l+r+1>>1;
			t=idx[mid-i+1];
			if(val[i]>min(mn[t][i],mn[t][mid-p[t]+1])) r=mid-1;
			else l=mid;
		}
		ir=l;
		//printf("%lld %lld\n",il,ir);
		if(ans<(sum[ir]-sum[il-1])*val[i])
		{
			ans=(sum[ir]-sum[il-1])*val[i];
			al=il,ar=ir;
		}
	}
	printf("%lld\n%lld %lld\n",ans,al,ar);
	
	return 0;
}