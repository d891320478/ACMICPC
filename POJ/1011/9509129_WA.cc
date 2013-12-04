#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int n,i,sum;
int a[100];
int fff;

int search(int s)
{
    int flag[100],i,j,k;
    
    memset(flag,0,sizeof(flag));
    for(i=n-1;i>=0;i--)
    if(! flag[i])
    {
        flag[i]=1;
        k=a[i];
        for(j=i-1;j>=0;j--)
            if(! flag[j])
            if(k+a[j]<=s)
            {
                k+=a[j];
                flag[j]=1;
            }
        if(k!=s)return 0;
    }
    return 1;
}

int main()
{
    scanf("%d",&n);
    while(n)
    {
        memset(a,0,sizeof(a));
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sort(a,a+n);
        fff=0;
        for(i=a[n-1];i<=sum/2;i++)
        if(sum%i==0)
            if(search(i))
            {
                printf("%d\n",i);
                fff=1;
                break;
            }
        if(! fff)printf("%d\n",sum);
        scanf("%d",&n);
    }
     
    return 0;
}
