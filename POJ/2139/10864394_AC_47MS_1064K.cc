#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 310
#define M 10010
int n,m,a[N][N],b[N],c[N];
int i,j,k;
int main ()
{
	memset(a,-1,sizeof(a));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) a[i][i]=0;
	while (m--)
	{
		scanf("%d",&b[0]);
		for(i=1;i<=b[0];i++)
		{
			scanf("%d",&b[i]);
			for(j=1;j<i;j++)
				a[b[j]][b[i]]=a[b[i]][b[j]]=1;
		}
	}
	for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		if(a[i][k]!=-1 && a[k][j]!=-1)
		if(a[i][j]==-1 || a[i][j]>a[i][k]+a[k][j])
			a[i][j]=a[i][k]+a[k][j];
	for(i=1;i<=n;i++)
	{
		c[i]=0;
		for(j=1;j<=n;j++)
			c[i]+=a[i][j];
	}
	printf("%d\n",c[min_element(c+1,c+1+n)-c]*100/(n-1));
	
	return 0;
}