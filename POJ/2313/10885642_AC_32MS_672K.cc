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
int n,ans,a[N],b[N];
int mid(int a,int b,int c)
{
	int a1=min(min(a,b),c),a2=max(max(a,b),c);
	return a+b+c-a1-a2;
}
int main ()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i += 1)
	{
		scanf("%d",&a[i]);
	}
	b[0]=a[0];
	b[n-1]=a[n-1];
	for(int i=1;i<n-1;i++)
		b[i]=mid(a[i+1],b[i-1],a[i]);
	for(int i=0;i<n;i++)
		ans+=abs(a[i]-b[i]);
	for(int i=1;i<n;i++)
		ans+=abs(b[i]-b[i-1]);
	printf("%d\n",ans);
	
	return 0;
}