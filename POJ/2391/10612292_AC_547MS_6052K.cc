#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 800
#define M 200000
#define INF 0x7fffffff
struct node
{
    long long v,next,val;
}s[M*2];
long long level[N],p[N],que[N],out[N],ind;
inline void insert(long long x,long long y,long long z)
{
    s[ind].v=y;    s[ind].val=z;    s[ind].next=p[x];
    p[x]=ind++;
    s[ind].v=x;    s[ind].val=0;    s[ind].next=p[y];
    p[y]=ind++;
}
long long max_flow(long long n,long long source,long long sink)
{
    long long ret=0,h=0,r=0;
    while(1)
    {
        long long i;
        for(i=0;i<n;++i)
            level[i]=0;
        h=0,r=0;
        level[source]=1;
        que[0]=source;
        while(h<=r)
        {
            long long t=que[h++];
            for(i=p[t];i!=-1;i=s[i].next)
                if(s[i].val&&level[s[i].v]==0)
                {
                    level[s[i].v]=level[t]+1;
                    que[++r]=s[i].v;
                }
        }
        if(level[sink]==0)break;
        for(i=0;i<n;++i)out[i]=p[i];
        long long q=-1;
        while(1)
        {
            if(q<0)
            {
                long long cur=out[source];
                for(;cur!=-1;cur=s[cur].next)
                    if(s[cur].val&&out[s[cur].v]!=-1&&level[s[cur].v]==2)
                        break;
                if(cur>=0) que[++q]=cur,out[source]=s[cur].next;
                else break;
            }
            long long u=s[que[q]].v;
            if(u==sink)
            {
                long long dd=INF,index=-1;
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
                long long cur=out[u];
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
long long m,n;
long long sum,ma;
long long a[N][N],c[N],w[N],lft,rht;
int main()
{
	long long i,j,k;
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
    	memset(a,-1,sizeof(a));
    	sum=0;
    	for(i=1;i<=n;i++)
    	{
    		scanf("%lld%lld",&c[i],&w[i]);
    		sum+=c[i];
    		a[i][i]=0;
    	}
        while (m--)
        {
        	long long u,v,w;
        	scanf("%lld%lld%lld",&u,&v,&w);
        	if(a[u][v]<0 || a[u][v]>w)
        		a[u][v]=a[v][u]=w;
        }
        lft=rht=0;
        for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        	if(a[i][k]>=0 && a[k][j]>=0)
        	if(a[i][j]==-1 || a[i][j]>a[i][k]+a[k][j])
        		a[i][j]=a[i][k]+a[k][j];
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        	if(rht<a[i][j])rht=a[i][j];
        ma=++rht;
        lft=0;
        while (lft<rht)
        {
        	long long mid=(rht+lft)>>1;
        	ind=0;
	    	memset(p,-1,sizeof(p));
	    	for(i=1;i<=n;i++)
	    	{
	    		insert(i,i+n,INF);
	    		if(c[i]>0)insert(0,i,c[i]);
	    		if(w[i]>0)insert(i+n,n+n+1,w[i]);
	    	}
	    	for(i=1;i<=n;i++)
	    	for(j=1;j<=n;j++)
	    		if(a[i][j]>0 && a[i][j]<=mid)
	    			if(c[i]>0 && w[j]>0)insert(i,j+n,INF);
	    	long long ans0=max_flow(n+n+2,0,n+n+1);
	    	if(ans0>=sum)rht=mid;
	    	else lft=mid+1;
        }
        if(lft>=ma)printf("-1\n");
        else printf("%lld\n",lft);
    }
    return 0;
} 