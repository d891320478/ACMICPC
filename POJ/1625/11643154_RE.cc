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
#include<vector>
#include<utility>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define MM 210
struct bignumber
{
	int n;
	int a[MM];
	void clear()
	{ n=0; memset(a,0,sizeof(a)); }
	void init(char *s)
	{
		clear();
		n=strlen(s); a[0]=0;
		for(int i=0;s[i];i++) a[n-i]=s[i]-'0';
		while (a[n]==0 && n>1) n--;
	}
	void init(int s)
	{
		clear();
		if(s==0) { n=1; a[1]=0; return; }
		while (s) { a[++n]=s%10; s/=10; }
	}
	void output()
	{ for(int i=n;i>0;i--) printf("%d",a[i]); printf("\n"); }
	int operator < (bignumber b)
	{
		if(n<b.n) return 1; if(n>b.n) return 0;
		for(int i=n;i>0;i--)
		{
			if(a[i]<b.a[i]) return 1;
			if(a[i]>b.a[i]) return 0;
		}
		return 0;
	}
	int operator == (bignumber b)
	{
		if(n!=b.n) return 0;
		for(int i=n;i>0;i--)
			if(a[i]!=b.a[i]) return 0;
		return 1;
	}
};
bignumber operator + (bignumber a,bignumber b)
{
	a.n=max(a.n,b.n);
	for(int i=1;i<=a.n;i++)
	{
		a.a[i]+=b.a[i];
		a.a[i+1]+=a.a[i]/10;
		a.a[i]%=10;
	}
	if(a.a[a.n+1]>0) a.n++;
	return a;
}
#define N 2510
#define M 140
int hash[M];
int n,m,p;
bignumber dp[2][N];
char s[55];
struct autoac
{
	int next[N][M],fail[N],end[N];
	int L,root;
	int newnode(){for(int i=0;i<M;i++) next[L][i]=-1; end[L++]=0; return L-1; }
	void init(){ L=0; root=newnode(); }
	void insert(char *buf,int val)
	{ int u=root;
		for(int i=0;buf[i];i++)
		{	if(next[u][hash[buf[i]]]==-1) next[u][hash[buf[i]]]=newnode();
			u=next[u][hash[buf[i]]];
		}end[u]=val;
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
int main ()
{
	scanf("%d%d%d",&n,&m,&p);
	gets(s); gets(s);
	for(int i=0;s[i];i++) hash[s[i]]=i;
	trie.init();
	while (p--)
	{
		gets(s);
		trie.insert(s,1);
	}
	trie.build();
	for(int i=0;i<=trie.L;i++) dp[0][i].init(0);
	dp[0][1].init(1);
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=trie.L;j++) dp[i&1][j].init(0);
		for(int j=1;j<=trie.L;j++)
		for(int k=0;k<n;k++)
		if(!trie.end[trie.next[j-1][k]])
			dp[i&1][trie.next[j-1][k]+1]=dp[i&1][trie.next[j-1][k]+1]+dp[(i&1)^1][j];
	}
	bignumber ans;
	ans.init(0);
	for(int j=1;j<=trie.L;j++)
		ans=ans+dp[m&1][j];
	ans.output();
	return 0;
}