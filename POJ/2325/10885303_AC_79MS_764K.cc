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
#define N 10010
#define M 10010
string s;
int a[N],ans[N],c[N];
int Div(int x)
{
	int tmp=0;
	c[0]=a[0];
	for(int i=a[0];i>0;i--)
	{
		c[i]=(tmp*10+a[i])/x;
		tmp=(tmp*10+a[i])%x;
	}
	if(tmp) return 0;
	while (c[c[0]]==0 && c[0]>1)
	{
		c[0]--;
	}
	for(int i=0;i<=c[0];i++)
		a[i]=c[i];
	return 1;
}
int main ()
{
	int i;
	while (cin>>s)
	{
		if(s=="-1") break;
		if(s.size()==1)
		{
			cout<<1<<s<<endl;
			continue;
		}
		memset(a,0,sizeof(a));
		a[0]=s.size();
		for(i=1;i<=a[0];i++)
			a[i]=s[a[0]-i]-'0';
		ans[0]=0;
		for(i=9;i>1;i--)
		{
			while(Div(i)) ans[++ans[0]]=i;
		}
		if(a[0]==1 && a[1]==1)
		{
			for(i=ans[0];i>0;i--) printf("%d",ans[i]);
		}
		else printf("There is no such number.");
		printf("\n");
	}
	
	return 0;
}