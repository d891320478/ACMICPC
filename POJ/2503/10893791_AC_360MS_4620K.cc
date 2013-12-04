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
struct dic
{
	char x[20],y[20];
}d[N];
int ld;
char s[100];
int operator < (dic a,dic b)
{
	return strcmp(a.y,b.y)<=0;
}
int search(int l,int r,char* s)
{
	int mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		int x=strcmp(d[mid].y,s);
		if(x==0) return mid;
		if(x<0) l=mid+1;
		else r=mid-1;
	}
	return -1;
}
int main ()
{
	while (gets(s))
	{
		if(s[0]==0) break;
		int i;
		for(i=0;s[i]!=' ';i++)
			d[ld].x[i]=s[i];
		d[ld].x[i]=0;
		for(i++;s[i];i++)
			d[ld].y[i-strlen(d[ld].x)-1]=s[i];
		ld++;
	}
	sort(d,d+ld);
	while (scanf("%s",s)!=-1)
	{
		int i=search(0,ld,s);
		if(i==-1) printf("eh\n");
		else puts(d[i].x);
	}
	
	return 0;
}