#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
#define N 10010
#define M 50010
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
	int heap[N],lh;
	int e[N],n;
	nod buf[M];
	int len;
	int d[N],vis[N];
	void build_down(int s)
	{
		int father=s,son=s*2;
		while (son<=lh)
		{
			if(son+1<=lh && d[heap[son]]>d[heap[son+1]])son++;
			if(d[heap[father]]>d[heap[son]])
			{
				swap(vis[heap[father]],vis[heap[son]]);
				swap(heap[father],heap[son]);
				father=son;		son=father*2;
			}else return;
		}
	}
	void build_up(int s)
	{
		int son=s,father=s/2;
		while (father>=1)
		{
			if(d[heap[father]]>d[heap[son]])
			{
				swap(vis[heap[father]],vis[heap[son]]);
				swap(heap[father],heap[son]);
				son=father;		father=son/2;
			}else return;
		}
	}
	
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
		memset(d,63,sizeof(d));
		memset(vis,0,sizeof(vis));
		lh=0;	vis[s]=1; heap[++lh]=s; d[s]=0;
		int u,v;
		while (lh>0)
		{
			u=heap[1];
			vis[u]=0;
			heap[1]=heap[lh--];
			build_down(1);
			for(int i=e[u];i!=-1;i=buf[i].next)
			{
				v=buf[i].b;
				if(d[v]>d[u]+buf[i].val)
				{
					d[v]=d[u]+buf[i].val;
					if(! vis[v])
					{	heap[++lh]=v;		vis[v]=lh;		build_up(lh);		}
					else
						if(vis[v]/2>0)
						if(d[v]<d[heap[vis[v]/2]]) build_up(vis[v]);
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