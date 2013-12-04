#include <cstdio>
#include <cmath>
int s[4]={0,1,0,-1},t[4]={1,0,-1,0};
struct ffff
{
	int p;
	int a[4][4];
}x[50000];
char ss[4][5];
int head,tail,vi;
bool u[100000];
bool fx(int k)
{
	int i,j,z=x[k].a[0][0];
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
		if(x[k].a[i][j]!=z)return 0;
	return 1;
}
int vis(int k)
{
	int i,j,ans=0;
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
		if(x[k].a[i][j])ans+=(int)pow(2.0,4.0*i+j);
	return ans;
}
int main()
{
	for(int i=0;i<4;i++)
		scanf("%s",ss[i]);
	x[0].p=0;
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
		x[0].a[i][j]=(ss[i][j]=='w'?1:0);
	if(fx(0))
	{
		printf("0\n");
		return 0;
	}
	vi=vis(0);
	u[vi]=1;
	while (head<=tail)
	{
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			tail++;
			for(int k=0;k<4;k++)
			for(int l=0;l<4;l++)
				x[tail].a[k][l]=x[head].a[k][l];
			x[tail].a[i][j]=1-x[tail].a[i][j];
			for(int k=0;k<4;k++)
				if(i+s[k]>=0 && i+s[k]<4 && j+t[k]>=0 && j+t[k]<4)
					x[tail].a[i+s[k]][j+t[k]]=1-x[tail].a[i+s[k]][j+t[k]];
			x[tail].p=x[head].p+1;
			if(fx(tail))
			{
				printf("%d\n",x[tail].p);
				return 0;
			}
			vi=vis(tail);
			if(! u[vi])u[vi]=1;
			else tail--;
		}
		head++;
	}
	printf("Impossible\n");
	
	return 0;
}