#include<stdio.h>
#include<string.h>

char s[10][10];
int n,k;
int u[10];
long int sum;

void dfs(int x,int y)
{
    int i,j;
    
    if(x>k)
    {
        sum++;
        return;
    }
    for(i=y;i<n-(k-x);i++)
    for(j=0;j<n;j++)
        if(s[i][j]=='#' && (! u[j]))
        {
            u[j]=1;
            dfs(x+1,i+1);
            u[j]=0;
        }
}

int main()
{
    int i;

    scanf("%d%d",&n,&k);
    while(n!=-1)
    {
        for(i=0;i<n;i++)
            scanf("%s",s[i]);
        sum=0;
        memset(u,0,sizeof(u));
        dfs(1,0);
        printf("%ld\n",sum);
        scanf("%d%d",&n,&k);
    }

    return 0;
}
