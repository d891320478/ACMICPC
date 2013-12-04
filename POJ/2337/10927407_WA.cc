#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 1010
#define M 10010
char s[N][25],ch;
int id[N];
int into[27],out[27],n,g[27][27],vis[27],sum,use[N];
int ans[N];
void dfs(int s)
{
	int i;
	for(i=0;i<26;i++)
		if(g[s][i])
		{
			g[s][i]--;
			out[s]--;
			into[i]--;
			dfs(i);
		}
	ans[++ans[0]]=s;
}
void dfs1(int s)
{
	vis[s]=1;
	sum--;
	for(int i=0;i<26;i++)
		if((g[s][i] || g[i][s]) && ! vis[i]) dfs1(i);
}
int cmp(int a,int b)
{
	return strcmp(s[a],s[b])<=0;
}
int main ()
{
	int tt,i,j;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d%c",&n,&ch);
		for(i=0;i<n;i++) {scanf("%s",s[i]);id[i]=i;}
		SET(into,0);
		SET(use,0);
		SET(out,0);
		SET(g,0);
		SET(vis,0);
		sum=0;
		int start=s[0][0]-'a';
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			int l=strlen(s[i]);
			int l2=strlen(s[j]);
			if(! vis[s[j][0]-'a'])
			{
				vis[s[j][0]-'a']=1;
				sum++;
			}
			if(! vis[s[i][l-1]-'a'])
			{
				vis[s[i][l-1]-'a']=1;
				sum++;
			}
			if(s[i][l-1]==s[j][0])
			{
				g[s[i][l-1]-'a'][s[j][l2-1]-'a']=1;
				into[s[j][l2-1]-'a']++;
				out[s[i][l-1]-'a']++;
			}
		}
		SET(vis,0);
		dfs1(start);
		if(sum)
		{
			printf("***\n");
			continue;
		}
		int sum1=0,sum2=0;
		for(i=0;i<26;i++)
		{
			if(abs(out[i]-into[i])==1) sum1++;
			else if(out[i]!=into[i]) sum2++;
		}
		if(sum1!=0 && sum1!=2 || sum2!=0)
		{
			printf("***\n");
			continue;
		}
		ans[0]=0;
		for(i=0;i<26;i++)
			if(out[i]-into[i]==1)
			{
				dfs(i);
				break;
			}
		if(i>=26) dfs(start);
		int flag=0;
		sort(id,id+n,cmp);
		for(i=ans[0];i>1;i--)
		{
			for(int j=0;j<n;j++)
				if(! use[id[j]])
				if(s[id[j]][0]=='a'+ans[i] && s[id[j]][strlen(s[id[j]])-1]=='a'+ans[i-1])
				{
					use[id[j]]=1;
					if(! flag) flag=1;
					else printf(".");
					printf("%s",s[id[j]]);
				}
		}
		printf("\n");
	}
	
	return 0;
}