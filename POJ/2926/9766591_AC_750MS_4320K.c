
#include<stdio.h>

long int n;
double maxx,minn;
long int i,j,k;
double a[100010][5],s,ans;
int b[33][5]={0,0,0,0,0};

int  main()
{
    for(i=1;i<=31;i++)
    {
        b[i][0]=b[i-1][0]+1;
        for(j=1;j<=4;j++)
        {
            b[i][j]=b[i-1][j]+b[i][j-1]/2;
            b[i][j-1]%=2;
        }
    }
    scanf("%ld",&n);
        ans=-1e15;
        for(i=1;i<=n;i++)
        for(j=0;j<5;j++)
            scanf("%lf",&a[i][j]);
        for(i=0;i<32;i++)
        {
            maxx=-1e15;
            minn=1e15;
            for(k=1;k<=n;k++)
            {
                if(b[i][0]==1)s=a[k][0];
                else s=-a[k][0];
                for(j=1;j<5;j++)
                {
                    if(b[i][j]==1)s+=a[k][j];
                    else s-=a[k][j];
                }
                if(s>maxx)maxx=s;
                if(s<minn)minn=s;
                ans=ans>maxx-minn?ans:maxx-minn;
            }
        }
        printf("%.2f\n",ans);

    return 0;
}
