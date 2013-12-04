#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
int n,a[N];
int main ()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i += 1)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int ans=0;
	for (int i = 1; i < n; i += 1)
	{
		ans+=abs(a[i]-a[i-1]);
	}
	printf("%d\n",ans);
	
	return 0;
}