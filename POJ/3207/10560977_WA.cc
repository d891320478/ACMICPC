#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
const bool db = false;
const int MAXN = 1010;
const int MAXV = 1000010;
#define EMPTY -1
#define RED 0
#define BLUE 1
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
    dfn[x]=low[x]=mark++;int y;
    S.push(x);
    FOREACH(head, data, next, x, y)
    {
    	if(dfn[y] == -1)DFS(y);
        if (color[y] == -1) low[x]=min(low[x], dfn[y]),low[x]=min(low[x], low[y]);
    }
    if (dfn[x]==low[x])
    {
        int tmp;
        do
        	tmp = S.pop(),color[tmp] = cnt;
        while (tmp != x);
      	cnt++;
    }
    return 1;
}
void Gabow()
{
    memset(dfn, -1, sizeof(dfn));
    memset(color, -1, sizeof(color));
    cnt = mark = S.top = 0;
    for (int i = 0; (i<N&&dfn[i]==-1)&&DFS(i), i < N; i++);
}
void ColorToBlue(int x)
{
    int y;
    color2[x] = BLUE;
    FOREACH(nhead, ndata, nnext, x, y)
    	if (color2[y] == EMPTY) ColorToBlue(y);
}
bool TwoSat()
{
    Gabow();
    for (int i = 0; i+1 < N; i+=2)
    	if (color[i] == color[i+1])
		{
			printf("the evil panda is lying again\n");
			return 0;
		}
	printf("panda is telling the truth...\n");
	return 1;
    memset(in_degree, 0, sizeof(in_degree));
    memset(color2, EMPTY, sizeof(color2));
    stop = 1;
    memset(shead, -1, sizeof(shead));
    for (int i = 0; i < N; i++)
    	ADD(shead, sdata, snext, stop, color[i], i);
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
    for (int i = 0; i < cnt; i++)
    	if (in_degree[i] == 0) Q.push(i);
    while (!Q.empty())
    {
    	int x = Q.front();
    	Q.pop();
        if (color2[x] != EMPTY) continue;
        color2[x] = RED;
        int y;
        FOREACH(nhead, ndata, nnext, x, y)
        {
        	in_degree[y]--;
        	if (in_degree[y] == 0) Q.push(y);
        }
        int tmp;
        FOREACH(shead, sdata, snext, x, y)
        	if (color2[ color[ tmp = CHANGE(y)] ] == EMPTY)
                ColorToBlue(color[ CHANGE(y) ]);
    }
    memset(color, RED, sizeof(color));
    for (int i = 0; i < cnt; i++)
    	if (color2[i] == BLUE)
    	{
    		int y;
            FOREACH(shead, sdata, snext, i, y)
            	color[y] = BLUE;
        }
	return true;
}
int a[MAXN][2];
int main ()
{
	int n,m,i,j;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		N=2*n;
		top=0;
		memset(head,-1,sizeof(head));
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i][0],&a[i][1]);
			if(a[i][0]>a[i][1])swap(a[i][0],a[i][1]);
			for(j=0;j<i;j++)
			{
				if(a[j][0]>a[i][0] && a[j][0]<a[i][1])
				{
					ADD(head, data, next, top, j*2, i*2+1);
					ADD(head, data, next, top, i*2, j*2+1);
				}
			}
		}
		TwoSat();
	}
	return 0;
}