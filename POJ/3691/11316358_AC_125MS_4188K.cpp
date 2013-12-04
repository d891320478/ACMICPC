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
#define N 1010
#define M 4
int id(char c)
{
	if(c=='A') return 0;
	if(c=='C') return 1;
	if(c=='G') return 2;
	return 3;
}
struct autoac
{
	int next[N][M],fail[N],end[N];
	int L,root;
	int newnode(){for(int i=0;i<M;i++) next[L][i]=-1; end[L++]=0; return L-1; }
	void init(){ L=0; root=newnode(); }
	void insert(char *buf)
	{ int u=root;
		for(int i=0;buf[i];i++)
		{	if(next[u][id(buf[i])]==-1) next[u][id(buf[i])]=newnode();
			u=next[u][id(buf[i])];
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
int dp[N][N];
int main ()
{
	int tt=0,n;
	char s[N];
	while (scanf("%d",&n) && n)
	{
		trie.init();
		memset(dp,-1,sizeof(dp));
		dp[0][0]=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			trie.insert(s);
		}
		trie.build();
		scanf("%s",s);
		int l=strlen(s);
		for(int i=1;i<=l;i++)
		for(int j=0;j<trie.L;j++)
		{
			if(trie.end[j]) continue;
			if(dp[i-1][j]==-1) continue;
			for(int k=0;k<4;k++)
			{
				if(dp[i][trie.next[j][k]]==-1 || dp[i][trie.next[j][k]]>dp[i-1][j]+(id(s[i-1])!=k))
					dp[i][trie.next[j][k]]=dp[i-1][j]+(id(s[i-1])!=k);
			}
		}
		int ans=-1;
		for(int i=0;i<trie.L;i++)
			if(dp[l][i]!=-1 && ! trie.end[i])
			if(ans==-1 || ans>dp[l][i]) ans=dp[l][i];
		printf("Case %d: %d\n",++tt,ans);
	}
	return 0;
}