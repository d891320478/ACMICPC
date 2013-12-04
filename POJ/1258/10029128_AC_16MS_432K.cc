#include <cstdio>
#include <cstring>

long g[101][101],value;
int n;

void prim()
{
	long int min,i,j,k,u[101]={0},d[101];

	for(i=1;i<=n;i++)
        d[i]=g[1][i];
    u[1]=1;
    for(i=1;i<n;i++)
    {
        min=1000000;
        for(j=1;j<=n;j++)
            if(! u[j])
            if(d[j]<min)
            {
                min=d[j];
                k=j;
            }
        u[k]=1;
        value+=d[k];
        for(j=1;j<=n;j++)
            if(! u[j]) if(d[j]>g[k][j])
                d[j]=g[k][j];
	}
}


int main ()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%ld",&g[i][j]);
		value=0;
		prim();
		printf("%ld\n",value);
	}
	
	return 0;
}