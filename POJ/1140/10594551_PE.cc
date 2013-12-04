#include <cstdio>
#include <cstring>
int n,m,tmp;
int f[1001],a[1010];
int main ()
{
	while (scanf("%d%d",&n,&m))
	{
		if(n==0 && m==0)break;
		memset(f,-1,sizeof(f));
		tmp=n;
		a[0]=0;
		while(f[tmp]==-1 && tmp!=0)
		{
			f[tmp]=a[0];
			tmp*=10;
			a[++a[0]]=tmp/m;
			tmp%=m;
		}
		printf(".");
		for(int i=1;i<=a[0];i++)
		{
			printf("%d",a[i]);
			if(i==49 || (i>50 && i%50==0))printf("\n");
		}
		if(! ((a[0]+1)==49 || ((a[0]+1)>50 && (a[0]+1)%50==0)))printf("\n");
		if(tmp==0)printf("This expansion terminates.\n");
		else printf("The last %d digits repeat forever.\n",a[0]-f[tmp]);
	}
	
	return 0;
}