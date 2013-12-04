#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
#define N 1010
#define M 1000000
struct fff
{
    int x,y;
}p,s1,s2;
int n,m1,m2,dss;
int ua[N],va[N],ub[N],vb[N];
int head[N],next[M],e[M],cnt;
int dfn[N],low[N],tot,step,point,stack[N];
int into[N],color[N];
int fd[N],fe[N];
void addedge(int u,int v)
{
    next[cnt]=head[u];
    e[cnt]=v;
    head[u]=cnt++;
}
void tarjan(int s)
{
    int i,j;
    dfn[s]=low[s]=++step;
    stack[++tot]=s;
    for(i=head[s];i!=-1;i=next[i])
    {
        if(! dfn[e[i]])
        {
            tarjan(e[i]);
            low[s]=min(low[s],low[e[i]]);
        }
        else if(! color[e[i]]) low[s]=min(low[s],dfn[e[i]]);
    }
    if(dfn[s]==low[s])
    {
        point++;
        do{
            j=stack[tot--];
            color[j]=point;
        } while (j!=s);
    }
}
bool twosat(int n)
{
    for(int i=0;i+1<n;i+=2) if(color[i]==color[i+1]) return 0;
    return 1;
}
int sbs(int a)
{
	return a<0?-a:a;
}
int fds(struct fff a,struct fff b)
{
    return sbs(a.y-b.y)+sbs(a.x-b.x);
}
int main ()
{
    int i,j;
    while(~scanf("%d%d%d",&n,&m1,&m2))
    {
    	scanf("%d %d",&s1.x,&s1.y);
    	scanf("%d %d",&s2.x,&s2.y);
        dss=fds(s1,s2);
        for(i=0;i<n;i++) {scanf("%d %d",&p.x,&p.y); fd[i]=fds(p,s1); fe[i]=fds(p,s2); }
        for(i=0;i<m1;i++) {scanf("%d %d",&ua[i],&va[i]); ua[i]--; va[i]--;}
        for(i=0;i<m2;i++) {scanf("%d %d",&ub[i],&vb[i]); ub[i]--; vb[i]--;}
        int l=0,r=4000000,mid;
        while (l<r)
        {
            for(i=0;i<n*2;i++)
            {
            	head[i]=-1;
            	dfn[i]=color[i]=0;
            }
            cnt=0;
            mid=(l+r)>>1;
            for(i=0;i<m1;++i)  
            {  
                addedge(ua[i]*2,va[i]*2+1);  
                addedge(ua[i]*2+1,va[i]*2);  
                addedge(va[i]*2,ua[i]*2+1);  
                addedge(va[i]*2+1,ua[i]*2);  
            }  
            for(i=0;i<m2;++i)  
            {  
                addedge(ub[i]*2,vb[i]*2);  
                addedge(ub[i]*2+1,vb[i]*2+1);  
                addedge(vb[i]*2,ub[i]*2);  
                addedge(vb[i]*2+1,ub[i]*2+1);  
            }
            for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
            	if(fd[i]+fd[j]>mid)
            	{
            		addedge(i*2,j*2+1);
            		addedge(j*2,i*2+1);
            	}
            	if(fd[i]+dss+fe[j]>mid)
            	{
            		addedge(i*2,j*2);
            		addedge(j*2+1,i*2+1);
            	}
				if(fe[i]+dss+fd[j]>mid)
            	{
            		addedge(i*2+1,j*2+1);
            		addedge(j*2,i*2);
            	}
            	if(fe[i]+fe[j]>mid)
            	{
            		addedge(i*2+1,j*2);
            		addedge(j*2+1,i*2);
            	}
            }
            point=tot=step=0;
            for(i=0;i<2*n;i++)
                if(! dfn[i]) tarjan(i);
            if(twosat(2*n)) r=mid;
            else l=mid+1;
            
        }
        if(l<4000000) printf("%d\n",l);
        else printf("-1\n");
    }
    
    return 0;
}