#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
#define N 10010
#define M 100010
#define INF 0x3f3f3f3f
typedef pair<int,int> T;
int kkkk,ans[N];
struct nod
{
	int b,val,next;
	void init(int b,int val,int next)
	{
		this->b=b;
		this->val=val;
		this->next=next;
	}
};
struct dijkstra
{
	int e[N],n;
	nod buf[M];
	int len;
	int d[N];
	void init(int n)
	{
		this->n=n;
		memset(e,-1,sizeof(e));
		len=0;
	}
	void addedge(int a,int b,int val)
	{
		buf[len].init(b,val,e[a]);
		e[a]=len++;
	}
	void solve(int s)
	{
		//static priority_queue< T,vector<T>,greater<T> > q;
		//while(! q.empty()) q.pop();
		queue<int>q;
		int vis[N]={0};
		memset(d,63,sizeof(d));
		d[s]=0;
		vis[s]=1;
		//q.push(T(0,s));
		q.push(s);
		int u,du,v,dv;
		while (! q.empty())
		{
			//u=q.top().second;
			//du=q.top().first;
			//q.pop();
			u=q.front();
			vis[u]=0;
			q.pop();
			//if(du!=d[u]) continue;
			for(int i=e[u];i!=-1;i=buf[i].next)
			{
				v=buf[i].b;
				dv=d[u]+buf[i].val;
				if(dv<d[v])
				{
					d[v]=dv;
					//q.push(T(dv,v));
					if(! vis[v]) vis[v]=1;
				}
			}
		}
	}
}dij;
struct cmp
{
	bool operator () (const T &a,const T &b)
	const{
		if(a.first+dij.d[a.second]==b.first+dij.d[b.second])
			return a.first>b.first;
		return a.first+dij.d[a.second]>b.first+dij.d[b.second];
	}
};
struct astar
{
	int e[N],n;
	nod buf[M];
	int len;
	int cnt[N];
	void init(int n)
	{
		this->n=n;
		memset(e,-1,sizeof(e));
		len=0;
		dij.init(n);
	}
	void addedge(int a,int b,int val)
	{
		buf[len].init(b,val,e[a]);
		e[a]=len++;
		dij.addedge(b,a,val);
	}
	int solve(int s,int t,int k)
	{
		static priority_queue<T,vector<T>,cmp> q;
		while(! q.empty()) q.pop();
		dij.solve(t);
		if(dij.d[s]==INF) return -1;
		int u,du,v,dv;
		memset(cnt,0,sizeof(cnt));
		q.push(T(0,s));
		while (! q.empty())
		{
			u=q.top().second;
			du=q.top().first;
			q.pop();
			cnt[u]++;
			//if(u==t)ans[cnt[u]]=du;
			if(cnt[t]==k) return du;
			if(cnt[u]>k) continue;
			for(int i=e[u];i!=-1;i=buf[i].next)
			{
				v=buf[i].b;
				dv=du+buf[i].val;
				q.push(T(dv,v));
			}
		}
		return -1;
	}
}as;
int main ()
{
	int n,m,k,a,b,c,s,t;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		as.init(n);
		while (m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			as.addedge(a-1,b-1,c);
		}
		scanf("%d%d%d",&s,&t,&k);
		printf("%d\n",as.solve(s-1,t-1,k));
	}
	return 0;
}