#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define maxn 110
#define maxm 10010
int id[maxm],eu[maxm],ev[maxm],ew[maxm],n,m,pnt[maxn];
int value,ans[maxn];
int cmp(const int &i,const int &j){return ew[i]<ew[j];}
int find(int x){if(x!=pnt[x])pnt[x]=find(pnt[x]);return pnt[x];}
int kruskal0()
{
    int i,j=-1,p,x,y;
    for(i=1;i<=n;i++)	pnt[i]=i;
    for(i=1;i<n;i++)
    {
        while(1)
        {
	p=id[++j];            if(j>=m)return 0;            x=find(eu[p]);            y=find(ev[p]);
	if(x!=y)break;
        }
        value+=ew[p];		pnt[y]=x;
        ans[++ans[0]]=p;
    }
    return 1;
}
int kruskal(int z)
{
    int i,j=-1,p,x,y,value1=0;
    for(i=1;i<=n;i++)	pnt[i]=i;
    for(i=1;i<n;i++)
    {
        while(1)
        {
	p=id[++j];    if(p==z)continue;        if(j>=m)return 0;            x=find(eu[p]);            y=find(ev[p]);
	if(x!=y)break;
        }
        value1+=ew[p];		pnt[y]=x;
    }
    if(value1==value)return -1;
    return 1;
}
int main ()
{
	int tt,i;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&eu[i],&ev[i],&ew[i]);
			id[i]=i;
		}
		sort(id,id+m,cmp);
		ans[0]=value=0;
		kruskal0();
		for(i=1;i<=ans[0];i++)
			if(kruskal(ans[i])==-1)break;
		if(i>ans[0])printf("%d\n",value);
		else printf("Not Unique!\n");
	}
	
	return 0;
}