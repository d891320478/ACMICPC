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
#define N 500010
#define M 26
struct autoac
{
	int next[N][M],fail[N];
	vector<int> end[N];
	int L,root;
	int newnode(){for(int i=0;i<M;i++) next[L][i]=-1; end[L].clear(); return L++; }
	void init(){ L=0; root=newnode(); }
	void insert(char *buf,int val)
	{
	    int u=root;
		for(int i=0;buf[i];i++)
		{
			if(next[u][buf[i]-'a']==-1) next[u][buf[i]-'a']=newnode();
			u=next[u][buf[i]-'a'];
		}
		end[u].push_back(val);
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
			for(vector<int>::iterator iter=end[fail[u]].begin();iter!=end[fail[u]].end();++iter)
			    end[u].push_back(*iter);
			for(int i=0;i<M;i++)
				if(next[u][i]==-1) next[u][i]=next[fail[u]][i];
				else{ fail[next[u][i]]=next[fail[u]][i]; q.push(next[u][i]); }
		}
		for(int i=0;i<L;++i)
		{
		    sort(end[i].begin(),end[i].end());
		    vector<int>::iterator iter=unique(end[i].begin(),end[i].end());
		    end[i].erase(iter,end[i].end());
		}
	}
	void query(char*,int);
}trie;
char s[1010][1010];
int a[1010][1010];
char t[110][110];
int n,m,x,y;
void autoac::query(char* buf,int c)
{
	int u=root,ans=0;
    for(int i=0;buf[i];i++)
	{
	    u=next[u][buf[i]-'a'];
	    if(! end[u].empty())
	    for(vector<int>::iterator iter=end[u].begin();iter!=end[u].end();++iter)
	        if(c-(*iter)>=0) ++a[c-(*iter)][i-y+1];
	}
}
int main ()
{
    while (scanf("%d %d",&n,&m)!=-1)
    {
        for(int i=0;i<n;++i) scanf("%s",s[i]);
        scanf("%d %d",&x,&y);
        for(int i=0;i<x;++i) scanf("%s",t[i]);
        memset(a,0,sizeof(a));
        trie.init();
        for(int i=0;i<x;++i) trie.insert(t[i],i);
        trie.build();
        for(int i=0;i<n;++i) trie.query(s[i],i);
        int ans=0;
        for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(a[i][j]>=x) ++ans;
        printf("%d\n",ans);
    }
    return 0;
}
