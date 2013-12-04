#include <iostream>
#include <cstring>
#define maxn 10001
#define maxh 16
using namespace std;
int n,h,root;
int pnt[maxn][maxh],son[maxn],next[maxn],depth[maxn];
int stack[maxn],mylog[maxn];
int GetParent(int x,int len)
{
	while (len>0)
	{
		x=pnt[x][mylog[len]];
		len-=1<<mylog[len];
	}
	return x;
}
int LCA(int x,int y)
{
	int nx,ny,px,py,low=0,mid,high=depth[x]<depth[y]?depth[x]:depth[y];
	px=GetParent(x,depth[x]-high);
	py=GetParent(y,depth[y]-high);
	if(px==py)return px;
	while (high-low>1)
	{
		mid=mylog[high-low-1];
		nx=pnt[px][mid];
		ny=pnt[py][mid];
		mid=high-1<<mid;
		if(nx==ny)low=mid;
		else high=mid,px=nx,py=ny;
	}
	return pnt[px][mylog[high-low]];
}
void dfs(int d,int cur)
{
	int i,j;
	stack[d]=cur;	depth[cur]=d;
	for(j=1,i=2;i<=d;j++,i*=2)pnt[cur][j]=stack[d-i];
	for(j=son[cur];j;j=next[j])dfs(d+1,j);
}
int main ()
{
	int i,j,k,l,t;
	for(i=0,j=1;j<maxn;i++)
	{
		k=j*2>maxn?maxn:j*2;
		while(j<k)mylog[j++]=i;
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(son,0,sizeof(son));
		memset(next,0,sizeof(next));
		memset(pnt,0,sizeof(pnt));
		for(i=1;i<n;i++)
		{
			cin>>k>>j;
			pnt[j][0]=k;
			next[j]=son[k];
			son[k]=j;
		}
		for(i=1;i<=n;i++)if(! pnt[i][0]){root=i;break;}
		dfs(0,root);
		//for(cin>>k;k;k--)
		//{
			cin>>i>>j;
			cout<<LCA(i,j)<<endl;
		//}
	}
	return 0;
}