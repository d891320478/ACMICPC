#include <cstdio>
#include <cstring>
#define maxn 101
long cx[maxn],cy[maxn],sx[maxn],sy[maxn],lx[maxn],ly[maxn];
long nx,ny,match,g[maxn][maxn];

bool path(long u)
{
    sx[u]=1;
    for(long v=1;v<=ny;v++)
        if (g[u][v]==lx[u]+ly[v] && !sy[v])
        {
            sy[v]=1;
            if(!cy[v] || path(cy[v]))
            {
                cx[u]=v; cy[v]=u; return 1;
            }
        }
    return 0;
}

void KM()
{
    long i,j,u,min,ans;
    memset(lx,0,sizeof(lx));    memset(ly,0,sizeof(ly));
    memset(cx,0,sizeof(cx));    memset(cy,0,sizeof(cy));
    for(i=1;i<=nx;i++)
    for(j=1;j<=ny;j++)
        if(lx[i]<g[i][j])lx[i]=g[i][j];
    for(match=0,u=1;u<=nx;u++)
        if(!cx[u])
        {
            memset(sx,0,sizeof(sx)); memset(sy,0,sizeof(sy));
            while (!path(u))
            {
                min=0x3fffffff;
                for(i=1;i<=nx;i++)
                if(sx[i])
                    for(j=1;j<=ny;j++)
                    if(!sy[j])
                        if(lx[i]+ly[j]-g[i][j]<min) min=lx[i]+ly[j]-g[i][j];
                for(i=1;i<=nx;i++) if(sx[i]){lx[i]-=min;sx[i]=0;}
                for(j=1;j<=ny;j++) if(sy[j]){ly[j]+=min;sy[j]=0;}
            }
        }
    ans=0;
    for(i=1;i<=nx;i++)
        ans+=g[i][cx[i]];
    printf("%ld\n",-ans);
}

void bfs(long a[101][101],long b[101][101],long xx,long yy,char s[102][102],long n,long m)
{
    long x[10002][3],head=0,tail=0,u[101][101]={0};
    x[0][0]=xx; x[0][1]=yy; x[0][2]=0;
    u[xx][yy]=1;
    while(head<=tail)
    {
        if(x[head][0]-1>=0)
        if(! u[x[head][0]-1][x[head][1]])
        {
            u[x[head][0]-1][x[head][1]]=1;
            tail++;
            x[tail][0]=x[head][0]-1;
            x[tail][1]=x[head][1];
            x[tail][2]=x[head][2]+1;
            if(s[x[tail][0]][x[tail][1]]=='H') g[a[xx][yy]][b[x[tail][0]][x[tail][1]]]=-x[tail][2];
        }
        if(x[head][0]+1<n)
        if(! u[x[head][0]+1][x[head][1]])
        {
            u[x[head][0]+1][x[head][1]]=1;
            tail++;
            x[tail][0]=x[head][0]+1;
            x[tail][1]=x[head][1];
            x[tail][2]=x[head][2]+1;
            if(s[x[tail][0]][x[tail][1]]=='H') g[a[xx][yy]][b[x[tail][0]][x[tail][1]]]=-x[tail][2];
        }
        if(x[head][1]-1>=0)
        if(! u[x[head][0]][x[head][1]-1])
        {
            u[x[head][0]][x[head][1]-1]=1;
            tail++;
            x[tail][0]=x[head][0];
            x[tail][1]=x[head][1]-1;
            x[tail][2]=x[head][2]+1;
            if(s[x[tail][0]][x[tail][1]]=='H') g[a[xx][yy]][b[x[tail][0]][x[tail][1]]]=-x[tail][2];
        }
        if(x[head][1]+1<m)
        if(! u[x[head][0]][x[head][1]+1])
        {
            u[x[head][0]][x[head][1]+1]=1;
            tail++;
            x[tail][0]=x[head][0];
            x[tail][1]=x[head][1]+1;
            x[tail][2]=x[head][2]+1;
            if(s[x[tail][0]][x[tail][1]]=='H') g[a[xx][yy]][b[x[tail][0]][x[tail][1]]]=-x[tail][2];
        }
        head++;
    }
}

int main()
{
    long n,m,i,j,a[maxn][maxn],b[maxn][maxn];
    char s[102][102],ch;
    while (scanf("%ld%ld%c",&n,&m,&ch))
    {
        if(n==0 && m==0)return 0;
        for(i=0;i<n;i++)
            scanf("%s",s[i]);
        nx=0;ny=0;
        memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(s[i][j]=='m'){ nx++; a[i][j]=nx; }
            if(s[i][j]=='H'){ ny++; b[i][j]=ny; }
        }
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(s[i][j]=='m') bfs(a,b,i,j,s,n,m);
        KM();
    }
    
    return 0;
}