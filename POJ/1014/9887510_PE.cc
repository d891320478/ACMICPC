#include <cstdio>

long c[7],ans,t=0,a[200];

int f()
{
	long flag=0;
	ans=0;
	
	for(int i=1;i<=6;i++)
	{
		scanf("%d",&c[i]);
		ans+=c[i]*i;
		if(c[i])flag=1;
	}
	return flag;
}

void ff(long n,int k)
{
	long s=1,an=n;
	
	while(an>=s)
	{
		an-=s;
		a[0]++;
		a[a[0]]=s*k;
		s*=2;
	}
	if(an)
	{
		a[0]++;
		a[a[0]]=an*k;
	}
}

int main ()
{
	while(f())
	{
		int z[60010]={1,0};
		
		t++;
		if(ans%2)
		{
			printf("Collection #%ld:\nCan't be divided.\n",t);
			continue;
		}
		ans/=2;
		a[0]=0;
		for(int i=1;i<=6;i++)
			ff(c[i],i);
		for(int i=1;i<=a[0];i++)
		for(long j=ans;j>=a[i];j--)
			z[j]=z[j] || z[j-a[i]];
		if(z[ans])printf("Collection #%ld:\nCan be divided.\n",t);
		else printf("Collection #%ld:\nCan't be divided.\n",t);
	}
	
	return 0;
}