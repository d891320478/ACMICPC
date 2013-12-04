#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int n,a[2010][2010],d[2010],i,j,k,value;
bool vis[2010];
string s[2010];
int main ()
{
	while (scanf("%d",&n) && n)
	{
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			for(j=0;j<i;j++)
			{
				a[i][j]=0;
				for(k=0;k<s[i].size();k++)
					a[i][j]+=(s[i][k]!=s[j][k]);
				a[j][i]=a[i][j];
			}
			a[i][i]=vis[i]=0;
		}
		for(i=0;i<n;i++)
			d[i]=a[0][i];
		vis[0]=1;
		value=0;
		for(i=1;i<n;i++)
		{
			int mn=1600000000;
			for(j=0;j<n;j++)
				if(! vis[j])
				if(d[j]<mn)
				{
					mn=d[j];
					k=j;
				}
			vis[k]=1;
			value+=d[k];
			for(j=0;j<n;j++)
				if(! vis[j])
				d[j]=min(d[j],a[k][j]);
		}
		printf("The highest possible quality is 1/%d.\n",value);
	}
	
	return 0;
}