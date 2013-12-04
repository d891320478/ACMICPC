#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n,m,a[110][110],f[110][110],i,j,k,ans;
int main ()
{
	while (scanf("%d%d",&n,&m)!=-1)
	{
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
		for(i=1;i<=m;i++)
			f[1][i]=a[1][i];
		for(i=2;i<=n;i++)
		for(j=i;j+n-i<=m;j++)
		for(k=i;k<j;k++)
			f[i][j]=max(a[i][j]+f[i-1][k],f[i][j]);
		ans=-1600000000;
		for(i=1;i<=m;i++)
			ans=max(ans,f[n][i]);
		printf("%d\n",ans);
	}
	
	return 0;
}
