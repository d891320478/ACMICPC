#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int a[27][210][210],n,i,j,k,l;
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
				a[s[i]-'a'][u][v]=1;
		}
		for(l=0;l<26;l++)
		for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			a[l][i][j]=(a[l][i][j]) || (a[l][i][k] && a[l][k][j]);
		while (cin>>u>>v)
		{
			int tmp=0;
			if(u==0 && v==0)break;
			for(l=0;l<26;l++)
				if(a[l][u][v]){printf("%c",'a'+l);tmp=1;}
			if(tmp)printf("\n");
		}
		printf("-\n");
	}
	
	return 0;
}