#include <cstdio>
#include <cstring>

long c[7],a[7][7],ans;

int f0()
{
	long flag=0;
	ans=0;
	
	for(int i=1;i<=6;i++)
	{
		scanf("%d",&c[i]);
		if(c[i])flag=1;
	}
	return flag;
}

int f1()
{
	int flag=0;
	for (unsigned int i = 1; i < 7; i += 1)
		if(c[i])flag=1;
	return flag;
}

int f2(int b)
{
	int flag,i,j,s,t;
	for(s=1;s+b-1<=6;s++)
	for(t=1;t+b-1<=6;t++)
	if(! a[s][t])
	{
		flag=1;
		for(i=s;i<=s+b-1;i++)
		for(j=t;j<=t+b-1;j++)
			if(a[i][j])flag=0;
		if(flag)
		{
			for(i=s;i<=s+b-1;i++)
			for(j=t;j<=t+b-1;j++)
				a[i][j]=1;
			c[b]--;
			return 1;
		}
	}
	return 0;
}

int main ()
{
	while(f0())
	{
		ans=0;
		while(f1())
		{
			int j=6;
			memset(a,0,sizeof(a));
			while(j>0)
			{
				while(c[j]==0 && j>0)j--;
				if(j==0)break;
				if(c[j]==0 || !f2(j))j--;
			}
			ans++;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}