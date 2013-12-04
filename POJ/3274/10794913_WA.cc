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
#define N 100010
#define M 10010
map<int,int> q;
int n,k,a,i,sum[N],zzz,ans,yyy;
int flag=0;
int main ()
{
	scanf("%d%d",&n,&k);
	zzz=1;
	while (k--) zzz*=2;
	sum[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		sum[i]=(sum[i-1]+a)%zzz;
		if(q[sum[i]]==0) q[sum[i]]=i;
		else
		{
			yyy=q[sum[i]];
			ans=ans>i-yyy-1?ans:i-yyy-1;
		}
		if(sum[i]==0)flag=1;
	}
	ans=ans>1?ans:1;
	printf("%d\n",ans);
	
	return 0;
}