/*
ID: dht31261
LANG: C
TASK:numtri
*/
#include<stdio.h>

int n,i,j;
int a[1001][1001];
long int f[1001][1001],max=0;

long int maxx(long int a,long int b)
{
    return (a>b?a:b);
}

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    for(j=1;j<=i;j++)
        scanf("%d",&a[i][j]);
    f[1][1]=a[1][1];
    for(i=2;i<=n;i++)
    for(j=1;j<=i;j++)
        f[i][j]=maxx(f[i-1][j-1],f[i-1][j])+a[i][j];
    for(i=1;i<=n;i++)
        max=max>f[n][i]?max:f[n][i];
    printf("%ld\n",max);
    
    return 0;
}