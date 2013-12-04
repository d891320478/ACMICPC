#include<stdio.h>
#include<string.h>

int m,n;
int a[102][102],g[102][102];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int max=0;

void dfs(int s,int t)
{
    int i;
    int maxx=0;
    if(g[s][t]!=0)return;
    for(i=0;i<4;i++)
        if(s+dx[i]>0 && s+dx[i]<=m && t+dy[i]>0 && t+dy[i]<=n)
            if(a[s+dx[i]][t+dy[i]]<a[s][t])
            {
                dfs(s+dx[i],t+dy[i]);
                if(maxx<g[s+dx[i]][t+dy[i]])
                    maxx=g[s+dx[i]][t+dy[i]];
            }
    g[s][t]=maxx+1;
    max=max>g[s][t]?max:g[s][t]; 
}

int main()
{
    int i,j;
    
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
        dfs(i,j);
    printf("%d\n",max);
    
    return 0;
}
