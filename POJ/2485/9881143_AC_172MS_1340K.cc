#include <cstdio>

int t;

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		int n;
		long ma=0,a[501][501],u[501]={0},d[501];
		
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%ld",&a[i][j]);
		for(int i=0;i<n;i++)
			d[i]=a[0][i];
		u[0]=1;
		for(int i=1;i<n;i++)
		{
			int k,mi=100000;
		    for(int j=0;j<n;j++)
		    	if(d[j]<mi && ! u[j])
		    	{
		    	    k=j;
		    	    mi=d[j];
		    	}
		    u[k]=1;
		    ma=ma>d[k]?ma:d[k];
		    for(int j=0;j<n;j++)
		    	if(a[k][j]<d[j] && !u[j]) d[j]=a[k][j];
		}
		printf("%ld\n",ma);
	}
	
	return 0;
}