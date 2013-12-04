#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
int n;
int a[N];
int ins[N];
stack <int> st;
int flag;
int main()
{
	int now,i;
	while (scanf("%d",&n) && n)
	{
		if(! flag) flag=1;
		else printf("\n");
		while(scanf("%d",&a[1]) && a[1])
		{
			for(i=2;i<=n;i++) scanf("%d",&a[i]);
			SET(ins,0);
			now=1;
			for(i=1;i<=n;i++)
			{
				if(! st.empty())
				{
					if(st.top()==a[i])
					{
						st.pop();
						ins[a[i]]=0;
						continue;
					}
					if(ins[a[i]]) break;
				}
				while (now<=n && now!=a[i])
				{
					ins[now]=1;
					st.push(now);
					now++;
				}
			}
			if(i<=n) printf("No\n");
			else printf("Yes\n");
		}
	}
	return 0;
}