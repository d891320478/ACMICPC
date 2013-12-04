#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
long long a[1000000],b,c;
string s;
int main ()
{
	while (cin>>s)
	{
		memset(a,0,sizeof(a));
		for(int i=s.size()-1;i>1;i--)
		{
			long long tmp;
			a[0]=s[i]-'0';
			tmp=0; c=0;
			while (tmp || c<=b)
			{
				tmp=tmp*10+a[c];
				a[c]=tmp/8;
				tmp%=8;
				c++;
			}
			b=c;
		}
		cout<<s<<" [8] = 0.";
		b--;
		while(a[b]==0 && b>1)b--;
		for(int i=1;i<=b;i++)
			cout<<a[i];
		cout<<" [10]\n";
	}
	
	return 0;
}
