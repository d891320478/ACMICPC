#include<stdio.h>
#include<string.h>

long int g[1000002];
long int a,b;
long int n,i,max;

long int dfs(long long int s)
{
    long int sn;

    if(s<=1000000)if(g[s]!=0)return g[s];
    if(s%2==0)
    {
        sn=dfs(s/2)+1;
        if(s<=1000000)g[s]=sn;
        return sn;
    }
    else
    {
        sn=dfs(3*s+1)+1;
        if(s<=1000000)g[s]=sn;
        return sn;
    }
}

int main()
{
    g[1]=1;
    for(i=2;i<=1000000;i++)
        if(! g[i]) dfs(i);
    while(scanf("%ld%ld",&a,&b)!=EOF)
    {
        if(a>b)
        {
            a^=b;
            b^=a;
            a^=b;
        }
        max=0;
        for(i=a;i<=b;i++)
            max=max>g[i]?max:g[i];
        printf("%ld %ld %ld\n",a,b,max);
    }

    return 0;
}
