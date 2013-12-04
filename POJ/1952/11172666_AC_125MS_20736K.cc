#include <cstdio>
#define N 5010
int a[N],f[N],n,ans[N][N],next[N];
void add(int a,int b)
{
	ans[a][0]=ans[a][0]>ans[b][0]?ans[a][0]:ans[b][0];
	for(int i=1;i<=ans[a][0];i++)
	{
		ans[a][i]+=ans[b][i];
		ans[a][i+1]+=ans[a][i]/10;
		ans[a][i]%=10;
	}
	if(ans[a][ans[a][0]+1]>0) ans[a][0]++;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i]=ans[i][0]=1;
	}
	a[++n]=0;
	f[n]=ans[n][0]=1;
	for(int i=2;i<=n;i++)
	for(int j=1;j<i;j++)
		if(a[j]>a[i] && f[j]+1>f[i]) f[i]=f[j]+1;
	printf("%d ",f[n]-1);
	for(int i=1;i<=n;i++)
	{
		next[i]=-1;
		for(int j=i+1;j<=n;j++)
			if(a[i]==a[j])
			{
				next[i]=j;
				break;
			}
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1) ans[i][1]=1;
		else
		{
			for(int j=1;j<i;j++)
				if(f[j]+1==f[i] && a[j]>a[i] && (next[j]>i || next[j]==-1))
					add(i,j);
		}
	}
	for(int i=ans[n][0];i>0;i--)
		printf("%d",ans[n][i]);
	printf("\n");
	return 0;
}