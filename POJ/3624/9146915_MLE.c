#include<stdio.h>

int n,m;
int f[3403][12881]={0};
int c[3403],w[12881];

int main()
{
    int i,j;

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d%d",&c[i],&w[i]);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(j-c[i]>=0)
            f[i][j]=(f[i-1][j])>(f[i-1][j-c[i]]+w[i])?(f[i-1][j]):(f[i-1][j-c[i]]+w[i]);
        else f[i][j]=f[i-1][j];
    printf("%d\n",f[n][m]);
    
    return 0;
}
