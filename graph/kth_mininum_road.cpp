K短路问题（POJ 2449）
#define maxn 10010
#define maxm 100010
const int inf = 0x3f3f3f3f;
int ans[maxn];
typedef pair<int,int> T;
struct Nod {
	int b, val, next;
	void init(int b, int val, int next) 
	{		this->b = b;	this->val = val;		this->next = next;	}
};
struct Dijkstra {
	int E[maxn], n;				//图
	Nod buf[maxm];	int len;	//资源
	int d[maxn];				//最短距离
	void init(int n) 
	{		this->n = n;	memset(E, 255, sizeof(E));	len = 0;	}
	void addEdge(int a, int b, int val)
	{	buf[len].init(b, val, E[a]);	E[a] = len ++;		}
	void solve(int s) {
		static priority_queue<T, vector<T>, greater<T> > q;
		while(!q.empty())	q.pop();
		memset(d, 63, sizeof(d));		d[s] = 0;	q.push(T(0, s));
		int u, du, v, dv;
		while(!q.empty()) {
			u = q.top().second;
			du = q.top().first;
			q.pop();
			if(du != d[u])	continue;
			for(int i = E[u]; i != -1; i = buf[i].next) {
				v = buf[i].b;	dv = du + buf[i].val;
				if(dv < d[v]) 
				{	d[v] = dv;		q.push(T(dv, v));		}
			}
		}
	}
};Dijkstra dij;
struct cmp {
	bool operator () (const T & a,const T & b) const {
		if(a.first+dij.d[a.second] == b.first+dij.d[b.second])
			return a.first > b.first;
		return a.first+dij.d[a.second]>b.first+dij.d[b.second];
	}
};
struct AStar {					//Astar求解k短路
	int E[maxn], n;				//图
	Nod buf[maxm];	int len;	//资源
	int cnt[maxn];				//记录次数
	void init(int n) 
	{	this->n = n;	memset(E, 255, sizeof(E));	len = 0;	dij.init(n);		}
	void addEdge(int a, int b, int val) {
		buf[len].init(b, val, E[a]);	E[a] = len ++;
		dij.addEdge(b, a, val);
	}
	/**
	 * 注释：
	 * 1.k=1是最短路，以此类推
	 * 2.k短路和k-1短路可能相同！
	 * 3.没有k短路返回-1
	 */
	int solve(int s, int t, int k) {
		if(s == t)	k ++;		//假设两个点合并在一起不算路!!
		static priority_queue<T, vector<T>, cmp> q;
		while(!q.empty())	q.pop();
		dij.solve(t);
		if(dij.d[s] == inf)	return -1;	//根本就没有路！
		int u, du, v, dv;		memset(cnt, 0, sizeof(cnt));
		q.push(T(0, s));		//T.first是f(n), T.second是n
		while(!q.empty()) {
			u = q.top().second;	du = q.top().first;	q.pop();		cnt[u] ++;
			//即当前是到u点的cnt[u]短路
			if(u==t)ans[cnt[u]]=du;
			if(cnt[t] == k)	return du;
			if(cnt[u] > k)	continue;	//大于k，我不在需要你了！【这句很危险！不删不一定正确，删去一定正确！】
			for(int i = E[u]; i != -1; i = buf[i].next) {
				v = buf[i].b;
				dv = du + buf[i].val;
				q.push(T(dv, v));		//松弛伙伴！
			}
		}
		return -1;
	}
} as;
int main ()
{
	int n,m,k,a,b,c,s,t;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		as.init(n);
		while (m--)
		{	scanf("%d%d%d",&a,&b,&c);		as.addEdge(a-1,b-1,c);	}
		scanf("%d%d%d",&s,&t,&k);
		printf("%d\n",as.solve(s-1,t-1,k));
	}
	return 0;
}
