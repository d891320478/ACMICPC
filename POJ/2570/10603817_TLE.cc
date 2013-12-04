#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int a[210][210],n,i,j,k,l;
char s[30];
int flag=0;
int main ()
{

	while (scanf("%d",&n) && n)
	{
		if(flag)printf("\n");
		else flag=1;
		memset(a,0,sizeof(a));
		int u,v;
		while (scanf("%d%d",&u,&v))
		{
			if(u==0 && v==0)break;
			scanf("%s",s);
			for(i=0;s[i];i++)
				a[u][v]+=1<<(s[i]-'a'+1);
		}
		for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			a[i][j]=a[i][j] | (a[i][k] & a[k][j]);
		while (scanf("%d%d",&u,&v))
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