#include <cstdio>
#include <cstring>
#include <cmath>

int n;
bool u[101];
double d[101],a[101][101],x[101],y[101],z[101],r[101],value;

int main ()
{
	while (scanf("%d",&n) && n)
	{
		memset(a,0,sizeof(a));
		memset(u,0,sizeof(u));
		for(int i=1;i<=n;i++)
			scanf("%lf%lf%lf%lf",&x[i],&y[i],&z[i],&r[i]);
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			double l=sqrt(pow(x[i]-x[j],2.0)+pow(y[i]-y[j],2.0)+pow(z[i]-z[j],2.0))-r[i]-r[j];
			if(l>a[i][j])a[i][j]=a[j][i]=l;
		}
		for(int i=1;i<=n;i++)
			d[i]=a[1][i];
		u[1]=1; value=0;
		for(int i=1;i<n;i++)
		{
			int k; double minn=1e9;
			for(int j=1;j<=n;j++)
				if(! u[j])
				if(d[j]<minn)
				{
					minn=d[j];
					k=j;
				}
			u[k]=1; value+=d[k];
			for(int j=1;j<=n;j++)
				if(! u[j])
				if(d[j]>a[k][j]) d[j]=a[k][j];
		}
		printf("%.3f\n",value);
	}
	
	return 0;
}
