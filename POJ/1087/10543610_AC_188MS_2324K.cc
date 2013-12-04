#include<cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
using namespace std;
map<string,int> ct,cz,sumt,sumz;
string a[610],b[610],c,d[610],e[610];
int f[610][610],h[610],vh[610];
int m,n,ans;
int s,t;
int min(int x,int y)
{	if (x<y) return x;		else return y;	}
int dfs(int v,int flow)
{
	int i,j,k,minh;
	if (v==t) return flow;
	minh=n;	k=0;
	for (i=1;i<=n;i++)
	if (f[v][i]>0)
	{
		if (h[v]==h[i]+1) {k=dfs(i,min(flow,f[v][i]));}
		if (h[s]>n) return 0;
		if (k>0)	{	f[v][i]-=k;	f[i][v]+=k;		return k;		} 
		minh=min(minh,h[i]);
	}
	vh[h[v]]--;	if (vh[h[v]]==0) h[s]=n+1;
	h[v]=minh+1;	vh[h[v]]++;
	return 0;
}
int main()
{
	int i,j,k,top;
	while(scanf("%d",&m)!=EOF)
	{
		memset(f,0,sizeof(f));
		memset(vh,0,sizeof(vh));
		memset(h,0,sizeof(h));
		ct.clear();
		cz.clear();
		s=1;t=2;top=2;
		for(i=1;i<=m;i++)
		{
			cin>>a[i];
			if(cz[a[i]]==0) cz[a[i]]=++top;
			f[cz[a[i]]][t]++;
		}
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			cin>>c>>b[i];
			if(ct[b[i]]==0) ct[b[i]]=++top;
			f[s][ct[b[i]]]++;
			if(cz[b[i]])f[ct[b[i]]][cz[b[i]]]=10000;
		}
		scanf("%d",&k);
		for(i=1;i<=k;i++)
		{
			cin>>d[i]>>e[i];
			if(ct[d[i]]==0)ct[d[i]]=++top;
			if(ct[e[i]]==0)ct[e[i]]=++top;
			f[ct[d[i]]][ct[e[i]]]=10000;
			if(cz[d[i]])f[ct[d[i]]][cz[d[i]]]=10000;
			if(cz[e[i]])f[ct[e[i]]][cz[e[i]]]=10000;
		}
		//scanf("%d%d",&s,&t);
		n=top;
		vh[s]=n+1;ans=0;
		while (h[s]<=n) ans=ans+dfs(s,2000000000);
		printf("%d\n",m-ans);
	}
	return 0;
}