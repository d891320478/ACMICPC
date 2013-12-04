#include <cstdio>
#include <iostream>
using namespace std;
#define SIZE 50010
#define lowbit(x)	(x&-x)
const int inf = 0x3f3f3f3f;

int rmq[SIZE+10];				//原始序列
struct TreeArr {
	int n;
	int L[SIZE+10], R[SIZE+10];	//向左、向右管辖区间的最大值
	void init(int n) {			//关注这种O(n)初始化方式！！！！！
		this->n = n;
		int i, y, k; 
		for(i = 1; i <= n; i ++) {
			y = lowbit(i);
			L[i] = rmq[i];
			for(k=1; k<y && i-k>0; k<<=1)	L[i] = max(L[i], L[i-k]);
		}
		for(i = n; i >= 1; i --) {
			y = lowbit(i);
			R[i] = rmq[i];
			for(k=1; k<y && i+k<=n;k<<=1)	R[i] = max(R[i], R[i+k]);
		}
	}
	//返回最大值，不是返回下标！！！！
	int query(int a, int b) {
		if(a>b)	return -inf;
		int res = -inf;
		for(; b-lowbit(b)>=a; b-=lowbit(b))	res = max(res, L[b]);
		for(; a<b; a += lowbit(a))			res = max(res, R[a]);
		res = max(res, rmq[a]);
		return res;
	}
} ta;
struct TreeArr1 {
	int n;
	int L[SIZE+10], R[SIZE+10];	//向左、向右管辖区间的最大值
	void init(int n) {			//关注这种O(n)初始化方式！！！！！
		this->n = n;
		int i, y, k; 
		for(i = 1; i <= n; i ++) {
			y = lowbit(i);
			L[i] = rmq[i];
			for(k=1; k<y && i-k>0; k<<=1)	L[i] = min(L[i], L[i-k]);
		}
		for(i = n; i >= 1; i --) {
			y = lowbit(i);
			R[i] = rmq[i];
			for(k=1; k<y && i+k<=n;k<<=1)	R[i] = min(R[i], R[i+k]);
		}
	}
	//返回最大值，不是返回下标！！！！
	int query(int a, int b) {
		if(a>b)	return -inf;
		int res = inf;
		for(; b-lowbit(b)>=a; b-=lowbit(b))	res = min(res, L[b]);
		for(; a<b; a += lowbit(a))			res = min(res, R[a]);
		res = min(res, rmq[a]);
		return res;
	}
} ta1;
int main ()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&rmq[i]);
	ta.init(n); ta1.init(n);
	while (m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",ta.query(l,r)-ta1.query(l,r));
	}
	return 0;
}