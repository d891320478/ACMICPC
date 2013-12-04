#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define ABS(x) ((x>0)?(x):(-(x)))
#define N 303
int id(char *s)
{
	if(strcmp(s,"MON")==0) return 1;
	if(strcmp(s,"TUE")==0) return 2;
	if(strcmp(s,"WED")==0) return 3;
	if(strcmp(s,"THU")==0) return 4;
	if(strcmp(s,"FRI")==0) return 5;
	if(strcmp(s,"SAT")==0) return 6;
	if(strcmp(s,"SUN")==0) return 7;
}
int print(int a[][N],int m,int n)
{
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
int n,m,a[N][N],b[N];
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int yf(int *a,int n)
{
	int i,j=0,k=0;
	for(i=1;i<=n;i++)
		if(b[i]) if(j) k=gcd(k,ABS(b[i])); else k=ABS(b[i]),j=1;
	if(k) for(i=1;i<=n;i++) b[i]/=k;
}
int guass(int a[][N],int n,int m)
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
				a[j][k]=(a[j][k]*t2-a[r][k]*t1)%7;
			//yf(a[j],m);
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
void findans(int a[][N],int n,int m)
{
	int i,j;
	for(i=n;i>0;i--)
	{
		int x=(a[i][i]%7+7)%7,y=a[i][m];
		for(j=i+1;j<m;j++)
			y=(y-a[i][j]*b[j])%7;
		y=(y+7)%7;
		if(y==0) b[i]=0;
		else
		for(j=0;j<7;j++)
			if(x*j%7==y)
			{
				b[i]=j;
				break;
			}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]<3) b[i]+=7;
		printf("%d",b[i]);
		if(i<n) printf(" ");
		else printf("\n");
	}
}
int main ()
{
	while (scanf("%d %d",&n,&m) && n+m)
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=m;i++)
		{
			int p;
			char s[5],t[5];
			scanf("%d %s %s",&p,s,t);
			a[i][n+1]=id(t)-id(s)+1;
			while (p--)
			{
				int k;
				scanf("%d",&k);
				a[i][k]++;
			}
			for(int j=1;j<=n+1;j++) a[i][j]%=7;
		}
		int rank=guass(a,m,n+1);
		if(rank==-1) puts("Inconsistent data.");
		else if(rank<n) puts("Multiple solutions.");
		else findans(a,n,n+1);
	}
	return 0;
}