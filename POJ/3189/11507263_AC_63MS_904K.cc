#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define pause cout << " press ansy key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-x))
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
#define repd(i, n) for (int i = (n - 1); i >= 0; i--)
#define FOR(i, n, m) for (int i = (n); i <= (m); i++)
#define FORD(i, n, m) for (int i = (n); i >= (m); i--)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define SZ(c) (c).size()
#define ALL(c) (c).begin(), (c).end()

using namespace std;
int chh;

typedef long long LL;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;

const int N = 50, M = N * N * 2, INF = ~0U >> 2;

int e, s, t, NN;
int head[N], pre[N], cur[N], dis[N], gap[N];
int pnt[M], wv[M], nxt[M];

void add_edge(int u, int v, int w) {
    pnt[e] = v, wv[e] = w, nxt[e] = head[u], head[u] = e++;
    pnt[e] = u, wv[e] = 0, nxt[e] = head[v], head[v] = e++;
}

int sap() {
    int i, flow = 0, aug = INF, u, v;
    bool flag;
    for (i = 0; i <= NN; i++) {
        cur[i] = head[i];
        gap[i] = dis[i] = 0;
    }
    gap[0] = NN;
    u = pre[s] = s;
    while (dis[s] < NN) {
        flag = 0;
        for (int &j = cur[u]; j != -1; j = nxt[j]) {
            v = pnt[j];
            if (wv[j] > 0 && dis[u] == dis[v] + 1) {
                flag = 1;
                if (wv[j] < aug) aug = wv[j];
                pre[v] = u;
                u = v;
                if (u == t) {
                    flow += aug;
                    while (u != s) {
                        u = pre[u];
                        wv[cur[u]] -= aug;
                        wv[cur[u] ^ 1] += aug;
                    }
                    aug = INF;
                }
                break;
            }
        }
        if (flag) continue;
        int mindis = NN;
        for (int j = head[u]; j != -1; j = nxt[j]) {
            v = pnt[j];
            if (wv[j] > 0 && dis[v] < mindis) {
                mindis = dis[v];
                cur[u] = j;
            }
        }
        if ((--gap[dis[u]]) == 0) break;
        gap[dis[u] = mindis + 1]++;
        u = pre[u];
    }
    return flow;
}

void init(int src, int dst, int num) {
    e = 0, s = src, t = dst, NN = num;
    memset(head, -1, sizeof(head));
}

const int XN = 1005, XM = 25;

int n, m;
int g[XN][XM], st[XM], vis[XN][XM], h[XN];

bool judge(int x) {
    int tol, tmp;
    int gg[XM];
    FOR (k, 1, m - x) {
        init(0, m * 2 + 1, m * 2 + 2);
        memset(vis, 0, sizeof(vis));
        memset(h, 0, sizeof(h));
        FOR (i, 1, n) FOR (j, k, k + x) vis[i][g[i][j]] = 1;
        FOR (j, 1, m) {
            add_edge(j, j + m, INF);
            tol = 0;
            memset(gg, 0, sizeof(gg));
            FOR (i, 1, n) {
                if (h[i]) continue;
                if (vis[i][j]) {
                    tol++, h[i] = 1;
                    FOR (ii, j + 1, m) gg[ii] += vis[i][ii];
                }
            }
            FOR (i, j + 1, m) add_edge(j, i + m, gg[i]);
            if (tol != 0) {
                //if (x == 1 && k == 1) cout << "s= " << s << " " << j << " " << tol, pause;
                add_edge(s, j, tol);
            }
        }
        FOR (i, 1, m) add_edge(i + m, t, st[i]);
        //if (x == 1 && k == 1) cout << "FFF= " << sap(), pause;
        if (sap() == n) return 1;
    }
    return 0;
}

int main() {
    int l, r, mid;
    while (~scanf("%d %d", &n, &m)) {
        FOR (i, 1, n) FOR (j, 1, m) scanf("%d", &g[i][j]);
        FOR (i, 1, m) scanf("%d", &st[i]);
//        l = 0, r = m - 1;
//        while (l != r) {
//            mid = (l + r) >> 1;
//            if (judge(mid)) r = mid;
//            else l = mid + 1;
//        }
        FOR (i, 0, m - 1) {
            if (judge(i)) {
                l = i;
                break;
            }
        }
        printf("%d\n", l+1);
    }
    return 0;
}