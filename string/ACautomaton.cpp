#define N 500010
#define M 26
struct autoac
{
	int next[N][M],fail[N],end[N];
	int L,root;
	int newnode(){for(int i=0;i<M;i++) next[L][i]=-1; end[L++]=0; return L-1; }
	void init(){ L=0; root=newnode(); }
	void insert(char *buf,int val)
	{ int u=root;
		for(int i=0;buf[i];i++)
		{	if(next[u][buf[i]-'a']==-1) next[u][buf[i]-'a']=newnode();
			u=next[u][buf[i]-'a'];
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
	int query(char *buf)
	{	int u=root,ans=0;
		for(int i=0;buf[i];i++)
		{	u=next[u][buf[i]-'a'];
			for(int v=u;v!=root;v=fail[v]){ ans+=end[v]; end[v]=0; }
		}
		return ans;
	}
}trie;
