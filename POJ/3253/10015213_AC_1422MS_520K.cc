#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    long long n,i,j,sum=0,a[20001];

    scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        sort(a,a+n);
        for(i=1;i<n;i++)
        {
            a[i]+=a[i-1];
            sum+=a[i];
            j=i;
            for(;a[j]>a[j+1] && j<n-1;j++)
            {
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        printf("%lld\n",sum);

    return 0;
}