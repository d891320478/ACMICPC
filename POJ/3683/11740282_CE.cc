#include<stdio.h>
#include<algorithm>
#define max(a,b) ( a>b ? a:b )
#define min(a,b) ( a<b ? a:b )
using namespace std;

inline int rev ( int x ) { return x ^ 1 ; };

const int maxn = 2000;

int n;
int st[maxn], ed[maxn];

int mk[maxn], low[maxn], depth[maxn], choice [ maxn ];

int find( int x ) { if( x != low[x] ) return low[x] = find(low[x]); return low[x]; };

void dfs ( int u, int d = 0 ) 
{
	mk[u] = -1; depth[u] = d; low[u] = u;
	for( int v = 0; v < n; ++ v ) 
		if ( ( u >> 1 ) != ( v >> 1 ) && max( st[u], st[rev(v)] ) < min( ed[u], ed[rev(v)] ) )
		{
		if ( !mk[v] ) dfs(v, d+1);
		if( mk[low[v]] == -1 && depth[low[u]] > depth[low[v]] ) low[u] = low[v];
		}
	if( !choice[rev(u)] ) choice[u] = 1;
	if( mk[rev(u)] == -1 ) mk[u] = 2; else mk[u] = 1;
}

void solve ()
{
	int i; 
	memset( mk, 0, sizeof( mk ) );
	memset( choice, 0, sizeof( choice ) );
	for( i = 0; i < n; ++ i ) if( !mk[i] ) dfs( i );
	for( i = 0; i < n; ++ i ) if( mk[i] == 2 && depth[ find ( i ) ] < depth[ rev(i) ] ) 
	{ 
		printf("NO\n"); return ;
	} 
	printf("YES\n");
	for( i = 0; i < n; ++ i ) if( choice[i] )
		printf("%02d:%02d %02d:%02d\n", st[i]/60, st[i]%60, ed[i]/60, ed[i]%60);
}

int main ()
{
	scanf("%d", &n);
	for( int i = 0; i < n; ++ i ) 
	{
		int a, b, v;
		scanf("%d:%d", &a, &b);
		st[i*2] = a * 60 + b; 
		scanf("%d:%d", &a, &b);
		ed[i*2+1] = a * 60 + b;
		scanf("%d", &v);
		ed[i*2] = st[i*2] + v;
		st[i*2+1] = ed[i*2+1] - v;
	} 
	n *= 2;
	solve ();
	return 0;
} 