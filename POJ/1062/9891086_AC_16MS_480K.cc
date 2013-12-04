#include <cstdio>
#include <cstring>

long n,k;
long a[110][110]={0},b[110],c[110],e,f,g,h[110][110],ma;

void map(long s,long t)
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(a[i][j])
		if(c[i]>=s && c[i]<=t && c[j]>=s && c[j]<=t) h[i][j]=1;
}

void dij()
{
	int u[110]={0,1},l;
	long d[110];
	
	d[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(h[1][i])d[i]=a[1][i];
		else d[i]=1<<30;
	}
	for(int i=1;i<n;i++)
	{
		long maxx=1<<30;
		
		for(int j=1;j<=n;j++)
			if(! u[j])
			if(maxx>d[j])
			{
				l=j;
				maxx=d[j];
			}
		u[l]=1;
		for(int j=1;j<=n;j++)
			if(h[l][j])
			if(d[j]>d[l]+a[l][j])d[j]=d[l]+a[l][j];
	}
	for(int i=1;i<=n;i++)
		ma=ma<(d[i]+b[i])?ma:(d[i]+b[i]);
}

int main ()
{
	scanf("%ld%ld",&k,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%ld%ld%ld",&b[i],&c[i],&e);
		for(int j=1;j<=e;j++)
		{
			scanf("%ld%ld",&f,&g);
			a[i][f]=g;
		}
	}
	ma=b[1];
	for(int i=0;i<=k;i++)
	if(c[1]-i>=0)
	{
		memset(h,0,sizeof(h));
		map(c[1]-i,c[1]-i+k);
		dij();
	}
	printf("%ld\n",ma);
	
	return 0;
}