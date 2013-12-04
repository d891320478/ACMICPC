#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int a[210][210],n,i,j,k,l;
string s;
int flag=0;
int main ()
{
	
	while (scanf("%d",&n) && n)
	{
		if(flag)printf("\n");
		else flag=1;
		memset(a,0,sizeof(a));
		int u,v;
		while (cin>>u>>v)
		{
			if(u==0 && v==0)break;
			cin>>s;
			for(i=0;i<s.size();i++)
				a[u][v]+=1<<(s[i]-'a'+1);
		}
		for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			a[i][j]=a[i][j] | (a[i][k] & a[k][j]);
		while (cin>>u>>v)
		{
			int tmp=0;
			if(u==0 && v==0)break;
			for(l=1;l<=26;l++)
				if(a[u][v] & 1<<l){printf("%c",'a'+l-1);tmp=1;}
			if(tmp)printf("\n");
		}
		printf("-\n");
	}
	
	return 0;
}