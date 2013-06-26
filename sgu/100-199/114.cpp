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
#define MM 15010
int n,sum;
struct po
{
	int x,p;
}p[MM];
int cmp(po a,po b)
{
	return a.x<b.x;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].p);
		sum+=p[i].p;
	}
	sum=sum+1>>1;
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(sum-p[i].p>0) sum-=p[i].p;
		else
		{
			printf("%d.00000\n",p[i].x);
			break;
		}
	}
	return 0;
}
