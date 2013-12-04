#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define eps 1e-5
#define MAXN 555
#define MAXM 55555
#define INF 100000007
using namespace std;
struct EDGE
{
    int cost, cap, v;
    int next, re;
}edge[MAXM];
int head[MAXN], e;
int vis[MAXN], d[MAXN];
int ans, cost, src, des, n;
void init()
{
    memset(head, -1, sizeof(head));
    e = 0;
    ans = cost = 0;
}
void add(int u, int v, int cap, int cost)
{
    edge[e].v = v;
    edge[e].cap = cap;
    edge[e].cost = cost;
    edge[e].re = e + 1;
    edge[e].next = head[u];
    head[u] = e++;
    edge[e].v = u;
    edge[e].cap = 0;
    edge[e].cost = -cost;
    edge[e].re = e - 1;
    edge[e].next = head[v];
    head[v] = e++;
}
int aug(int u, int f)
{
    if(u == des)
    {
        ans += cost * f;
        return f;
    }
    vis[u] = 1;
    int tmp = f;
    for(int i = head[u]; i != -1; i = edge[i].next)
        if(edge[i].cap && !edge[i].cost && !vis[edge[i].v])
        {
            int delta = aug(edge[i].v, tmp < edge[i].cap ? tmp : edge[i].cap);
            edge[i].cap -= delta;
            edge[edge[i].re].cap += delta;
            tmp -= delta;
            if(!tmp) return f;
        }
    return f - tmp;
}
bool modlabel()
{
    for(int i = 0; i <= n; i++) d[i] = INF;
    d[des] = 0;
    deque<int>Q;
    Q.push_back(des);
    while(!Q.empty())
    {
        int u = Q.front(), tmp;
        Q.pop_front();
        for(int i = head[u]; i != -1; i = edge[i].next)
            if(edge[edge[i].re].cap && (tmp = d[u] - edge[i].cost) < d[edge[i].v])
                (d[edge[i].v] = tmp) <= d[Q.empty() ? src : Q.front()] ? Q.push_front(edge[i].v) : Q.push_back(edge[i].v);
    }
    for(int u = 1; u <= n; u++)
        for(int i = head[u]; i != -1; i = edge[i].next)
            edge[i].cost += d[edge[i].v] - d[u];
    cost += d[src];
    return d[src] < INF;
}
void costflow()
{
    while(modlabel())
    {
        do
        {
            memset(vis, 0, sizeof(vis));
        }while(aug(src, INF));
    }
}
int nt, m;
struct point
{
    int x, y;
}p[MAXN], h[MAXN];
int dis[MAXN][MAXN];
char s[MAXN][MAXN];
int main()
{
    while(scanf("%d%d", &m, &nt) != EOF)
    {
        if(m == 0 && nt == 0) break;
        for(int i = 0; i < m; i++)
            scanf("%s", s[i]);
        int hcnt = 0, pcnt = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < nt; j++)
            {
                if(s[i][j] == 'H')
                {
                    hcnt++;
                    h[hcnt].x = i;
                    h[hcnt].y = j;
                }
                else if(s[i][j] == 'm')
                {
                    pcnt++;
                    p[pcnt].x = i;
                    p[pcnt].y = j;
                }
            }
        for(int i = 1; i <= pcnt; i++)
            for(int j = 1; j <= hcnt; j++)
                dis[i][j] = abs(p[i].x - h[j].x) + abs(p[i].y - h[j].y);
        init();
        n = hcnt + pcnt + 2;
        src = hcnt + pcnt + 1;
        des = n;
        for(int i = 1; i <= pcnt; i++)
            for(int j = 1; j <= hcnt; j++)
                add(i, j + pcnt, 1, dis[i][j]);
        for(int i = 1; i <= pcnt; i++)
            add(src, i, 1, 0);
        for(int i = 1; i <= hcnt; i++)
            add(i + pcnt, des, 1, 0);
        costflow();
        printf("%d\n", ans);
    }
    return 0;
}