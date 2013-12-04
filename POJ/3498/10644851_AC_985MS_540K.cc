#include<stdio.h>
#include <cstring>
int f[210][210],h[210],vh[210];	int m,n,ans;	int s,t;
int min(int x,int y)
{	if (x<y) return x;		else return y;	}
int dfs(int n,int v,int flow)
{
	int i,j,k,minh;
	if (v==t) return flow;
	minh=n;	k=0;
	for (i=1;i<=n;i++)
	if (f[v][i]>0)
	{
		if (h[v]==h[i]+1) {k=dfs(n,i,min(flow,f[v][i]));}
		if (h[s]>n) return 0;
		if (k>0)	{	f[v][i]-=k;	f[i][v]+=k;		return k;		} 
		minh=min(minh,h[i]);
	}
	vh[h[v]]--;	if (vh[h[v]]==0) h[s]=n+1;
	h[v]=minh+1;	vh[h[v]]++;
	return 0;
}
struct point
{
	double x,y;
	int cr,jmp;
}p[110];
bool g[110][110];
double dis(point a,point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main()
{
	//freopen("1.in","r",stdin);
	int i,j,k,ttt,sum;
	double D;
	int ns[210];
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d%lf",&n,&D);
		memset(g,0,sizeof(g));
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf%d%d",&p[i].x,&p[i].y,&p[i].cr,&p[i].jmp);
			for(j=1;j<i;j++)
				if(dis(p[i],p[j])<=D*D)g[i][j]=g[j][i]=1;
			sum+=p[i].cr;
		}
		s=2*n+1;
		t=s+1;
		ns[0]=0;
		for(i=1;i<=n;i++)
		{
			memset(f,0,sizeof(f));
			for(j=1;j<=n;j++)
			{
				f[s][j]=p[j].cr;
				if(j!=i) f[j][j+n]=p[j].jmp;
				for(k=1;k<=n;k++)
					if(g[j][k]) f[j+n][k]=100000000;
			}
			f[i][i+n]=f[i+n][t]=100000000;
			memset(vh,0,sizeof(vh));
			memset(h,0,sizeof(h));
			vh[0]=n+n+2;
			ans=0;
			while (h[s]<=n+n+2) ans=ans+dfs(n+n+2,s,2000000000);
			if(ans>=sum)ns[++ns[0]]=i;
		}
		if(ns[0]==0)printf("-1\n");
		else
		{
			for(i=1;i<=ns[0];i++)
			{
				printf("%d",ns[i]-1);
				if(i==ns[0]) printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}