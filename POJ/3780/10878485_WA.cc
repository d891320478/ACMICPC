#include<cstdio>
#include<cstring>
#define N 1010
int g[N][N];
int n,arr[N];
void construct(int start)
{
	static int nxt[N];
	memset(nxt,-1,sizeof(nxt));
	int head=start,i;
	for(i=1;i<=n;i++)
	{
		if(i==start) continue;
		if(g[i][head])
		{
			nxt[i]=head;
			head=i;
		}
		else
		{
			int prev=head;
			int iter=nxt[head];
			while(1)
			{
				if(iter==-1 || g[i][iter])
				{
					nxt[prev]=i;
					nxt[i]=iter;
					break;
				}
				prev=iter;
				iter=nxt[iter];
			}
		}
	}
	arr[0]=0;
	for(int x=head;x!=-1;x=nxt[x]) arr[++arr[0]]=x;
}
int main()
{
	int i,j,flag;
	while (scanf("%d",&n) && n)
	{
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		flag=0;
		for(i=1;i<=n;i++)
		{
			construct(i);
			if(g[arr[n]][arr[1]])
			{
				for(j=1;j<=n;j++)
					if(arr[j]==1) break;
				for(int k=j;k<=n;k++)
				{
					printf("%d",arr[k]);
					arr[0]--;
					if(arr[0]) printf(" ");
					else printf("\n");
				}
				for(int k=1;k<j;k++)
				{
					printf("%d",arr[k]);
					arr[0]--;
					if(arr[0]) printf(" ");
					else printf("\n");
				}
				flag=1;
				break;
			}
		}
		if(! flag) printf("-1\n");
	}
}