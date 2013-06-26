#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define EPS 1e-8
#define N 1010
int n,m,y;
int x[N],z[N],id[N];
bool cmp(int i,int j)
{
	return (1.0*(z[j]+1)/m-1.0*x[j]/y)-(1.0*(z[i]+1)/m-1.0*x[i]/y)>EPS;
}
int main()
{
		scanf("%d%d%d",&n,&m,&y);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&x[i]);
			id[i]=i;
		}
		int sum=0;
		for(int i=1;i<=n;++i)
		{
			z[i]=(int)(1.0*m*x[i]/y+EPS);
			sum+=z[i];
		}
		sum=m-sum;
		sort(id+1,id+1+n,cmp);
		for(int i=1;i<=sum;i++) ++z[id[i]];
		for(int i=1;i<=n;i++)
		{
			printf("%d",z[i]);
			if(i<n) printf(" ");
			else printf("\n");
		}
	return 0;
}
