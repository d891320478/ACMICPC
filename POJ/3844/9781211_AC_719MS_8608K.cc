#include<stdio.h>
#include<string.h>


int c;
long long a[50010],d,n,sum[1000010],ans;


int main()

{
	scanf("%d",&c);
	while (c--)
	{
		scanf("%lld%lld",&d,&n);
		memset(sum,0,sizeof(sum));
		for (long i = 1; i <= n; i += 1)
		{
			scanf("%ld",&a[i]);
			a[i]=(a[i]+a[i-1])%d;
			sum[a[i]]++;
		}
		sum[0]++;
		ans=0;
		for (long i = 0; i < d; i += 1)
			ans+=sum[i]*(sum[i]-1)/2;
		printf("%lld\n",ans);
	}


	return 0;

}
