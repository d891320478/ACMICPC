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
#define EPS 1e-8
#define PI 3.141592653589793
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 40
#define MM 10010
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
int n,f;
double r[MM];
int main()
{
	int tt=fastget();
	while (tt--)
	{
		n=fastget();
		f=fastget()+1;
		double l0=0,r0=0,mid;
		for(int i=1;i<=n;i++) scanf("%lf",&r[i]),r0+=r[i]*r[i]*M_PI;
		for(int _i=1;_i<=1000;_i++)
		{
			mid=(l0+r0)/2;
			int sum=0;
			for(int i=1;i<=n;i++)
				sum+=(int)(r[i]*r[i]*M_PI/mid+EPS);
			if(sum>=f) l0=mid;
			else r0=mid;
		}
		printf("%.4f\n",l0);
	}
	return 0;
}