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
int n,m;
int a[1010][1010];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
		scanf("%d",&a[i][j]);
	for(int j=m;j>0;--j)
	for(int i=n;i>0;--i)
	{
		if(i+1<=n)
		{
			if(i-1>0 && j+1<=m) a[i][j]=min(min(a[i+1][j],a[i-1][j+1]),a[i][j]);
			else if(j+1<=m) a[i][j]=min(a[i][j],min(a[i+1][j],a[i][j+1]));
			else a[i][j]=min(a[i][j],a[i+1][j]);
		}
		else if(i-1>0 && j+1<=m) a[i][j]=min(a[i][j],a[i-1][j+1]);
		else if(j+1<=m) a[i][j]=min(a[i][j],a[i][j+1]);
	}
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	{
		printf("%d",a[i][j]);
		if(j<m) printf(" ");
		else printf("\n");
	}
	return 0;
}
