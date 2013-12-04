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
#define N 1000010
#define M 26
const int lx[]={-1,-1,0,1,1,1,0,-1};
const int ly[]={0,1,1,1,0,-1,-1,-1};
int ans[1010][4],len[1010];
int n,m,w;
char s[1010][1010],x[1010];
struct autoac
{
	int next[N][M],fail[N],end[N];
	int L,root;
	int newnode(){for(int i=0;i<M;i++) next[L][i]=-1; end[L++]=0; return L-1; }
	void init(){ L=0; root=newnode(); }
	void insert(char *buf,int val)
	{ int u=root;
		for(int i=0;buf[i];i++)
		{	if(next[u][buf[i]-'A']==-1) next[u][buf[i]-'A']=newnode();
			u=next[u][buf[i]-'A'];
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
			for(int i=0;i<M;i++)
				if(next[u][i]==-1) next[u][i]=next[fail[u]][i];
				else{ fail[next[u][i]]=next[fail[u]][i]; q.push(next[u][i]); }
		}
	}
	void query(int x,int y,int c)
	{	int u=root;
		for(int i=x,j=y;i>=0 && i<n && j>=0 && j<m;i+=lx[c],j+=ly[c])
		{	u=next[u][s[i][j]-'A'];
			for(int v=u;v!=root;v=fail[v])
			if(end[v])
			{
				int id=end[v];
				ans[id][0]=i-(len[id]-1)*lx[c];
				ans[id][1]=j-(len[id]-1)*ly[c];
				ans[id][2]=c;
			}
		}
	}
}trie;
int main ()
{
	scanf("%d %d %d",&n,&m,&w);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	trie.init();
	for(int i=1;i<=w;i++)
	{
		scanf("%s",x);
		len[i]=strlen(x);
		trie.insert(x,i);
	}
	trie.build();
	for(int i=0;i<n;i++)
	{
		trie.query(i,0,1);
		trie.query(i,0,2);
		trie.query(i,0,3);
		trie.query(i,m-1,5);
		trie.query(i,m-1,6);
		trie.query(i,m-1,7);
	}
	for(int i=0;i<m;i++)
	{
		trie.query(0,i,3);
		trie.query(0,i,4);
		trie.query(0,i,5);
		trie.query(n-1,i,0);
		trie.query(n-1,i,1);
		trie.query(n-1,i,7);
	}
	for(int i=1;i<=w;i++)
		printf("%d %d %c\n",ans[i][0],ans[i][1],ans[i][2]+'A');
	return 0;
}