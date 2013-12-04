#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 1005;
const int maxm = 100005;
const double EPS = 1e-10;
const int INF = INT_MAX/2;

struct EDGE
{
    int a,b;
    int next;
};

int nx,ny,m;
EDGE edge[maxm];
int edge_num,ans;
int first[maxn];
int cx[maxn], cy[maxn];// cx[i]表示xi对应的匹配，cy[i]表示yi对应的匹配.
int distx[maxn], disty[maxn]; // 层的概念，即在BFS中的第几层.
int que[maxn];
int head,tail;

void AddEdge(int a,int b)
{
    edge[edge_num].a = a;
    edge[edge_num].b = b;
    edge[edge_num].next = first[a];
    first[a] = edge_num++;
}

bool BFS(void)
{
    int i, j, k;
    bool flag(0);
    int h, t;
    memset(distx,0,sizeof(distx));
    memset(disty,0,sizeof(disty));
    head = tail = 0;
    for (i = 1; i <= nx; i++)
        if (cx[i] == -1) que[tail++] = i;
    while (head != tail)
    {
        for (h = head, t = tail; h != t; h = (h + 1) % maxn)
        {
            i = que[h];
            for (k = first[i]; k != -1; k = edge[k].next)
            {
                j = edge[k].b;
                if (!disty[j])
                {
                    disty[j] = distx[i] + 1;
                    if (cy[j] == -1) flag = 1;
                    else
                    {
                        distx[cy[j]] = disty[j] + 1;
                        que[tail] = cy[j];
                        tail = (tail + 1) % maxn;
                    }
                }
            }
        }
        head = t;
    }
    return flag;
}

bool DFS(int i)
{
    int j, k;
    for (k = first[i]; k != -1; k = edge[k].next)
    {
        j = edge[k].b;
        if (disty[j] == distx[i] + 1)
        { // 说明j是i的后继结点.
            disty[j] = 0; // j被用过了，不能再作为其他点的后继结点了.
            if (cy[j] == -1 || DFS(cy[j]))
            {
                cx[i] = j, cy[j] = i;
                return 1;
            }
        }
    }
    return 0;
}

void Hopcroft_Karp()
{
    int i, j;
    while (BFS())
        for (i = 1; i <= nx; i++)
            if (cx[i] == -1 && DFS(i)) ans++;
}

int main()
{
    int i,j,a,b,t;

    scanf("%d",&t);
    while (t--)
    {
    	scanf("%d%d",&nx,&m);
    	ny=nx;
		fill(cx,cx+maxn,-1);
		fill(cy,cy+maxn,-1);
		fill(first,first+maxn,-1);
		edge_num=ans=0;
        while (m--)
        {
            scanf("%d%d",&a,&b);
            AddEdge(a,b);
        }
        Hopcroft_Karp();
        printf("%d\n",nx-ans);
    }
    return 0;
}