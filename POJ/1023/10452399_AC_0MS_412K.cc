#include <cstdio>
#include <cmath>
int n;
long long a;
char s[70],ans[70];
int main ()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%s%lld",&n,s,&a);
		for(int i=0;i<n;i++)
		{
			if(a%(long long)(pow(2,i+1))!=0)
			{
				if(s[n-i-1]=='p')a-=(long long)pow(2,i);
				else a+=(long long)pow(2,i);
				ans[n-i-1]='1';
			}
			else ans[n-i-1]='0';
		}
		ans[n]=0;
		if(!a)printf("%s\n",ans);
		else printf("Impossible\n");
	}
	
	return 0;
}