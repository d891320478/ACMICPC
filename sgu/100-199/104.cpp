#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n,m,a[110][110],f[110][110],i,j,k,ans;
int zzz[110];
void find(int x)
{
	if(x==0) return;
	for(int i=zzz[x+1]-1;i>x-1;i--)
	if(f[x][i]+a[x+1][zzz[x+1]]==f[x+1][zzz[x+1]])
	{
		zzz[x]=i;
		break;
	}
	find(x-1);
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		scanf("%d",&a[i][j]);
		f[i][j]=-1600000000;
	}
	for(i=1;i<=m-n+1;i++)
		f[1][i]=a[1][i];
	for(i=2;i<=n;i++)
	for(j=i;j+n-i<=m;j++)
	for(k=i-1;k<j;k++)
		f[i][j]=max(a[i][j]+f[i-1][k],f[i][j]);
	ans=-1600000000;
	for(i=1;i<=m;i++)
		if(ans<f[n][i])
		{
			ans=f[n][i];
			zzz[n]=i;
		}
	printf("%d\n",ans);
	find(n-1);
	for(int i=1;i<=n;i++)
	{
		printf("%d",zzz[i]);
		if(i<n) printf(" ");
		else printf("\n");
	}
	return 0;
}
