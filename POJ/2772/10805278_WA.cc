#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 10010
#define M 10010
int n,b;
long long a[N],f;
int main ()
{
	int tttt,i;
	scanf("%d",&tttt);
	while (tttt--)
	{
		scanf("%d%lld%d",&n,&f,&b);
		for(i=0;i<n;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			if(c==0) a[i]=0;
			if(c==f) a[i]=f;
			else a[i]=c+d*f;
		}
		sort(a,a+n);
		if(b%n==0) printf("%lld\n",a[n-1]+(b/n)*f*2-f);
		else printf("%lld\n",a[b%n-1]+(b/n)*f*2+f);
	}
	
	return 0;
}