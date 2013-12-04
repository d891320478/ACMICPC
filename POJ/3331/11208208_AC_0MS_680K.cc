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
#define N 10010
#define M 10010
int ans[366][10];
int n;
int a[N]={1,1};
int main()
{
	int tt;
	ans[0][1]=ans[1][1]=1;
	for(int i=2;i<=365;i++)
	{
		for(int j=1;j<=a[0];j++)
		{
			a[j]*=i;
			if(j>1)
			{
				a[j]+=a[j-1]/10;
				a[j-1]%=10;
			}
		}
		while (a[a[0]]>=10)
		{
			a[a[0]+1]=a[a[0]]/10;
			a[a[0]]%=10;
			++a[0];
		}
		for(int j=1;j<=a[0];j++)
			ans[i][a[j]]++;
	}
	scanf("%d",&tt);
	while (tt--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",ans[u][v]);
	}
	return 0;
}