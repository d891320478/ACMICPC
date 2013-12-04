#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

long int n;
long int a[100],sum,num,llen;
long int u[100],flag;
long int i;

int search(long int l,long int len,long int ans)
{
    long int i;

    if(ans==num-1)return 1;
    if(l==0)
    {
        for(i=n;u[i];i--);
        u[i]=1;
        if(search(llen-a[i],i-1,ans+1))return 1;
        u[i]=0;
        return 0;
    }
    else
    {
        for(i=len;i>0;i--)
        {
            if(u[i])continue;
            if(l<a[i])continue;
            if(a[i]==a[i+1] && u[i+1]==0)continue;
            u[i]=1;
            if(search(l-a[i],i-1,ans))return 1;
            u[i]=0;
        }
        return 0;
    }
}

int main()
{
	 scanf("%ld",&n);
    while(n)
    {
        sum=flag=0;
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
        {
            scanf("%ld",&a[i]);
            sum+=a[i];
        }
		sort(a+1,a+n+1);
        memset(u,0,sizeof(u));
        for(llen=a[n];llen<=sum/2;llen++)
        if(! (sum%llen))
        {
            num=sum/llen;
            u[n]=1;
            if(search(llen-a[n],n-1,0))
            {
                flag=1;
                break;
            }
            u[n]=0;
        }
        if(flag)printf("%ld\n",llen);
        else printf("%ld\n",sum);
        scanf("%ld",&n);
    }

    return 0;
}
