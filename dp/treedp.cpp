//树上删去一条边后两棵新树的直径和乘积最小
int dp[N][3],L[N][3];  
int head[N],cnt,ans,id;  
struct edge  
{  
    int v,w,next;  
}e[N<<1];  
int n;  
void add(int u,int v,int w)  
{  
    e[cnt].v=v;  
    e[cnt].w=w;  
    e[cnt].next=head[u];  
    head[u]=cnt++;  
}  
void dfs1(int u,int f)  
{  
    int v;  
    dp[u][0]=dp[u][1]=dp[u][2]=0;  
    L[u][0]=L[u][1]=L[u][2]=0;  
    for(int i=head[u];i!=-1;i=e[i].next)  
    if((v=e[i].v)!=f)  
    {  
        dfs1(v,u);  
        if(L[v][0]+1>L[u][0]) L[u][2]=L[u][1],L[u][1]=L[u][0],L[u][0]=L[v][0]+1;  
        else if(L[v][0]+1>L[u][1]) L[u][2]=L[u][1],L[u][1]=L[v][0]+1;  
        else if(L[v][0]+1>L[u][2]) L[u][2]=L[v][0]+1;  
        dp[u][0]=max(max(dp[u][0],L[u][0]+L[u][1]),dp[v][0]);  
        if(dp[v][0]>dp[u][1]) dp[u][2]=dp[u][1],dp[u][1]=dp[v][0];  
        else if(dp[v][0]>dp[u][2]) dp[u][2]=dp[v][0];  
    }  
}  
void dfs(int u,int f,int l,int d,int ed)  
{  
    int v,ans0,l0,d0;  
    if(ed!=-1)  
    {  
        ans0=max(d,dp[u][0]);  
        if(ans0*e[ed].w<ans || ans0*e[ed].w==ans && id>(ed>>1)+1)  
        {  
            ans=ans0*e[ed].w;  
            id=(ed>>1)+1;  
        }  
    }  
    for(int i=head[u];i!=-1;i=e[i].next)  
    if((v=e[i].v)!=f)  
    {  
        l0=l+1;  
        if(L[u][0]==L[v][0]+1) l0=max(L[u][1]+1,l0);  
        else l0=max(L[u][0]+1,l0);  
        d0=d;  
        if(L[u][0]==L[v][0]+1) d0=max(d0,L[u][1]+l);  
        else d0=max(d0,L[u][0]+l);  
        if(L[u][0]==L[v][0]+1) d0=max(d0,L[u][1]+L[u][2]);  
        else if(L[u][1]==L[v][0]+1) d0=max(d0,L[u][0]+L[u][2]);  
        else d0=max(d0,L[u][0]+L[u][1]);  
        dfs(v,u,l0,d0,i);  
    }  
}  
int main ()  
{
    int tt,_=0;  
    scanf("%d",&tt);  
    while (tt--)  
    {  
        scanf("%d",&n);  
        cnt=0;  
        memset(head,-1,sizeof(head));  
        for(int i=1;i<n;++i)  
        {  
            int u,v,w;  
            scanf("%d%d%d",&u,&v,&w);  
            add(u,v,w);  
            add(v,u,w);  
        }  
        dfs1(1,0);  
        ans=id=2147483647;  
        dfs(1,0,0,0,-1);  
        printf("Case #%d: %d\n",++_,id);  
    }  
    return 0;  
}  
