#include <cstdio>
int a[367][10],b[1000],i,j;
int main ()
{
	b[0]=b[1]=1;
	for(i=1;i<=366;i++)
	{
		for(j=1;j<=b[0];j++)
		{
			b[j]*=i;
			if(j>1)
			{
				b[j]+=b[j-1]/10;
				b[j-1]%=10;
			}
		}
		while(b[b[0]]>=10)
		{
			b[b[0]+1]=b[b[0]]/10;
			b[b[0]++]%=10;
		}
		for(j=1;j<=b[0];j++)
			a[i][b[j]]++;
	}
	int n;
	while (scanf("%d",&n) && n)
	{
		printf("%d! --\n",n);
		for(i=0;i<5;i++)
			printf("   (%d)%5d",i,a[n][i]);
		printf("\n");
		for(i=5;i<10;i++)
			printf("   (%d)%5d",i,a[n][i]);
		printf("\n");
	}
	
	return 0;
}