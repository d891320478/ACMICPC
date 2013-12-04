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
#define N 50
#define M 1610
int n,a[N],sum;
int dp[M][M];
int f(int a,int b,int c)
{
	double p=(a+b+c)/2.0;
	if(p*(p-a)*(p-b)*(p-c)>=0)
		return (int)(100*sqrt(p*(p-a)*(p-b)*(p-c)));
	else return -1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=sum;j>=0;j--)
	for(int k=j;k>=0;k--)
	{
		if(j-a[i]>=0) dp[j][k]=dp[j][k] || dp[j-a[i]][k];
		if(k-a[i]>=0) dp[j][k]=dp[j][k] || dp[j][k-a[i]];
	}
	int ans=-1;
	for(int i=1;i<=sum;i++)
	for(int j=1;j<=sum;j++)
	if(dp[i][j])
	{
		int k=sum-i-j,cr=f(i,j,k);
		ans=max(ans,cr);
	}
	printf("%d\n",ans);
	return 0;
}