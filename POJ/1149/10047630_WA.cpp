#include <cstdio>
#include <cstring>
using namespace std;
const long long V=220,E=100000;

long long n,m,h[V],vh[V],start,end;
long long g[V][V],a[E],u[E];

struct etype
{
    long long t,u;
    etype *next,*pair;
    etype(){}
    etype(long long t_,long long u_,etype* next_):t(t_),u(u_),next(next_){}
    void* operator new(unsigned,void* p){return p;}
} *e[V],*eb[V],Te[E+E],*Pe=Te;

long long aug(long long no,long long m)
{
    if(no==end)return m;
    long long l=m;
    for(etype *&i=e[no];i;i=i->next)if(i->u && h[i->t]+1==h[no])
    {
        long long d=aug(i->t,l<i->u?l:i->u);
        i->u-=d,i->pair->u+=d,l-=d;
        if(h[start]==n || !l)return m-l;
    }
    long long minh=n;
    for(etype *i=e[no]=eb[no];i;i=i->next)if(i->u)
        if(h[i->t]+1<minh)minh=h[i->t]+1;
    if(!--vh[h[no]])h[start]=n;else ++vh[h[no]=minh];
    return m-l;
}
   
int main()
{
	long long i,j,k,c;
    scanf("%lld%lld",&m,&n);
    for(i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	start=n+1; end=n+2;
	memset(e,0,sizeof(e));
	for (i=1;i<=n;i++)
	{
		long long u,s=i,t=end;
		scanf("%lld",&g[i][0]);
		for(j=1;j<=g[i][0];j++)
			scanf("%lld",&g[i][j]);
		scanf("%lld",&u);
        e[s]=new(Pe++)etype(t,u,e[s]);
        e[t]=new(Pe++)etype(s,0,e[t]);
        e[s]->pair=e[t];
        e[t]->pair=e[s];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=g[i][0];j++)
		{
			if(! u[g[i][j]])
			{
				long long s=start,t=i,v=a[g[i][j]];
				u[g[i][j]]=i;
				e[s]=new(Pe++)etype(t,v,e[s]);
				e[t]=new(Pe++)etype(s,0,e[t]);
				e[s]->pair=e[t];
				e[t]->pair=e[s];
			}
			else
			{
				long long s=u[g[i][j]],t=i,v=1000000;
				e[s]=new(Pe++)etype(t,v,e[s]);
				e[t]=new(Pe++)etype(s,0,e[t]);
				e[s]->pair=e[t];
				e[t]->pair=e[s];
				u[g[i][j]]=i;
			}
		}
	}
	n+=2;
    memmove(eb,e,sizeof(e));
    memset(h,0,sizeof(h));
    memset(vh,0,sizeof(vh));
    vh[0]=n;
    long long ans=0;
    while(h[start]<n)ans+=aug(start,~0U>>1);
    printf("%lld\n",ans);
    return 0;
}