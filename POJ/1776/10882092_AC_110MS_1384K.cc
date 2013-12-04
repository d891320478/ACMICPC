#include <cstdio>
#include <cstring>
#define maxn 1010
int ms() {
	int res = 0;
	char c;
	while(c=getchar(), c>'9'||c<'0');
	for(res=c-'0'; c=getchar(),c>='0'&&c<='9'; res=res*10+c-'0');
	return res;
}

void construct(bool g[maxn][maxn], int n, int * arr) {
	static int nxt[maxn];
	memset(nxt, 255, sizeof(nxt));
	
	int head = 0;
	for(int i = 1; i < n; i ++) {
		if(g[i][head]) {
			nxt[i] = head;
			head = i;
		} else {
			int prev = head;
			int iter = nxt[head];
			while(1) {
				if(iter==-1 || g[i][iter]) {
					nxt[prev] = i;
					nxt[i] = iter;
					break;
				}
				prev = iter;
				iter = nxt[iter];
			}
		}
	}
//	printf("over1\n");
	int i = 0;
	for(int x = head; x != -1; x = nxt[x]) {
		arr[i ++] = x;
	}
}

bool g[maxn][maxn];
int n;
int arr[maxn];

int main() {
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i ++) {
			for(int j = 0; j < n; j ++) {
				g[i][j] = ms();
			}
		}
		construct(g, n, arr);
		printf("1\n%d\n", n);
		for(int i = 0; i < n; i ++) {
			printf("%d ", arr[i]+1);
		}
		printf("\n");
	}
	return 0;
}