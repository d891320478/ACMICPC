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
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 1000010
#define M 10010
int next[N],i,j,l;
char s[N];
int main()
{
	while (gets(s) && s[0]!='.')
	{
		j=next[0]=-1;
		l=strlen(s);
		for(i=1;i<l;i++)
		{
			while (j>-1 && s[j+1]!=s[i]) j=next[j];
			if(s[j+1]==s[i]) j++;
			next[i]=j;
		}
		printf("%d\n",(l%(l-next[l-1]-1) || next[l]==-1)?1:l/(l-next[l-1]-1));
	}
	return 0;
}