#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;

int a[600][110],b[110],c[110];
char s1[110],s2[110];

int bj(int *x,int *y)
{
	if(x[0]>y[0])return 1;
	if(x[0]<y[0])return -1;
	for(int i=x[0];i>=1;i--)
	{
		if(x[i]>y[i])return 1;
		if(x[i]<y[i])return -1;
	}
	return 0;
}

int main ()
{
	a[0][0]=a[1][1]=a[1][0]=a[2][0]=1;
	a[2][1]=2;
	for(int i=3;i<=500;i++)
	{
		int k=a[i-1][0]>a[i-2][0]?a[i-1][0]:a[i-2][0];
		for(int j=1;j<=k;j++)
		{
			a[i][j]+=a[i-1][j]+a[i-2][j];
			a[i][j+1]=a[i][j]/10;
			a[i][j]%=10;
		}
		if(a[i][k+1]>0)k++;
		a[i][0]=k;
	}
	while (scanf("%s %s",s1,s2))
	{
		if(strcmp(s1,"0")==0 && strcmp(s2,"0")==0)break;
		b[0]=strlen(s1); c[0]=strlen(s2);
		for(int i=0;s1[i];i++) b[b[0]-i]=s1[i]-'0';
		for(int i=0;s2[i];i++) c[c[0]-i]=s2[i]-'0';

		int i,j,q1,q2;

		for(i=0;bj(b,a[i])>=0;i++);i--;
		for(j=0;bj(c,a[j])>=0;j++);j--;
		q1=bj(b,a[i]); q2=bj(c,a[j]);
		if(q1==0 && q2==0)printf("%d\n",j-i+1);
		else if(q1!=0 && q2!=0)	printf("%d\n",j-i);
			else if(q1==0)printf("%d\n",j-i+1);
				else printf("%d\n",j-i);
	}
	
	return 0;
}
