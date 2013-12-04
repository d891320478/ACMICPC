#include <cstdio>
int t,n,a[101],i,j;
int main()
{
	for(i=1;i<=100;i++)
	for(j=1;j<=i;j++)
		a[i]+=(i%j==0);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int ans=0;
		for(i=1;i<=n;i++)
			if(a[i]%2)ans++;
		printf("%d\n",ans);
	}
	
	return 0;
}