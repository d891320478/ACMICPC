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
int n,a[30],a1,a2,i;
string s;
int main ()
{
	while (cin>>n && n)
	{
		cin>>s;
		SET(a,0);
		a1=a2=0;
		for(i=0;i<s.size();i++)
		{
			if(a[s[i]-'A']==0)
			{
				if(a1<n)
				{
					a1++;
					a[s[i]-'A']=1;
				}
				else
				{
					a2++;
					a[s[i]-'A']=2;
				}
			}
			else {if(a[s[i]-'A']==1)a1--;a[s[i]-'A']=0;}
		}
		if(a2==0)printf("All customers tanned successfully.\n");
		else printf("%d customer(s) walked away.\n",a2);
	}
	
	return 0;
}