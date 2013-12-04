#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int N=1510;
const int M=2250010;
const int inf=1<<30;
int head[N];
struct Edge
{
	int v,next,w;
}edge[M];
int cnt,n,s,t;
void addedge(int u,int v,int w)
{
	edge[cnt].v=v;	edge[cnt].w=w;	edge[cnt].next=head[u];
	head[u]=cnt++;
	edge[cnt].v=u;	edge[cnt].w=0;	edge[cnt].next=head[v];
	head[v]=cnt++;
}
int sap()
{
	int pre[N],cur[N],dis[N],gap[N];
	int flow=0,aug=inf,u;
	bool flag;
	for(int i=1;i<=2*n;i++)
	{
		cur[i]=head[i];
		gap[i]=dis[i]=0;
	}
	gap[s]=2*n;
	u=pre[s]=s;
	while(dis[s]<2*n)
	{
		flag=0;
		for(int &j=cur[u];j!=-1;j=edge[j].next)
		{
			int v=edge[j].v;
			if(edge[j].w>0&&dis[u]==dis[v]+1)
			{
				flag=1;
				if(edge[j].w<aug) aug=edge[j].w;
				pre[v]=u;
				u=v;
				if(u==t)
				{
					flow+=aug;
					while(u!=s)
					{      
						u=pre[u];
						edge[cur[u]].w-=aug;
						edge[cur[u]^1].w+=aug;
					}
					aug=inf;
				}
				break;
			}
		}
		if(flag) continue;
		int mindis=2*n;
		for(int j=head[u];j!=-1;j=edge[j].next)
		{
			int v=edge[j].v;
			if(edge[j].w>0&&dis[v]<mindis)            
			{
				mindis=dis[v];
				cur[u]=j;
			}
		}
		if((--gap[dis[u]])==0) break;
		gap[dis[u]=mindis+1]++;  
		u=pre[u];
	}
	return flow;
}
int main()
{
	int m,f,d,i,j,k,l,c;
    while(scanf("%d%d%d",&m,&f,&d)!=-1)
    {
        memset(head,-1,sizeof(head));
        s=1; t=n=2*m+f+d+2; cnt=0;
        for(i=2;i<=m+1;i++)
        	addedge(s,i,1);
        for(i=1;i<=d;i++)
        	addedge(2*m+f+1+i,t,1);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&k,&l);
            for(j=1;j<=k;j++)
            {
            	int ue;
            	scanf("%d",&ue);
            	addedge(i+1,ue+2*m+1,1);
            	addedge(ue+2*m+1,i+m+1,1);
            }
            for(j=1;j<=l;j++)
            {
            	int ue;
            	scanf("%d",&ue);
            	addedge(i+m+1,ue+2*m+f+1,1);
            }
        }
        printf("%d\n",sap());
    }
}
