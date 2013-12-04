#include <cstdio>
#include <cstring>
#include <cassert>
#include <queue>
using namespace std;
#define MAXN 302
#define MAXM 400000
#define inf 999999999
typedef struct{
	int start,end;
	int cap,cost,flow;
	int prev,next;
	int rprev,rnext;
	int reverse;
}Edge;
Edge EB[2*MAXM];
int Adj[MAXN],rAdj[MAXN],EBc=1;
void min_cost_max_flow_init(){
	memset(EB,0,sizeof(EB));
	memset(Adj,0,sizeof(Adj));
	memset(rAdj,0,sizeof(rAdj));
	EBc=1;
}
/*AddEdge用来给定一组u,v,cap,cost将其加入图中
 * 它并不处理费用相同的重边，即不进行边的归并
 * 如果要处理边的合并，应另行修改此函数
 */
void AddEdge(int u,int v,int cap,int cost){
	//费用相同的重边不做归并
	if(cap==0){
		return;//容量为0的边没有意义，直接返回，不加入
	}
	EB[EBc].start=u;
	EB[EBc].end=v;
	EB[EBc].cap=cap;
	EB[EBc].cost=cost;
	EB[EBc].prev=EB[EBc].rprev=0;
	EB[EBc].next=EB[EBc].rnext=Adj[u];
	EB[EBc].reverse=EBc+1;

	EB[EBc+1].start=v;
	EB[EBc+1].end=u;
	EB[EBc+1].cap=0;
	EB[EBc+1].cost=-cost;
	EB[EBc+1].prev=EB[EBc+1].next=0;
	EB[EBc+1].rprev=EB[EBc+1].rnext=0;
	EB[EBc+1].reverse=EBc;

	if(Adj[u]!=0){
		EB[Adj[u]].prev=EB[Adj[u]].rprev=EBc;
	}
	Adj[u]=EBc;//完成对邻接表的插入
	rAdj[u]=Adj[u];//初始时邻接表与剩余邻接表完全相同
	EBc+=2;
}
/* min_cost_max_flow
 * 最小费用最大流 O(kVE^2)其中k是一小因子,搜索最短路采用SPFA
 * 不允许出现负回路，但是允许有负权边
 * 输入:n 节点数，s源，t汇
 * 输出:totalcost 总花费，返回totalflow总流量
 */
int min_cost_max_flow(int n,int s,int t,int &totalcost){
	int i,totalflow=0;
	int dist[MAXN];
	int Pi[MAXN];//Pi并不存储节点前驱，而是存储边前驱,它保存前驱边在EB数组中的下标
	bool inQ[MAXN];
	totalcost=0;
	queue<int> Q;
	while(1){
		for(i=1;i<=n;i++){//初始置所有点的距离为无穷
			dist[i]=inf;
		}
		memset(Pi,0,sizeof(Pi));
		memset(inQ,0,sizeof(inQ));
		dist[s]=0;//置源点距离为0
		Q.push(s);
		inQ[s]=1;
		while(!Q.empty()){
			int now=Q.front();
			Q.pop();
			inQ[now]=0;
			for(i=rAdj[now];i!=0;i=EB[i].rnext){//i是对应边在EB中的下标 now是点的当前点的编号
				if(EB[i].cost+dist[now]<dist[EB[i].end]){
					dist[EB[i].end]=EB[i].cost+dist[now];
					Pi[EB[i].end]=i;//保存点的搜入边
					if(!inQ[EB[i].end]){//若此点没有在队列中，则入队
						Q.push(EB[i].end);
						inQ[EB[i].end]=1;
					}
				}
			}
		}
		if(dist[t]>=inf){//汇点的距离为inf说明无法找到增广路，故寻找增广路的过程结束
			break;
		}
		int d=inf;//d代表了增广路径的流量
		for(i=Pi[t];i!=0;i=Pi[EB[i].start]){
			if(d>EB[i].cap-EB[i].flow){//如果当前流量大于路径上的剩余容量
				d=EB[i].cap-EB[i].flow;
			}	
		}//找到增广路径流量d
		totalflow+=d;
		totalcost+=d*dist[t];
		for(i=Pi[t];i!=0;i=Pi[EB[i].start]){
			EB[i].flow+=d;
			EB[EB[i].reverse].flow-=d;
			if(EB[i].cap-EB[i].flow==0){//没有剩余容量，此边应删除出剩余邻接表
				if(EB[i].rnext!=0){//i不是表尾，则将后点前拉
					EB[EB[i].rnext].rprev=EB[i].rprev;
				}
				if(EB[i].rprev!=0){//i不是表头，则将前点后拉
					EB[EB[i].rprev].rnext=EB[i].rnext;
				}else{//i是表头，则要更新rAdj[EB[i].start]
					rAdj[EB[i].start]=EB[i].rnext;
				}
				EB[i].rprev=EB[i].rnext=0;//i的前后继置零
			}
			//i的对应边此时必然有了剩余容量，如果不在表中，则加入
			assert(EB[EB[i].reverse].cap-EB[EB[i].reverse].flow>0);//i的对应边应有剩余容量
			if(EB[EB[i].reverse].rprev==0 && EB[EB[i].reverse].rnext==0 && rAdj[EB[EB[i].reverse].start]!=EB[i].reverse){
				EB[EB[i].reverse].rprev=0;
				EB[EB[i].reverse].rnext=rAdj[EB[EB[i].reverse].start];
				if(rAdj[EB[EB[i].reverse].start]!=0){
					EB[rAdj[EB[EB[i].reverse].start]].rprev=EB[i].reverse;
				}
				rAdj[EB[EB[i].reverse].start]=EB[i].reverse;
			}
		}//到此 增广路更新完毕

	}
	return totalflow;
}
/*模板使用方法:
 * 首先调用min_cost_max_flow_init()进行初始化
 * 然后使用AddEdge(u,v,cap,cost)将边加入表
 * 调用min_cost_max_flow(n,s,t,totalcost)求最大流
 */
int n,m,k,s,t,saber;
int sum[MAXN],flag,a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN][MAXN],ans;
	
int main()
{
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
    	if(n==0 && m==0 && k==0)break;
    	flag=1;
    	memset(sum,0,sizeof(sum));
    	for(int i=1;i<=n;i++)
    	for(int j=1;j<=k;j++)
    	{
    		scanf("%d",&a[i][j]);
    		sum[j]-=a[i][j];
    	}
    	for(int i=1;i<=m;i++)
    	for(int j=1;j<=k;j++)
    	{
    		scanf("%d",&b[i][j]);
    		sum[j]+=b[i][j];
    	}
    	for(int i=1;i<=k;i++)
    	for(int j=1;j<=n;j++)
    	for(int l=1;l<=m;l++) 
    		scanf("%d",&c[i][j][l]);
    	for(int i=1;i<=k;i++)
    		if(sum[i]<0){flag=0;break;}
    	if(!flag){printf("-1\n");continue;}
        s=1;t=m+n+2;saber=0;
        for(int z=1;z<=k;z++)
        {
        	min_cost_max_flow_init();
		    for(int i=1;i<=m;i++)
		    	AddEdge(s,i+1,100000,0);
		    for(int i=1;i<=m;i++)
		    for(int j=m+1;j<=m+n;j++)
		    	AddEdge(i+1,j+1,b[i][z],c[z][j-m][i]);
		    for(int i=m+1;i<=m+n;i++)
		    	AddEdge(i+1,t,a[i-m][z],0);
		    ans=0;
		    min_cost_max_flow(m+n+2,s,t,ans);
		    saber+=ans;
		}
        printf("%d\n",saber);
    }
	return 0;
}