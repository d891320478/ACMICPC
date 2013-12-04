#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
string s;
int a[20],i;
int main ()
{
	while (cin>>s)
	{
		for(i=0;i<s.size();i++)
			a[i]=(a[i]+s[i]-'0')%10;
	}
	for(i=0;i<s.size();i++)
		printf("%d",a[i]);
	printf("\n");
	
	return 0;
}
