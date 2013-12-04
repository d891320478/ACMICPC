#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
const bool db = false;
const int MAXN = 2000+10;
const int MAXV = 8000000+10;
#define ADD(head, data, next, top, x, y) data[top]=y,next[top]=head[x],head[x]=top,top++
#define FOREACH(head, data, next, x, y) for (int _i=head[x];y=data[_i],_i>0;_i=next[_i])
#define CHANGE(x) x&1?x-1:x+1
struct stack
{
	int top, data[MAXN];
    void push(int x){data[top++]=x;}
    int pop(){return data[--top];}
}S;
int dfn[MAXN], low[MAXN], color[MAXN], color2[MAXN],cnt, mark,N,head[MAXN],data[MAXV], next[MAXV],top,nhead[MAXN];
int ndata[MAXV],nnext[MAXV],ntop,shead[MAXN],sdata[MAXN], snext[MAXN],stop,in_degree[MAXN],ncolor[MAXN];
int DFS(int x)
{
    dfn[x]=low[x]=mark++;int y;    S.push(x);
    FOREACH(head, data, next, x, y)
    {
    	if(dfn[y] == -1)DFS(y);
        if (color[y] == -1) low[x]=min(low[x], dfn[y]),low[x]=min(low[x], low[y]);
    }
    if (dfn[x]==low[x])
    {
        int tmp;
        do   {tmp = S.pop(),color[tmp] = cnt;}   while (tmp != x);
      	cnt++;
    }
    return 1;
}
void Gabow()
{
    memset(dfn, -1, sizeof(dfn));    memset(color, -1, sizeof(color));
    cnt = mark = S.top = 0;
    for (int i = 0; (i<N&&dfn[i]==-1)&&DFS(i), i < N; i++);
}
void ColorTo1(int x)
{
    int y;
    color2[x] = 1;
    FOREACH(nhead, ndata, nnext, x, y)
    	if (color2[y] == -1) ColorTo1(y);
}
bool TwoSat()
{
    Gabow();
    for (int i = 0; i+1 < N; i+=2)
    	if (color[i] == color[i+1]){		printf("bad luck\n");	return 0;		}
    memset(in_degree, 0, sizeof(in_degree));
    memset(color2, -1, sizeof(color2));
    stop = 1;
    memset(shead, -1, sizeof(shead));
    for (int i = 0; i < N; i++)   	ADD(shead, sdata, snext, stop, color[i], i);
    ntop = 1;
    memset(nhead, -1, sizeof(nhead));
    for (int i = 0; i < N; i++)
    {
    	int x;
        FOREACH(head, data,next, i, x)
            if (color[i] != color[x])
     			ADD(nhead, ndata, nnext, ntop, color[x], color[i]),in_degree[color[i]]++;
    }
    queue<int> Q;
    for (int i = 0; i < cnt; i++)   	if (in_degree[i] == 0) Q.push(i);
    while (!Q.empty())
    {
    	int x = Q.front();   	Q.pop();
        if (color2[x] != -1) continue;
        color2[x] = 0;        int y;
        FOREACH(nhead, ndata, nnext, x, y)
        {
        	in_degree[y]--;
        	if (in_degree[y] == 0) Q.push(y);
        }
        int tmp;
        FOREACH(shead, sdata, snext, x, y)
        	if (color2[ color[ tmp = CHANGE(y)] ] == -1)
                ColorTo1(color[ CHANGE(y) ]);
    }
    memset(color, 0, sizeof(color));
    for (int i = 0; i < cnt; i++)
    	if (color2[i] == 1)
    	{
    		int y;
            FOREACH(shead, sdata, snext, i, y)       	color[y] = 1;
        }
    bool flag=0;
    for(int i=2;i<N;i++)
    	if(color[i]==0)
    	{
    		if(! flag)flag=1;
    		else printf(" ");
    		printf("%d",i/2);
    		if(i%2)printf("w");
    		else printf("h");
    	}
    printf("\n");
	return true;
}
int main ()
{
	int n,m;
	while (scanf("%d%d",&n,&m) && (n || m))
	{
		N=n*2;
		top=1;
		memset(head,-1,sizeof(head));
		ADD(head,data,next,top,0,1);
		while (m--)
		{
			int u,v; char a,b;
			scanf("%d%c %d%c",&u,&a,&v,&b);
			if(a=='h')u=u*2+1;
			else u=u*2;
			if(b=='h')v=v*2+1;
			else v=v*2;
			ADD(head,data,next,top,u,v^1);
			ADD(head,data,next,top,v,u^1);
		}
		TwoSat();
	}
	
	return 0;
}