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
#define ABS(x) (x)>=0?(x):-(x)
#define N 10010
#define M 10010
char s1[N],s2[N];
int ans;
void kmp(char *s1,char *s2)
{
	int ls1,ls2,i,j, p[100]={-1};

	ls1=strlen(s1);    ls2=strlen(s2);    j=-1;
    for(i=1;i<ls2;i++)
    {
        while(j>-1 && s2[j+1]!=s2[i])j=p[j];
        if(s2[j+1]==s2[i])j++;
        p[i]=j;
    }
    j=-1;
    for(i=0;i<ls1;i++)
    {
        while(j>-1 && s2[j+1]!=s1[i])j=p[j];
        if(s2[j+1]==s1[i])j++;
        if(j==ls2-1)
        {
            ans++;
            j=p[j];
        }
    }
}
int main ()
{
	int ttt;
	scanf("%d",&ttt);
	while (ttt--)
	{
		scanf("%s%s",s2,s1);
		ans=0;
		kmp(s1,s2);
		printf("%d\n",ans);
	}
	
	return 0;
}