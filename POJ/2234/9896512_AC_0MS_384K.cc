#include <cstdio>

long a,b,c,n;

int main ()
{
	while(scanf("%ld",&n)!=EOF)
	{
		scanf("%ld",&c);
		for(int i=2;i<=n;i++)
		{
			scanf("%ld",&b);
			c=c^b;
		}
		if(!c)printf("No\n");
		else printf("Yes\n");
	}
	
	return 0;
}
