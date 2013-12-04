#include <cstdio>
#include <cstring>

int f[4000]={1,1,0},a[4000],t;
char ch,s[10];
int ans,u[10],v[400000];

int prime(int c)
{
	int i;
	
	if(c<4000)return 1-f[c];
	for(int i=1;a[i]*a[i]<=c;i++)
		if(c%a[i]==0)return 0;
	return 1;
}

void dfs(int c)
{
	int i;

	if(v[c/32] & (1<<(c%32)))return;
	if(prime(c)) ans++;
	v[c/32]|=1<<(c%32);
	/*if(v[c])return;
	if(prime(c)) ans++;
	v[c]=1;*/
	for(i=0;s[i];i++)
		if(! u[i])
		{
			u[i]=1;
			dfs(c*10+s[i]-'0');
			u[i]=0;
		}
}

int main()
{
	a[0]=0;
	for(int i=2;i<4000;i++)
	if(! f[i])
	{
		a[++a[0]]=i;
		for(int j=2;j*i<4000;j++)
			f[i*j]=1;
	}
	scanf("%d%c",&t,&ch);
	while (t--)
	{
		scanf("%s",s);
		ans=0;
		memset(u,0,sizeof(u));
		memset(v,0,sizeof(v));
		dfs(0);
		printf("%d\n",ans);
	}
	
	return 0;
}