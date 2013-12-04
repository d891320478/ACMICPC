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
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 11
#define M 65
int n;
char s[N][M],ans[M],tmp[M];
int kmp(char *s1,char *s2)
{
	int ls1,ls2,i,j,p[M]={-1};
	ls1=strlen(s1);
	ls2=strlen(s2);
	j=-1;
	for(i=1;i<ls2;i++)
	{
		while (j>-1 && s2[j+1]!=s2[i]) j=p[j];
		if(s2[j+1]==s2[i]) j++;
		p[i]=j;
	}
	j=-1;
	for(i=0;i<ls1;i++)
	{
		while(j>-1 && s1[i]!=s2[j+1]) j=p[j];
		if(s2[j+1]==s1[i]) j++;
		if(j==ls2-1) return 1;
	}
	return 0;
}
int main()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]);
		int i,j,k,l=strlen(s[1]);
		ans[0]=0;
		for(i=3;i<=l;i++)
		{
			int flag=0;
			for(j=0;i+j-1<l;j++)
			{
				for(k=0;k<i;k++)
					tmp[k]=s[1][j+k];
				tmp[i]=0;
				for(k=2;k<=n;k++)
					if(! kmp(s[k],tmp)) break;
				if(k>n)
				{
					flag=1;
					if(strlen(ans)<i || strcmp(ans,tmp)>0) strcpy(ans,tmp);
				}
			}
			if(! flag) break;
		}
		if(i==3) printf("no significant commonalities\n");
		else printf("%s\n",ans);
	}
	return 0;
}