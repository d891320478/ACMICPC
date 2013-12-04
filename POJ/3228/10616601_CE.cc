#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 500
#define M 300000
#define INF 0x7fffffff
struct node
{
    int v,next,val;
}s[M*2];
int level[N],p[N],que[N],out[N],ind;
inline void insert(int x,int y,int z)
{
    s[ind].v=y;    s[ind].val=z;    s[ind].next=p[x];
    p[x]=ind++;
    s[ind].v=x;    s[ind].val=0;    s[ind].next=p[y];
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
int a[N],b[N],g[N][N],l[M],ll;
int lft,rht,mid,su,ma;
int n,m;
struct ee
{
	int u,v,w;
}e[M];
int main()
{
    int i,j,S,T;
    while(scanf("%d",&n) && n)
    {
		S=0;
		T=n+1;
		ma=su=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			su+=a[i];
		}
		for(i=1;i<=n;i++)
			scanf("%d",&b[i]);
		memset(g,-1,sizeof(g));
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
			l[i]=e[i].w;
		}
		sort(l,l+m);
		ll=0;
		for(i=1;i<m;i++)
			if(l[i]!=l[i-1])l[++ll]=l[i];
		lft=0; rht=ll;
		int ans=-1;
		while(lft<=rht)
		{
			ind=0;
    		memset(p,-1,sizeof(p));
			mid=(lft+rht)>>1;
			for(i=1;i<=n;i++)
			{
				if(a[i]>0)insert(S,i,a[i]);
				if(b[i]>0)insert(i,T,b[i]);
			}
			for(i=0;i<m;i++)
			if(e[i].w<=l[mid])
			{
				insert(e[i].u,e[i].v,INF);
				insert(e[i].v,e[i].u,INF);
			}
			if(max_flow(n+2,0,n+1)>=su)rht=mid-1,ans=l[mid];
			else lft=mid+1;
		}
		if(ans==-1) printf("No Solution\n");
		else printf("%d\n",ans);
	}
	return 0;
}