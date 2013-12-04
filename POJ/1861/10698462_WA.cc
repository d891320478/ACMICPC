#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define maxn 1010
#define maxm 20010
long id[maxm],eu[maxm],ev[maxm],ew[maxm],n,m,pnt[maxn];
int cmp(const long &i,const long &j){return (ew[i]<ew[j]) || (ew[i]==ew[j] && i<j);}
long find(long x){if(x!=pnt[x])pnt[x]=find(pnt[x]);return pnt[x];}
int kruskal()
{
    long i,j=-1,p,x,y,value=0,q;
    int e[maxn][2];
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
        if(ew[p]>value)
        {
        	value=ew[p];
        	q=p;
        }
        e[i][0]=eu[p];
        e[i][1]=ev[p];
        pnt[y]=x;
    }
    cout<<q+1<<endl<<n-1<<endl;
    for(i=1;i<n;i++)
    	cout<<e[i][0]<<' '<<e[i][1]<<endl;
    return 1;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d%d",&eu[i],&ev[i],&ew[i]);
	if(! kruskal())printf("-1\n");
	
	return 0;
}