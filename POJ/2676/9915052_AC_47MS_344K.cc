#include <cstdio>
#include <cstring>

int t,a[10][10],flag;
char ch;

int f(int s,int t,int o)
{
	for(int i=0;i<9;i++)
	{
		if(i!=t)if(a[s][i]==o)return 0;
		if(i!=s)if(a[i][t]==o)return 0;
	}
	int m=s/3*3,n=t/3*3;
	for(int i=m;i<m+3;i++)
	for(int j=n;j<n+3;j++)
		if(i!=s && j!=t)if(a[i][j]==o) return 0;
	return 1;
}

void dfs(int s,int t)
{
	if(flag)return;
	if(s<0 || t<0){flag=1; return;}
	if(a[s][t]==0)
	{
		for(int i=1;i<=9;i++)
		if(f(s,t,i))
		{
			a[s][t]=i;
			if(s!=0) dfs(s-1,t);
			else dfs(8,t-1);
		}
		if(flag)return;
		a[s][t]=0;
	}
	else 
	if(s>0) dfs(s-1,t);
	else dfs(8,t-1);
}

int main ()
{
	scanf("%d%c",&t,&ch);
	while (t--)
	{
		char s[11];
		
		for(int i=0;i<9;i++)
		{
			scanf("%s",s);
			for(int j=0;s[j];j++) a[i][j]=s[j]-'0';
		}
		flag=0;
		dfs(8,8);
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
				printf("%d",a[i][j]);
			printf("\n");
		}
	}
	
	return 0;
}