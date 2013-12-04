#include <cstdio>
#include <cstring>
char s[12][12];
int n,m,a,b,f[12][12],i,j,ans;
bool flag;
bool dfs(int x,int y)
{
	ans++;
	if(x<0)
	{
		a=0,b=y;return 1;
	}
	if(y<0)
	{
		a=x,b=0;return 1;
	}
	if(x>=n)
	{
		a=n-1,b=y;return 1;
	}
	if(y>=m)
	{
		a=x,b=m-1;return 1;
	}
	if(f[x][y])
	{
		a=x,b=y;return 0;
	}
	f[x][y]=ans;
	if(s[x][y]=='N')dfs(x-1,y);
	else if(s[x][y]=='S')dfs(x+1,y);
	else if(s[x][y]=='W')dfs(x,y-1);
	else if(s[x][y]=='E')dfs(x,y+1);
}
int main()
{
	while (scanf("%d%d%d",&n,&m,&a))
	{
		if(n==0 &&m==0 && a==0)break;
		a--;
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		memset(f,0,sizeof(f));
		ans=0;
		flag=dfs(0,a);
		if(flag)printf("%d step(s) to exit\n",f[a][b]);
		else printf("%d step(s) before a loop of %d step(s)\n",f[a][b]-1,ans-f[a][b]);
	}	
	return 0;
}