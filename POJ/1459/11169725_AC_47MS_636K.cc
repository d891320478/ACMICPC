#include <cstdio>
#include <cstring>
#define MXN 255
using namespace std;
 
const int inf=0x77777777;
int d[MXN+5],c[MXN+5][MXN+5],cnt[MXN+5];
int n,s,t,m;
 
#define min(A,B) ((A)<(B)?(A):(B))
unsigned int aug(int u,unsigned int res) {
  if (u==t) return res;
  int fnd=false;unsigned int del,r=res;
  for (int v=1;v<=n;++v)
    if (d[u]==d[v]+1 && c[u][v]>0) {
      fnd=true;
      del=aug(v,min(r,c[u][v]));
      c[u][v]-=del,c[v][u]+=del,r-=del;
      if (d[s]>=n || r<=0) return (res-r);
    }
  if (!fnd) {
    int mind=n;
    for (int v=1;v<=n;++v)
      if (c[u][v]>0 && d[v]+1<mind) mind=d[v]+1;
    if (!--cnt[d[u]]) d[s]=n; else ++cnt[(d[u]=mind)];
  }
  return (res-r);
}
 
inline unsigned int sap() {
  memset(d,0,sizeof d);
  memset(cnt,0,sizeof cnt);
  unsigned int ret=0;
  for (cnt[0]=n;d[s]<n;ret+=aug(s,inf)) ;
  return ret;
}
 int main ()
{
	int n1,n2;
	while (scanf("%d%d%d%d",&n,&n1,&n2,&m)!=-1)
	{
		memset(c,0,sizeof c);
    	s=n+1;t=n+2;
		while (m--)
		{
			int u,v,w;
			scanf(" (%d,%d)%d",&u,&v,&w);
			u++,v++;
			c[u][v]+=w;
		}
		while (n1--)
		{
			int u,w;
			scanf(" (%d)%d",&u,&w);
			u++;
			c[s][u]+=w;
		}
		while (n2--)
		{
			int u,w;
			scanf(" (%d)%d",&u,&w);
			u++;
			c[u][t]+=w;
		}
		n+=2;
		printf("%d\n",sap());
	}
	
	return 0;
}