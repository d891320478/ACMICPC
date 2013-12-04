#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
#include<vector>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 40
#define MM 10010
int fastget()
{
	char c; int ans=0; c=getchar();
	while (! (c>='0' && c<='9')) c=getchar();
	while (c>='0' && c<='9')
	{
		ans=(ans<<3)+(ans<<1)+c-'0';
		c=getchar();
	}
	return ans;
}
void fastput(int x)
{
	char s[12]; int a=0;
	if(x==0) puts("0");
	else
	{
		while (x) { s[a++]=x%10+'0'; x/=10; }
		for(a--;a>=0;a--) putchar(s[a]);
		putchar('\n');
	}
}
int a[NN][NN],x[NN],vis[NN];
int guass(int a[][NN],int n,int m)
{
	int i,j,k,r;
	for(i=r=1;i<m;i++)
	{
		for(j=r;j<=n && ! a[j][i];j++);
		if(j>n) continue;
		if(j>r) for(k=1;k<=m;k++) swap(a[r][k],a[j][k]);
		for(j=1;j<=n;j++) if(j!=r && a[j][i])
		for(k=i;k<=m;k++) if(a[r][k]) a[j][k]^=1;
		++r;
	}
	return r-1;//rank
}
int main()
{
	int tt=fastget();
	for(int cs=1;cs<=tt;cs++)
	{
		SET(a,0);
		for(int i=1;i<=5;i++)
		for(int j=1;j<=6;j++)
		{
			a[j+(i-1)*6][31]=fastget();
			a[j+(i-1)*6][j+(i-1)*6]=1;
			if(j>1) a[j+(i-1)*6][j+(i-1)*6-1]=1;
			if(j<6) a[j+(i-1)*6][j+(i-1)*6+1]=1;
			if(i>1) a[j+(i-1)*6][j+(i-1)*6-6]=1;
			if(i<5) a[j+(i-1)*6][j+(i-1)*6+6]=1;
		}
		int rank=guass(a,30,31);
		if(rank==30)
		{
			for(int i=30;i;i--)
			{
				x[i]=a[i][31];
				for(int j=i+1;j<=30;j++)
					x[i]^=(x[j] && a[i][j]);
			}
		}
		else
		{
			SET(vis,0);
			for(int i=1;i<=30;i++)
			for(static int j=1;j<=30;j++)
				if(a[i][j])
				{
					vis[j]=i;
					break;
				}
			for(int j=30;j;j--)
			if(! vis[j])
			{
				x[j]=a[vis[j]][31];
				for(int k=j+1;k<=30;k++) x[j]^=(a[vis[j]][k] && x[k]);
			}
		}
		printf("PUZZLE #%d\n",cs);
		for(int i=1;i<=30;i++)
		{
			printf("%d",x[i]);
			if(i%6) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}