#include <cstdio>
#include <cstring>
#define SET(a,b) memset(a,b,sizeof(a))
#define N 55
int a[N][N],dis[N];
int n,m,value,i,j,k;
bool vis[N];
int main ()
{
	while (scanf("%dis",&n) && n)
	{
		scanf("%dis",&m);
		SET(a,0x3f);
		SET(vis,0);
		while (m--)
		{
			scanf("%d%d%d",&i,&j,&k);
			if(a[i][j]>k)a[i][j]=a[j][i]=k;
		}
		vis[1]=1;
		value=0;
		for(i=1;i<=n;i++)
			dis[i]=a[1][i];
		for(i=1;i<n;i++)
		{
			int min=100000000;
			for(j=1;j<=n;j++)
				if(dis[j]<min && ! vis[j])
				{
					k=j;
					min=dis[j];
				}
			vis[k]=1;
			value+=dis[k];
			for(j=1;j<=n;j++)
				if(! vis[j])
				if(dis[j]>a[k][j])
					dis[j]=a[k][j];
		}
		printf("%d\n",value);
	}
	
	return 0;
}