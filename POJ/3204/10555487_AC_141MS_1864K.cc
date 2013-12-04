#include<iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 510
#define M 10010
#define INF 0x7fffffff
struct node
{
    int u,v,next,val;
}s[M*2];
int level[N],p[N],que[N],out[N],ind;
inline void insert(int x,int y,int z)
{
    s[ind].u=x;	s[ind].v=y;    s[ind].val=z;    s[ind].next=p[x];
    p[x]=ind++;
    s[ind].u=y;	s[ind].v=x;    s[ind].val=0;    s[ind].next=p[y];
    p[y]=ind++;
}
int max_flow(int n,int source,int sink)
{
    int ret=0,h=0,r=0;
    while(1)
    {
        int i;
        for(i=0;i<n;++i)
            level[i]=0;
        h=0,r=0;
        level[source]=1;
        que[0]=source;
        while(h<=r)
        {
            int t=que[h++];
            for(i=p[t];i!=-1;i=s[i].next)
                if(s[i].val&&level[s[i].v]==0)
                {
                    level[s[i].v]=level[t]+1;
                    que[++r]=s[i].v;
                }
        }
        if(level[sink]==0)break;
        for(i=0;i<n;++i)out[i]=p[i];
        int q=-1;
        while(1)
        {
            if(q<0)
            {
                int cur=out[source];
                for(;cur!=-1;cur=s[cur].next)
                    if(s[cur].val&&out[s[cur].v]!=-1&&level[s[cur].v]==2)
                        break;
                if(cur>=0) que[++q]=cur,out[source]=s[cur].next;
                else break;
            }
            int u=s[que[q]].v;
            if(u==sink)
            {
                int dd=INF,index=-1;
                for(i=0;i<=q;i++)
                    if(dd>s[que[i]].val)
                        dd=s[que[i]].val,index=i;
                ret+=dd;
                for(i=0;i<=q;i++)
                {
                    s[que[i]].val-=dd;
                    s[que[i]^1].val+=dd;    
                }
                for(i=0;i<=q;i++)
                    if(s[que[i]].val==0)
                    {
                        q=index-1;
                        break;
                    }
            }
            else
            {
                int cur=out[u];
                for(;cur!=-1;cur=s[cur].next)
                    if(s[cur].val&&out[s[cur].v]!=-1&&level[u]+1==level[s[cur].v])
                        break;
              	if(cur!=-1)
                    que[++q]=cur,out[u]=s[cur].next;
                else
                    out[u]=-1,q--;
            }
        }
    }
    return ret;
}
int n,m;
int a[N][N];
bool vs[N],vt[N];
void dfs(int s,bool *vis)
{
	vis[s]=1;
	for(int i=0;i<n;i++)
		if(a[s][i])
		if(! vis[i])
			dfs(i,vis);
}
int main()
{
    scanf("%d %d",&n,&m);
    ind=0;
    memset(p,-1,sizeof(p));
    for(int i=0;i<m;i++)
    {
        int from,to,cost;
        scanf("%d %d %d",&from,&to,&cost);
        insert(from,to,cost);
    }
    max_flow(n,0,n-1);
    for(int i=0;i<ind;i+=2)
    	if(s[i].val>0) a[s[i].u][s[i].v]=1;
    dfs(0,vs);
    memset(a,0,sizeof(a));
	for(int i=0;i<ind;i+=2)
    	if(s[i].val>0) a[s[i].v][s[i].u]=1;
    dfs(n-1,vt);
    int ans=0;
    for(int i=0;i<ind;i+=2)
    	if(vs[s[i].u] && vt[s[i].v] && s[i].val==0)ans++;
    printf("%d\n",ans);
    return 0;
} 