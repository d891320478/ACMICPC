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
#include<utility>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
int fastget()
{
	char c; int ans=0; c=getchar();
	int sign=1;
	while (! (c>='0' && c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while (c>='0' && c<='9')
	{
		ans=(ans<<3)+(ans<<1)+c-'0';
		c=getchar();
	}
	return ans*sign;
}
void fastput(int x)
{
	char s[12]; int a=0;
	if(x==0) puts("0");
	else
	{
		if(x<0) putchar('-'),x=-x;
		while (x) { s[a++]=x%10+'0'; x/=10; }
		for(a--;a>=0;a--) putchar(s[a]);
		putchar('\n');
	}
}
int n,m,c;
double dp[2][110];
double pre;
int main()
{
	while (scanf("%d",&c) && c)
	{
		scanf("%d%d",&n,&m);
		if(m>c || m>n || ((m+n)&1))
		{
			printf("0.000\n");
			continue;
		}
		if(n>10000)
		if(n%2) n=10001;
		else n=10000;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		for(int j=0;j<=min(c,i);j++)
		{
			dp[i&1][j]=0;
			if(j-1>=0) dp[i&1][j]+=dp[(i&1)^1][j-1]*(c-j+1.0)/c;
			if(j+1<=c) dp[i&1][j]+=dp[(i&1)^1][j+1]*(j+1.0)/c;
		}
		printf("%.3f\n",dp[n&1][m]+EPS);
	}
	return 0;
}