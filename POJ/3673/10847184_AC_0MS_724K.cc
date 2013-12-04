#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 10010
#define M 10010
string a,b;
long long sum=0;
int i,j;
int main ()
{
	cin>>a>>b;
	for(i=0;i<a.size();i++)
	for(j=0;j<b.size();j++)
		sum+=(a[i]-'0')*(b[j]-'0');
	cout<<sum<<endl;
	
	return 0;
}