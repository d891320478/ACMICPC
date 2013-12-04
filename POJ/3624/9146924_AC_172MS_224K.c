#include<stdio.h>

int n,m;
int f[15000]={0};
int c[30000],w[30000];

int main()
{
    int i,j;

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d%d",&c[i],&w[i]);
    for(i=1;i<=n;i++)
    for(j=m;j>=c[i];j--)
            if(f[j]<f[j-c[i]]+w[i]) f[j]=f[j-c[i]]+w[i];
    printf("%d\n",f[m]);
    
    return 0;
}
