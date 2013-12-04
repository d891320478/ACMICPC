#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 1000010
#define M 10010
char s[N];
int j,c[N],tmp,i;
int main ()
{
	int ttt=0;
	while (gets(s)!=NULL)
	{
		if(strcmp(s,"0")==0) break;
		for(i=1;i<10;i++)
		{
			tmp=i;
			c[0]=0;
			for(j=0;s[j];j++)
			{
				tmp=tmp*10+s[j]-'0';
				c[++c[0]]=tmp/11;
				tmp%=11;
			}
			if(! tmp) break;
		}
		if(i>=10) printf("%d. IMPOSSIBLE\n",++ttt);
		else
		{
			printf("%d. ",++ttt);
			for(i=1;i<=c[0];i++) printf("%d",c[i]);
			printf("\n");
		}
	}
	
	return 0;
}