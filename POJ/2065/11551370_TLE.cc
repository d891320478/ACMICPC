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
#define NN 80
int fastget()
{
	char c; int ans=0; c=getchar();
	int sign=1;
	while (! (c>='0' && c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while (c>='0' && c<='9')
	{
		ans=(ans<<3)+(ans<<1)+c-'0';
		c=getchar();
	}
	return ans*sign;
}
void fastput(int x)
{
	char s[12]; int a=0;
	if(x==0) puts("0");
	else
	{
		if(x<0) putchar('-'),x=-x;
		while (x) { s[a++]=x%10+'0'; x/=10; }
		for(a--;a>=0;a--) putchar(s[a]);
		putchar('\n');
	}
}
char s[NN];
int a[NN][NN],b[NN],p;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int guass(int a[][NN],int n,int m)
{
	int i,j,k,r,t1,t2,d;
	for(i=r=1;i<m;i++)
	{
		for(j=r;j<=n && ! a[j][i];j++);
		if(j>n) continue;
		if(j>r) for(k=1;k<=m;k++) swap(a[r][k],a[j][k]);
		for(j=1;j<=n;j++)
		if(j!=r && a[j][i])
		{
			d=gcd(ABS(a[r][i]),ABS(a[j][i]));
			t1=a[j][i]/d;
			t2=a[r][i]/d;
			for(k=1;k<=m;k++)
				a[j][k]=(a[j][k]*t2-a[r][k]*t1)%p;
		}
		r++;
	}
	for(i=n;i>0;i--)
	if(a[i][m])
	{
		for(j=1;j<m && !a[i][j];j++);
		if(j==m) return -1;
	}
	return r-1;
}
int exteuclid(int a,int b,int &x,int &y)
{
    int tmp,d;
    if(b==0) {   x=1;  y=0; return a;    }
    d=exteuclid(b,a%b,x,y);
    tmp=x;    x=y;    y=tmp-a/b*y;
    return d;
}
void findans(int a[][NN],int n,int m)
{
	for(int i=n;i>0;i--)
	{
		int x=a[i][m],y=(a[i][i]%p+p)%p;
		int c,d;
		for(int j=i+1;j<m;j++)
			x-=b[j]*a[i][j];
		x=(x%p+p)%p;
		if(! x)
		{
			b[i]=0;
			continue;
		}
		int gd=exteuclid(y,p,c,d);
		b[i]=c*x/gd;
		b[i]=(b[i]%p+p)%p;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d",b[i]);
		if(i<n) printf(" ");
		else printf("\n");
	}
}
int main()
{
freopen("1.in","r",stdin);
	int tt=fastget();
	while (tt--)
	{
		p=fastget();
		scanf("%s",s);
		int n=strlen(s);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			a[i][n+1]=(s[i-1]=='*'?0:(s[i-1]-'a'+1))%p;
		for(int i=1;i<=n;i++)
		{
			a[i][1]=1;
			for(int j=2;j<=n;j++)
				a[i][j]=a[i][j-1]*i%p;
		}
		guass(a,n,n+1);
		findans(a,n,n+1);
	}
	return 0;
}