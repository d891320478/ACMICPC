#include <cstring>
#include <cstdio>
#include <algorithm>
#include<iostream>
using namespace std;
#define N 300
#define M 90000
#define INF 0x7fffffff
struct node
{
    int v,next,val;
}s[M*2];
int lft,rht,mid;
struct fff
{
	int ue,ve,we;
}e[M];
int cmp(const fff &a,const fff &b)
{
	return a.we<b.we;
}
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
int m,n,L;
int main()
{
    while(scanf("%d%d%d",&n,&m,&L)!=EOF)
    {
    	lft=1600000000; rht=0;
    	for(int i=0;i<m;i++)
		{
		    scanf("%d%d%d",&e[i].ue,&e[i].ve,&e[i].we);
		    rht=rht>e[i].we?rht:e[i].we;
		    lft=lft<e[i].we?lft:e[i].we;
		}
		sort(e,e+m,cmp);
		while (lft<rht)
		{
			mid=(lft+rht)/2;
			ind=0;
			memset(p,-1,sizeof(p));
			for(int i=0;i<m;i++)
			{
				if(e[i].we>mid)break;
				insert(e[i].ue-1,e[i].ve-1,1);
				insert(e[i].ve-1,e[i].ue-1,1);
			}
			int ans=max_flow(n,0,n-1);
			if(ans>=L)rht=mid;
    		else lft=mid+1;
		}
		printf("%d\n",lft);
    }
    return 0;
}