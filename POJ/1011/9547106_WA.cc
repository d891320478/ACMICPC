
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int n;
int a[65],sum,num;
int u[65],flag;
int i;

int search(int l,int len,int ans)
{
    int i;

    if(ans==num-1)return 1;
    if(l==0)
    {
        for(i=n;u[i];i--);
        u[i]=1;
        if(search(sum/num-a[i],i-1,ans+1))return 1;
        u[i]=0;
        return 0;
    }
    else
    {
        for(i=len-1;i>0;i--)
        {
            if(u[i])continue;
            if(l<a[i])continue;
            if(a[i]==a[i+1] && (! u[i+1]))continue;
            u[i]=1;
            if(search(l-a[i],i,ans))return 1;
            u[i]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    while(n)
    {
        sum=flag=0;
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
		sort(a+1,a+n+1);
        memset(u,0,sizeof(u));
        for(i=a[n];i<=sum/2;i++)
        if(! (sum%i))
        {
            num=sum/i;
            u[n]=1;
            if(search(i-a[n],n,0))
            {
                flag=1;
                break;
            }
        }
        if(flag)printf("%d\n",i);
        else printf("%d\n",sum);
        scanf("%d",&n);
    }

    return 0;
}
