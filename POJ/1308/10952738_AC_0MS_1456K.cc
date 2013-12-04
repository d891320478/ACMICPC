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
#define N 100010
#define M 10010
int n,u,v,pnt[N],vis[N],sum,s0;
int flag=1;
int find(int x)
{
	return x==pnt[x]?x:(pnt[x]=find(pnt[x]));
}
int main ()
{
	for(int i=1;i<=100000;i++) pnt[i]=i;
	int ttt=0;
	while (1)
	{
		scanf("%d%d",&u,&v);
		if(u==-1 && v==-1) break;
		if(u==0 && v==0)
		{
			flag=((sum-1==s0 && flag) || (sum==0 && s0==0));
			printf("Case %d is ",++ttt);
			printf(flag?"a tree.\n":"not a tree.\n");
			flag=1; sum=s0=0;
			for(int i=1;i<=100000;i++) pnt[i]=i,vis[i]=0;
			continue;
		}
		if(! flag) continue;
		if(! vis[u]) sum++;
		if(! vis[v]) sum++;
		vis[u]=vis[v]=1;
		s0++;
		int x=find(u),y=find(v);
		if(x==y) flag=0;
		pnt[y]=x;
	}
	
	return 0;
}