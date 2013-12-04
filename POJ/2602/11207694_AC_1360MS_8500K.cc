#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 1000010
#define M 10010
int n,a[N],b[N];
int main()
{
	scanf("%d",&n);
	for(int i=n;i>0;i--) scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++)
	{
		a[i]+=b[i];
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	if(a[n+1]) n++;
	for(int i=n;i>0;i--) putchar('0'+a[i]);
	printf("\n");
	return 0;
}