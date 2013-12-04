#include <cstdio>
#include <cstring>
using namespace std;
const int V=220,E=10000;

int n,m,h[V],vh[V],start,end;
int g[V][V],a[E],u[E];

struct etype
{
    int t,u;
    etype *next,*pair;
    etype(){}
    etype(int t_,int u_,etype* next_):t(t_),u(u_),next(next_){}
    void* operator new(unsigned,void* p){return p;}
} *e[V],*eb[V],Te[E+E],*Pe=Te;

int aug(int no,int m)
{
    if(no==end)return m;
    int l=m;
    for(etype *&i=e[no];i;i=i->next)if(i->u && h[i->t]+1==h[no])
    {
        int d=aug(i->t,l<i->u?l:i->u);
        i->u-=d,i->pair->u+=d,l-=d;
        if(h[start]==n || !l)return m-l;
    }
    int minh=n;
    for(etype *i=e[no]=eb[no];i;i=i->next)if(i->u)
        if(h[i->t]+1<minh)minh=h[i->t]+1;
    if(!--vh[h[no]])h[start]=n;else ++vh[h[no]=minh];
    return m-l;
}
   
int main()
{
	int i,j,k,c;
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	start=n+1; end=n+2;
	memset(e,0,sizeof(e));
	for (i=1;i<=n;i++)
	{
		int u,s=i,t=end;
		scanf("%d",&g[i][0]);
		for(j=1;j<=g[i][0];j++)
			scanf("%d",&g[i][j]);
		scanf("%d",&u);
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
				int s=start,t=i,v=a[g[i][j]];
				u[g[i][j]]=i;
				e[s]=new(Pe++)etype(t,v,e[s]);
				e[t]=new(Pe++)etype(s,0,e[t]);
				e[s]->pair=e[t];
				e[t]->pair=e[s];
			}
			else
			{
				int s=u[g[i][j]],t=i,v=1000000;
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
    int ans=0;
    while(h[start]<n)ans+=aug(start,~0U>>1);
    printf("%d\n",ans);
    return 0;
}