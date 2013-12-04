#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 10010
#define M 1000010
int d[N],a[N],head[N],next[M],e[M],l[M];
int i,j,top,k,ans,n,tail;
bool vis[N];
queue<int>q;
int main()
{
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		scanf("%d",&j);
		while (j--)
		{
			scanf("%d",&k);
			next[top]=head[k];
			e[top]=i;
			l[top]=a[k];
			head[k]=top++;
		}
	}
	q.push(1);
	vis[1]=1;
	while(! q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(i=head[x];i!=-1;i=next[i])
		if(d[e[i]]<d[x]+l[i])
		{
			d[e[i]]=d[x]+l[i];
			if(! vis[e[i]])
			{
				q.push(e[i]);
				vis[e[i]]=1;
			}
		}
	}
	for(i=1;i<=n;i++)
		ans=ans>d[i]+a[i]?ans:d[i]+a[i];
	printf("%d\n",ans);
	return 0;
}