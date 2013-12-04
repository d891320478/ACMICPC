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
char a[10];
struct ch
{
	char x[11],y[11];
}s[110];
int ls;
bool operator < (ch a,ch b)
{
	return strcmp(a.x,b.x)<=0;
}
int main ()
{
	while (scanf("%s",s[ls].x))
	{
		if(strcmp(s[ls].x,"XXXXXX")==0) break;
		strcpy(s[ls].y,s[ls].x);
		sort(s[ls].y,s[ls].y+strlen(s[ls].y));
		ls++;
	}
	sort(s,s+ls);
	while (scanf("%s",a))
	{
		if(strcmp(a,"XXXXXX")==0) break;
		sort(a,a+strlen(a));
		int flag=0;
		for(int i=0;i<ls;i++)
			if(strcmp(a,s[i].y)==0) {printf("%s\n",s[i].x);flag=1;}
		if(! flag) puts("NOT A VALID WORD");
		printf("******\n");
	}
	
	return 0;
}