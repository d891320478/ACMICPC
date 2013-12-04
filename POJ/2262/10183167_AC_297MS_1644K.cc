#include <cstdio>

int n,a[100000],i,j;
bool f[1000001]={1,1,0,0},flag;
char s[]="Goldbach's conjecture is wrong.";
int main()
{
	a[0]=1; a[1]=2;
	for(i=2;i*2<=1000000;i++) f[i*2]=1;
	for(i=3;i<=1000000;i+=2)
	if(! f[i])
	{
		a[++a[0]]=i;
		for(j=3;i*j<=1000000;j+=2)
			f[i*j]=1;
	}
	while (scanf("%d",&n) && n)
	{
		flag=0;
		i=1;
		while(i<=a[0] && a[i]<=n/2)
		{
			if(! f[n-a[i]])
			{
				flag=1;
				break;
			}
			else i++;
		}
		if(flag)printf("%d = %d + %d\n",n,a[i],n-a[i]);
		else puts(s);
	}
	
	return 0;
}