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
#include<vector>
#include<utility>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 40
#define MM 10010
char s[110];
int dp[110][110];
int ls;
void find(int l,int r)
{
	//printf("%d %d\n",l,r);
	if(l>r) return;
	if(l==r)
	{
		if(s[l-1]=='(' || s[l-1]==')') printf("()");
		if(s[l-1]=='[' || s[l-1]==']') printf("[]");
		return;
	}
	if(s[l-1]=='(' && s[r-1]==')' || s[l-1]=='[' && s[r-1]==']')
	if(dp[l][r]==dp[l+1][r-1])
	{
		printf("%c",s[l-1]);
		find(l+1,r-1);
		printf("%c",s[r-1]);
		return;
	}
	if(dp[l][r]==dp[l+1][r]+1)
	if(s[l-1]=='(' || s[l-1]=='[')
	{
		if(s[l-1]=='(') printf("()");
		else printf("[]");
		find(l+1,r);
		return;
	}
	if(dp[l][r]==dp[l][r-1]+1)
	if(s[r-1]==')' || s[r-1]==']')
	{
		if(s[l-1]==')') printf("()");
		else printf("[]");
		find(l,r-1);
		return;
	}
	for(int k=l;k<r;k++)
		if(dp[l][r]==dp[l][k]+dp[k+1][r])
		{
			find(l,k);
			find(k+1,r);
			return;
		}
}
int main()
{
	scanf("%s",s);
	{
		ls=strlen(s);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=ls;i++) dp[i][i]=1;
	
		for(int i=2;i<=ls;i++)
		for(int j=1;j<=ls;j++)
		if(j+i-1<=ls)
		{
			dp[j][j+i-1]=INF;
			if(s[j-1]=='(' && s[j+i-2]==')' || s[j-1]=='[' && s[j+i-2]==']')
				dp[j][j+i-1]=dp[j+1][j+i-2];
			if(s[j-1]=='(' || s[j-1]=='[')
				dp[j][j+i-1]=min(dp[j][j+i-1],dp[j+1][j+i-1]+1);
			if(s[j+i-1]==')' || s[j+i-1]==']')
				dp[j][j+i-1]=min(dp[j][j+i-1],dp[j][j+i-2]+1);
			for(int k=j;k<j+i-1;k++)
				dp[j][j+i-1]=min(dp[j][j+i-1],dp[j][k]+dp[k+1][j+i-1]);
		}
		//printf("%d\n",dp[1][ls]);
		find(1,ls);
		printf("\n");
	}
	return 0;
}