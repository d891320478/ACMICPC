#include<stdio.h>

long int a[15];
int k,i,j;

int f(long int n,long int k)
{
    long int i=n*2,s=0;

    while(i>n)
    {
        s=(s+k-1)%i;
        i--;
        if(s<n)return 1;
    }

    return 0;
}

int main()
{
for(i=1;i<14;i++)
    {
        j=i+1;
        while(1)
        {
            if(! f(i,j))
            {
                a[i]=j;
                break;
            }
            if(! f(i,j+1))
            {
                a[i]=j+1;
                break;
            }
            j+=i+1;
        }
    }
    scanf("%d",&k);
    while(k)
    {
        printf("%ld\n",a[k]);
        scanf("%ld",&k);
    }

    return 0;
}
