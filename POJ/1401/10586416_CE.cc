#include <cstdio>
int main ()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d",&n);
		int ans=0;
		while(n/5)
		{
			ans+=n/5;
			n/=5;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
