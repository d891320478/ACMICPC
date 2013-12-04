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
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 110
#define M 4
#define MOD 100000
int a[N][N],b[N][N],c[N][N],n;
int id(char c)
{
	if(c=='A') return 0;
	if(c=='C') return 1;
	if(c=='G') return 2;
	if(c=='T') return 3;
}
struct autoac
{
	int next[N][M],fail[N],end[N];
	int L,root;
	int newnode(){for(int i=0;i<M;i++) next[L][i]=-1; end[L++]=0; return L-1; }
	void init(){ L=0; root=newnode(); }
	void insert(char *buf,int val)
	{ int u=root;
		for(int i=0;buf[i];i++)
		{	if(next[u][id(buf[i])]==-1) next[u][id(buf[i])]=newnode();
			u=next[u][id(buf[i])];
		}end[u]+=val;
	}
	void build()
	{
		queue<int> q;
		for(int i=0;i<M;i++)
			if(next[root][i]==-1) next[root][i]=root;
			else{ fail[next[root][i]]=root; q.push(next[root][i]); }
		while (! q.empty())
		{
			int u=q.front(); q.pop(); //end[now]+=end[fail[now]];
			for(int i=0;i<M;i++)
				if(next[u][i]==-1) next[u][i]=next[fail[u]][i];
				else{ fail[next[u][i]]=next[fail[u]][i]; q.push(next[u][i]); }
		}
	}
	void matrix()
	{
		for(int i=0;i<L;i++)
		for(int j=0;j<M;j++)
			if(! end[next[i][j]])
			b[i][next[i][j]]++;
	}
}trie;
int m,sz;
char s[N];
void mm(int a[][N],int b[][N])
{
	memset(c,0,sizeof(c));
	for(int i=0;i<sz;i++)
	for(int j=0;j<sz;j++)
	for(int k=0;k<sz;k++)
		c[i][j]=(c[i][j]+a[i][k]*b[k][j])%100000;
	for(int i=0;i<sz;i++)
	for(int j=0;j<sz;j++)
		a[i][j]=c[i][j];
}
void matrixm()
{
	memset(a,0,sizeof(a));
	for(int i=0;i<sz;i++) a[i][i]=1;
	while (n)
	{
		if(n & 1) mm(a,b);
		mm(b,b);
		n>>=1;
	}
}
int main ()
{
	scanf("%d%d",&m,&n);
	trie.init();
	while (m--)
	{
		scanf("%s",s);
		trie.insert(s,1);
	}
	trie.build();
	trie.matrix();
	sz=trie.L;
	matrixm();
	int ans=0;
	for(int i=0;i<sz;i++)
		ans=(ans+a[0][i])%MOD;
	printf("%d\n",ans);
	return 0;
}