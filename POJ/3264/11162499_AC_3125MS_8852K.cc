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
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 500010
#define M 21
int n,m,val[N],mx[M][N],mn[M][N],p[M],idx[N];
void init()
{
	idx[0]=-1;
	for(int i=1;i<N;i++)
		idx[i]=idx[i-1]+(!(i&(i-1)));
	for(int i=0;i<M;i++)
		p[i]=1<<i;
}
void rmq()
{
	for(int i=1;i<=n;i++)
		mx[0][i]=mn[0][i]=i;
	for(int i=1;p[i]<=n;i++)
	for(int j=1;j+p[i]-1<=n;j++)
	{
		mx[i][j]=val[mx[i-1][j]]>val[mx[i-1][j+p[i-1]]]?mx[i-1][j]:mx[i-1][j+p[i-1]];
		mn[i][j]=val[mn[i-1][j]]<val[mn[i-1][j+p[i-1]]]?mn[i-1][j]:mn[i-1][j+p[i-1]];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	init();
	rmq();
	while (m--)
	{
		int l,r,t;
		scanf("%d%d",&l,&r);
		t=idx[r-l+1];
		printf("%d\n",max(val[mx[t][l]],val[mx[t][r-p[t]+1]])-min(val[mn[t][l]],val[mn[t][r-p[t]+1]]));
	}
	return 0;
}