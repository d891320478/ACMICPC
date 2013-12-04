#include <cstdio>
#include <cstring>
#define N 210
int d[N],a[N][N],s,t,n,i,j,k,v;
bool vis[N];
int main ()
{
	scanf("%d%d%d",&n,&s,&t);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		a[i][j]=1600000000;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		for(k=1;k<=j;k++)
		{
			scanf("%d",&v);
			if(k==1)a[i][v]=0;
			else a[i][v]=1;
		}
		a[i][i]=0;
		vis[i]=0;
	}
	vis[s]=1;
	for(i=1;i<=n;i++)
		d[i]=a[s][i];
	for(i=1;i<n;i++)
	{
		int min=1600000000;
		for(j=1;j<=n;j++)
			if(! vis[j])
			if(min>d[j])
			{
				min=d[j];
				k=j;
			}
		vis[k]=1;
		for(j=1;j<=n;j++)
			if(! vis[j])
			if(d[j]>d[k]+a[k][j])
				d[j]=d[k]+a[k][j];
	}
	if(d[t]<1600000000)printf("%d\n",d[t]);
	else printf("-1\n");
	return 0;
}