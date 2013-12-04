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
#define N 510
#define M 10010
int a[N][N],b[N][N],c[N][N],d[N],e[N],f[N];
int n,i,j;
int main ()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		d[i]=i;
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		scanf("%d",&b[i][j]);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		scanf("%d",&c[i][j]);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		e[i]+=d[j]*a[j][i];
		f[i]+=d[j]*c[j][i];
	}
	memset(d,0,sizeof(d));
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		d[i]+=e[j]*b[j][i];
	for(i=1;i<=n;i++) if(d[i]!=f[i])break;
	if(i<=n)printf("NO\n");
	else printf("YES\n");
	return 0;
}