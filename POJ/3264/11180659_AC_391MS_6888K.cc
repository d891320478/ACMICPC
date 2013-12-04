#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define SET(a,b) memset(a,b,sizeof(a))
#define N 50010
#define M 21
int n,m,val[N],mx[M][N],mn[M][N],p[M],idx[N];
int l,r,t,ans,lc;
int i,a,j;
char c,ch[20];
void init()
{
	idx[0]=-1;
	for(i=1;i<N;i++)
		idx[i]=idx[i-1]+(!(i&(i-1)));
	for(i=0;i<M;i++)
		p[i]=1<<i;
}
void rmq()
{
	for(i=1;i<=n;i++)
		mx[0][i]=mn[0][i]=val[i];
	for(i=1;p[i]<=n;i++)
	for(j=1;j+p[i]-1<=n;j++)
	{
		mx[i][j]=mx[i-1][j]>mx[i-1][j+p[i-1]]?mx[i-1][j]:mx[i-1][j+p[i-1]];
		mn[i][j]=mn[i-1][j]<mn[i-1][j+p[i-1]]?mn[i-1][j]:mn[i-1][j+p[i-1]];
	}
}
int fastget()
{
	a=0;
	while (c=getchar()) if(c>='0' && c<='9') break;
	a=c-'0';
	while (c=getchar())
		if(c>='0' && c<='9') a=a*10+c-'0';
		else break;
	return a;
}
int main()
{
	n=fastget();
	m=fastget();
	for(i=1;i<=n;i++) val[i]=fastget();
	init();
	rmq();
	while (m--)
	{
		l=fastget();
		r=fastget();
		t=idx[r-l+1];
		ans=max(mx[t][l],mx[t][r-p[t]+1])-min(mn[t][l],mn[t][r-p[t]+1]);
		lc=0;
		while (ans)
		{
			ch[lc++]=ans%10+'0';
			ans/=10;
		}
		for(i=lc-1;i>=0;i--) putchar(ch[i]);
		if(! lc) putchar('0');
		putchar('\n');
	}
	return 0;
}