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
int n,k,a,i,sum,zzz,ans,yyy;
int flag=0;
int main ()
{
	scanf("%d%d",&n,&k);
	zzz=1;
	while (k--) zzz*=2;
	zzz-=1;
	sum=ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		sum=(sum+a)%zzz;
		if(a==zzz)flag=1;
		if(q[sum]==0) q[sum]=i;
		else
		{
			yyy=q[sum];
			ans=ans>i-yyy?ans:i-yyy;
		}
	}
	if(flag) ans=ans>1?ans:1;
	printf("%d\n",ans);
	
	return 0;
}