#include<stdio.h>

int n,d;

int main()
{
    while(scanf("%d%d",&n,&d)&&n)
    {
        int a[100]={1,1};

        for(int t=1;t<=d;t++)
        {
            for(int i=1;i<=a[0];i++)
            {
                a[i]*=n;
                if(i>1)
                {
                    a[i]+=a[i-1]/10;
                    a[i-1]%=10;
                }
            }
            while(a[a[0]]>=10)
            {
                a[0]++;
                a[a[0]]=a[a[0]-1]/10;
                a[a[0]-1]%=10;
            }
        }
        for(int i=a[0];i>=1;i--)
            printf("%d",a[i]);
        printf("\n");
    }

    return 0;
}
