#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[31],d[31][31];
int n,i,j;
int main ()
{
	while (scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				scanf("%d",&a[j]);
				d[i][j]=a[j]+max(d[i-1][j-1],d[i-1][j]);
			}
		}
		int ans=0;
		for(i=1;i<=n;i++)
			ans=max(ans,d[n][i]);
		printf("%d\n",ans);
	}
	
	return 0;
}