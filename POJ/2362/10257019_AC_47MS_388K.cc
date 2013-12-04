#include <cstdio>
int a[21],n,sum;
bool flag,f[21];
void dfs(int k,int l,int s)
{
	if(s>=4 || flag)
	{
		flag=1;
		return;
	}
	if(k>=n)return;
	if(l==0)
	{
		for(int i=0;i<n;i++)
			if(! f[i])
			{
				f[i]=1;
				dfs(i,sum/4-a[i],s+1);
				f[i]=0;
				break;
			}
	}
	else
	{
		for(int i=k+1;i<n;i++)
			if(! f[i])
			if(l-a[i]>=0)
			{
				f[i]=1;
				dfs(i,l-a[i],s);
				f[i]=0;
			}
	}
}
int main ()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
			f[i]=0;
		}
		if(sum%4){ printf("no\n");continue; }
		flag=0; f[0]=1;
		dfs(0,sum/4-a[0],1);
		if(flag)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}