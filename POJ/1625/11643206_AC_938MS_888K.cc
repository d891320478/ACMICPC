#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 110
#define MM 260
int n,m,p;
char hash[NN];
int dp[110][110],dp1[110][110],ans[110];
int gethash(char c)
{
	for(int i=0;hash[i];i++)
		if(hash[i]==c) return i;
}
struct autoac
{
	int next[NN][MM],fail[NN],end[NN];
	int L,root,M;
	int newnode(){for(int i=0;i<M;i++) next[L][i]=-1; end[L++]=0; return L-1; }
	void init(){ L=0; root=newnode(); }
	void insert(char *buf)
	{ int u=root;
		for(int i=0;buf[i];i++)
		{
			int hh=gethash(buf[i]);
			if(next[u][hh]==-1) next[u][hh]=newnode();
			u=next[u][hh];
		}end[u]=1;
	}
	void build()
	{
		queue<int> q;
		for(int i=0;i<M;i++)
			if(next[root][i]==-1) next[root][i]=root;
			else{ fail[next[root][i]]=root; q.push(next[root][i]); }
		while (! q.empty())
		{
			int u=q.front(); q.pop();
			end[u]|=end[fail[u]];
			for(int i=0;i<M;i++)
				if(next[u][i]==-1) next[u][i]=next[fail[u]][i];
				else{ fail[next[u][i]]=next[fail[u]][i]; q.push(next[u][i]); }
		}
	}
}trie;
char s[MM];
void pluss(int *a,int *b)
{
	int c[NN];
	memset(c,0,sizeof(c));
	for(int i=1;i<=100;i++) c[i]=a[i]+b[i];
	for(int i=1;i<100;i++)
	{
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	c[0]=100;
	while (c[c[0]]==0) c[0]--;
	for(int i=0;i<=c[0];i++) a[i]=c[i];
}
int main ()
{
	while(scanf("%d %d %d",&n,&m,&p)!=-1)
	{
		gets(s); gets(hash);
		trie.M=n;
		trie.init();
		for(int i=0;i<p;i++)
		{
			gets(s);
			trie.insert(s);
		}
		trie.build();
		memset(dp1,0,sizeof(dp1));
		for(int i=0;i<=trie.L;i++)
			dp1[i][0]=1;
		dp1[1][0]=dp1[1][1]=1;
		for(int i=1;i<=m;i++)
		{
			memset(dp,0,sizeof(dp));
			for(int i=0;i<=trie.L;i++)
				dp[i][0]=1;
			for(int j=1;j<=trie.L;j++)
			//if(! trie.end[j-1])
			for(int k=0;k<n;k++)
				if(! trie.end[trie.next[j-1][k]])
				pluss(dp[trie.next[j-1][k]+1],dp1[j]);
			for(int x=0;x<=trie.L;x++)
			for(int y=0;y<=dp[x][0];y++)
				dp1[x][y]=dp[x][y];
		}
		memset(ans,0,sizeof(ans));
		ans[0]=1;
		for(int i=1;i<=trie.L;i++)
			pluss(ans,dp[i]);
		printf("%d",ans[ans[0]]);
		for(int i=ans[0]-1;i>0;i--)
		{
			/*
				 if(ans[i]<10) printf("000");
			else if(ans[i]<100) printf("00");
			else if(ans[i]<1000) printf("0");
			
			else if(ans[i]<10000) printf("0000");
			else if(ans[i]<100000) printf("000");
			else if(ans[i]<1000000) printf("00");
			else if(ans[i]<10000000) printf("0");
			*/
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}