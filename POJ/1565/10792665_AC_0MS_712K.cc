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
string s;
long long a[35];
int i,j;
int main ()
{
	a[0]=1;
	for(i=1;a[i-1]<=2147483647;i++)
		a[i]=a[i-1]*2+1;
	while (cin>>s && s!="0")
	{
		long long ans=0;
		int ls=s.size();
		for(i=ls-1,j=0;i>=0;i--) ans+=a[j++]*(s[i]-'0');
		printf("%lld\n",ans);
	}
	
	return 0;
}