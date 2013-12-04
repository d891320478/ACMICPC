#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
#define SET(a,b) memset(a,b,sizeof(a))
#define INF 1<<30
#define EPS 1e-8
#define N 10010
#define M 10000
int n,i;
long long a[N],b[N],c[N],ans=0;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	b[1]=c[1]=0;
	for(i=2;i<=n;i++) c[1]+=a[i]-a[1];
	for(i=2;i<=n;i++)
	{
		b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
		c[i]=c[i-1]-(n-i+1)*(a[i]-a[i-1]);
	}
	for(i=1;i<=n;i++)
		ans+=b[i]+c[i];
	printf("%lld\n",ans);
	
	return 0;
}