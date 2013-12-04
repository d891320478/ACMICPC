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
int top,st[N];
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
			top=0;
			for(i=1;i<=n;i++)
			{
				if(top)
				{
					if(st[top]==a[i])
					{
						top--;
						ins[a[i]]=0;
						continue;
					}
					if(ins[a[i]]) break;
				}
				while (now<=n && now!=a[i])
				{
					ins[now]=1;
					st[++top]=now;
					now++;
				}
				now++;
			}
			if(i<=n) printf("No\n");
			else printf("Yes\n");
		}
	}
	return 0;
}