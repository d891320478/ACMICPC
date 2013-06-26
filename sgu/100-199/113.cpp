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
#include<ctime>
#include<vector>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 40
#define MM 100010
int n,tt;
int f[MM]={1,1,0},a[MM];
int isp(int x)
{
	if(x<=100000) if(! f[x]) return 1;
	for(int i=1;a[i]*a[i]<=x;i++)
		if(x%a[i]==0) return 0;
	return 1;
}
int main()
{
	for(int i=2;i<=100000;i++)
	if(! f[i])
	{
		a[++a[0]]=i;
		for(int j=i+i;j<=100000;j+=i) f[j]=1;
	}
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d",&n);
		int flag=1;
		for(int i=1;flag && a[i]*a[i]<=n;i++)
		if(n%a[i]==0)
		if(isp(n/a[i])) flag=0;
		if(flag) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
