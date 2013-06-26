//HDU 2121最小树形图
#define N 1111
#define M 11111
int eu[M],ev[M];	long long ew[M],emax,in[N],ans;	
int pre[N],id[N],vis[N];	int n,m,ansi;
long long directed_mst(int rt,int n,int m)
{
    long long ret=0;    int i,u,v;
    while (1)
    {
        for(i=0;i<n;i++) in[i]=id[i]=vis[i]=-1;
        for(i=0;i<m;i++)
        {
            u=eu[i],v=ev[i];
            if(u!=v) if(ew[i]<in[v] || in[v]==-1)
            {   pre[v]=u;   in[v]=ew[i];  if(u==rt) ansi=i;      }
        }
        for(i=0;i<n;i++) if(in[i]==-1 && i!=rt) return -1;
        int cnt=0;        in[rt]=0;
        for(i=0;i<n;i++)
        {
            ret+=in[i];     v=i;
            while (vis[v]!=i && id[v]==-1 && v!=rt)
            {   vis[v]=i;    v=pre[v];     }
            if(v!=rt && id[v]==-1)
            {   for(u=pre[v];u!=v;u=pre[u]) id[u]=cnt;   id[v]=cnt++;     }
        }
        if(cnt==0) break;     for(i=0;i<n;i++)    if(id[i]==-1) id[i]=cnt++;
        for(i=0;i<m;i++)
        {   v=ev[i];    eu[i]=id[eu[i]];    ev[i]=id[ev[i]];
            if(eu[i]!=ev[i]) ew[i]-=in[v];
        }
        n=cnt;        rt=id[rt];
    }
    return ret;
}
int main ()
{
    while (scanf("%d%d",&n,&m)!=-1)
    {
        emax=10;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%I64d",&eu[i],&ev[i],&ew[i]);
            eu[i]++,ev[i]++;       emax+=ew[i];
        }
        for(int i=m;i<m+n;i++) {   eu[i]=0;   ev[i]=i-m+1;    ew[i]=emax;      }
        ans=directed_mst(0,n+1,m+n);
        if(ans-emax>=emax || ans==-1) puts("impossible\n");
        else printf("%I64d %d\n\n",ans-emax,ansi-m);
    }
    return 0;
}
