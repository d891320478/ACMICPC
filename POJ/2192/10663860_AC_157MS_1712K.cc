#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define SET(a,b) memset(a,b,sizeof(a))
#define INF 1<<30
#define EPS 1e-8
string a,b,c;
bool f[1010][1010];
int i,j,la,lb;
int main()
{
	int tt,ttt;
	scanf("%d",&tt);
	for(ttt=1;ttt<=tt;ttt++)
	{
		cin>>a>>b>>c;
		la=a.size();
		lb=b.size();
		printf("Data set %d: ",ttt);
		if(la+lb!=c.size())
		{
			printf("no\n");
			continue;
		}
		SET(f,0);
		f[0][0]=1;
		for(i=1;i<=la;i++)
			f[i][0]=f[i-1][0] && a[i-1]==c[i-1];
		for(i=1;i<=lb;i++)
			f[0][i]=f[0][i-1] && b[i-1]==c[i-1];		
		for(i=1;i<=la;i++)
		for(j=1;j<=lb;j++)
			f[i][j]=(f[i-1][j] && a[i-1]==c[i+j-1]) || (f[i][j-1] && b[j-1]==c[i+j-1]);
		if(f[la][lb]) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
