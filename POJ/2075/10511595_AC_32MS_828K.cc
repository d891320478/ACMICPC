#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#define maxn 510
#define maxm 250010
using namespace std;
map<string,int>per;
string p1,p2;
double len;
int id[maxm],eu[maxm],ev[maxm],n,m,pnt[maxn];
double ew[maxm];
int cmp(const int &i,const int &j){return ew[i]<ew[j];}
int find(int x){if(x!=pnt[x])pnt[x]=find(pnt[x]);return pnt[x];}
int kruskal()
{
    int i,j=-1,p,x,y;
    double value=0;
    for(i=0;i<m;i++) 	id[i]=i;
    sort(id,id+m,cmp);
    for(i=0;i<n;i++)	pnt[i]=i;
    for(i=1;i<n;i++)
    {
        while(1)
        {
	p=id[++j];            if(j>=m)return 0;            x=find(eu[p]);            y=find(ev[p]);
	if(x!=y)break;
        }
        value+=ew[p];		pnt[y]=x;
    }
    if(value<=len)printf("Need %.1f miles of cable\n",value);
    else printf("Not enough cable\n");
    return 1;
}
int main ()
{
	int i;
	while (scanf("%lf",&len)!=-1)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			cin>>p1;
			per[p1]=i;
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			cin>>p1>>p2>>ew[i];
			eu[i]=per[p1];
			ev[i]=per[p2];
		}
		kruskal();
	}
	
	return 0;
}
