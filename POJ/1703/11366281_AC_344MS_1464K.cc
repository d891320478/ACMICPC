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
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 100010
#define MM 10010
int pnt[NN],dg[NN];
int n,m;
int x,y;
char s[2];
int find(int x)
{
	if(x==pnt[x]) return x;
	return pnt[x]=find(pnt[x]);
}
void _union(int x,int y)
{
	x=find(x);
	y=find(y);
	pnt[y]=x;
}
int main()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) pnt[i]=i,dg[i]=0;
		while (m--)
		{
			scanf("%s%d%d",s,&x,&y);
			if(s[0]=='D')
			{
				if(dg[x]==0 && dg[y]==0)
				{
					dg[x]=y;
					dg[y]=x;
				}
				else if(dg[x]==0 && dg[y]!=0)
				{
					dg[x]=y;
					_union(x,dg[y]);
				}
				else if(dg[x]!=0 && dg[y]==0)
				{
					dg[y]=x;
					_union(y,dg[x]);
				}
				else
				{
					_union(x,dg[y]);
					_union(y,dg[x]);
				}
			}
			else if(find(x)==find(y)) puts("In the same gang.");
			else if(find(x)==find(dg[y])) puts("In different gangs.");
			else puts("Not sure yet.");
		}
	}
	return 0;
}