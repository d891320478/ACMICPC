#include<stdio.h>

int n,m;
long int f[13000];
int c[3100],w[3100];

int main()
{
    int i,j;

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d%d",&c[i],&w[i]);
    for(i=1;i<=n;i++)
    for(j=m;j>=c[i];j--)
            if(f[j]<f[j-c[i]]+w[i]) f[j]=f[j-c[i]]+w[i];
    printf("%ld\n",f[m]);
    
    return 0;
}
