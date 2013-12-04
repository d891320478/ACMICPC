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
#define PI acos(-1)
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 32010
#define M 15010
int n;
int a[N];
int level[M];
int lowbit(int i)
{
	return i & (-i);
}
int sum(int x)
{
	int ans=0;
	while (x>0)
	{
		ans+=a[x];
		x-=lowbit(x);
	}
	return ans;
}
void update(int x)
{
	while (x<=32000)
	{
		a[x]++;
		x+=lowbit(x);
	}
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		//printf("  %d\n",sum(x));
		level[sum(x)]++;
		update(x);
	}
	for(int i=0;i<n;i++)
		printf("%d\n",level[i]);
	
	return 0;
}