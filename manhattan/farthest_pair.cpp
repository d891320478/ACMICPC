#include <stdio.h>
#define N 100010
double ans,x[N][6],mn,mx,sum;
int n;
int main ()
{
	while (scanf("%d",&n)!=-1)
	{
		for(int i=1;i<=n;i++)
		for(int j=0;j<5;j++)
			scanf("%lf",&x[i][j]);
		ans=-1e15;
		for(int i=0;i<(1<<4);i++)
		{
			mx=-1e15; mn=1e15;
			for(int j=1;j<=n;j++)
			{
				sum=x[j][0];
				for(int k=0;k<4;k++)
					if(i & (1<<k)) sum+=x[j][k+1];
					else sum-=x[j][k+1];
				mx=mx>sum?mx:sum;
				mn=mn<sum?mn:sum;
			}
			ans=ans>mx-mn?ans:mx-mn;
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
