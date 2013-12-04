#include<cstdio>
long v[10001];
long i,j,k,m,n;
void ff(long int n,long int c)
{
    long int l=0,ans=n,s=1;

    while(ans>=s)
    {
        v[++v[0]]=s*c;
        l+=v[v[0]];
        ans-=s;
        s*=2;
    }
    if(ans) v[++v[0]]=ans*c;
}
int main()
{
    while(scanf("%ld%ld",&m,&n)!=EOF)
    {
        long a[100001]={0};
        v[0]=0;
        for(i=1;i<=n;i++)
        {
        	long x,y;
            scanf("%ld%ld",&x,&y);
            ff(x,y);
        }
        for(i=1;i<=v[0];i++)
        for(j=m;j>=v[i];j--)
            if(a[j]<a[j-v[i]]+v[i])a[j]=a[j-v[i]]+v[i];
        printf("%ld\n",a[m]);
    }

    return 0;
}