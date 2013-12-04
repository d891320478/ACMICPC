#include <cstdio>

long a[110][110],b[110],value=0;
int d[110][110],f[110]={0,1},u=1;
int i,j,k,n,q;

void dfs(int s)
{
	int i,j;

	for(i=1;i<=d[s][0];i++)
	{
		if(! f[d[s][i]])
		{
			f[d[s][i]]=1;
			u++;
			for(j=1;j<=n;j++)
				if(! f[j])
				if(b[j]>a[d[s][i]][j])b[j]=a[d[s][i]][j];
			dfs(i);
		}
	}
}

int main ()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		scanf("%ld",&a[i][j]);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&j,&k);
		d[j][++d[j][0]]=k;
		d[k][++d[k][0]]=j;
	}
	for(i=1;i<=n;i++)
		b[i]=a[1][i];
	dfs(1);
	while(u<n)
	{
		long maxx=1<<30;
		for(i=1;i<=n;i++)
			if(! f[i])
			if(maxx>b[i])
			{
				maxx=b[i];
				j=i;
			}
		f[j]=1;
		u++;
		value+=b[j];
		dfs(j);
		for(i=1;i<=n;i++)
			if(! f[i])
			if(b[i]>a[j][i])b[j]=a[j][i];
	}
	printf("%ld\n",value);
	
	return 0;
}