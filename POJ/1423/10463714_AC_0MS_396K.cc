#include <cstdio>
#include <cmath>
#define PI acos(-1.0)
#define e exp(1.0)
long long n,ans;
int main ()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lld",&n);
		ans=1+(long long)(log10(sqrt(2*n*PI))+n*log10(n/e));
		printf("%lld\n",ans);
	}
	
	return 0;
}
