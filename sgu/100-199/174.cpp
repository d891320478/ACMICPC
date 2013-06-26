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
#define N 400010
map<pair<int,int>,int> Q;
int poi=0;
int n;
int flag=0;
int pnt[N];
int find(int x)
{
	if(x==pnt[x]) return x;
	return pnt[x]=find(pnt[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<N;i++) pnt[i]=i;
	for(int i=1;i<=n;++i)
	{
		int a,b,c,d;
		int u,v;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(Q.find(make_pair(a,b))==Q.end()) u=Q[make_pair(a,b)]=++poi;
		else u=Q[make_pair(a,b)];
		if(Q.find(make_pair(c,d))==Q.end()) v=Q[make_pair(c,d)]=++poi;
		else v=Q[make_pair(c,d)];
		if(a==c && b==d)
		{
			printf("%d\n",i);
			return 0;
		}
		u=find(u);
		//printf("---\n");
		v=find(v);
		//printf("---\n");
		if(u-v) pnt[v]=u;
		else
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
