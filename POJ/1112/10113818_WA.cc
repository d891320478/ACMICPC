#include <cstdio>
#include <cstdlib>

int n,a[110][110],b[110][110],g[110][110],i,j,k,l;
int s[110][2][110],u[110],point=0;
int maxp=1000;
int x[110],y[110],f[110][110],p[110][110][110];

void dfs(int t,int p,int q)
{
	int i;

	u[t]=1;
	s[q][p][++s[q][p][0]]=t;
	for(i=1;i<=g[t][0];i++)
		if(! u[g[t][i]])dfs(g[t][i],1-p,q);
}

int main ()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		while(scanf("%d",&k) && k)
			a[i][k]=1;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(i!=j)
	if(! (a[i][j] && a[j][i]))
	{
		g[i][++g[i][0]]=j;
		g[j][++g[j][0]]=i;
		b[i][j]=b[j][i]=1;
	}
	for(i=1;i<=n;i++)
		if(! u[i])
		{
			point++;
			dfs(i,0,point);
			for(j=1;j<s[point][0][0];j++)
			for(k=j+1;k<=s[point][0][0];k++)
				if(b[s[point][0][j]][s[point][0][k]])
				{
					printf("No solution\n");
					return 0;
				}
			for(j=1;j<s[point][1][0];j++)
			for(k=j+1;k<=s[point][1][0];k++)
				if(b[s[point][1][j]][s[point][1][k]])
				{
					printf("No solution\n");
					return 0;
				}
		}
	f[0][0]=1;
	for(i=1;i<=point;i++)
	for(j=n;j>=0;j--)
	for(k=n;k>=0;k--)
	{
		if(j-s[i][0][0]>=0 && k-s[i][1][0]>=0)
		if(f[j-s[i][0][0]][k-s[i][1][0]])
		{
			f[j][k]=1;
			p[i][j][k]=0;
		}
		if(j-s[i][1][0]>=0 && k-s[i][0][0]>=0)
		if(f[j-s[i][1][0]][k-s[i][0][0]])
		{
			f[j][k]=1;
			p[i][j][k]=1;
		}
	}
	for(i=1;i<=n;i++)
		if(f[i][n-i] && maxp>abs(i-n+i))
		{
			j=i;
			maxp=abs(i-n+i);
		}
	k=n-j;
	i=n;
	x[0]=y[0]=0;
	while(i)
	{
		if(p[i][j][k]==0)
		{
			for(l=1;l<=s[i][0][0];l++)
				x[x[0]+l]=s[i][0][l];
			x[0]+=l-1;
			j-=l-1;
			for(l=1;l<=s[i][1][0];l++)
				y[y[0]+l]=s[i][1][l];
			y[0]+=l-1;
			k-=l-1;
		}
		else
		{
			for(l=1;l<=s[i][1][0];l++)
				x[x[0]+l]=s[i][1][l];
			x[0]+=l-1;
			j-=l-1;
			for(l=1;l<=s[i][0][0];l++)
				y[y[0]+l]=s[i][0][l];
			y[0]+=l-1;
			k-=l-1;
		}
		i--;
	}
	printf("%d",x[0]);
	for(i=1;i<=x[0];i++)
		printf(" %d",x[i]);
	printf("\n");
	printf("%d",y[0]);
	for(i=1;i<=y[0];i++)
		printf(" %d",y[i]);
	printf("\n");
	
	return 0;
}