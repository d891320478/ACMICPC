#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define maxn 30
#define maxm 1000
long id[maxm],eu[maxm],ev[maxm],ew[maxm],n,m,pnt[maxn];
int cmp(const long &i,const long &j){return ew[i]>ew[j];}
long find(long x){if(x!=pnt[x])pnt[x]=find(pnt[x]);return pnt[x];}
int kruskal()
{
    long i,j=-1,p,x,y,value=0;
    for(i=0;i<m;i++) 	id[i]=i;
    sort(id,id+m,cmp);
    for(i=0;i<n;i++)	pnt[i]=i;
    for(i=1;i<n;i++)
    {
        while(1)
        {
			p=id[++j];   if(j>=m)return 0;
			x=find(eu[p]);   y=find(ev[p]);	if(x!=y)break;
        }
        value+=ew[p];		pnt[y]=x;
    }
    cout<<value<<endl;
    return 1;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d%d",&eu[i],&ev[i],&ew[i]);
	kruskal();
	
	return 0;
}