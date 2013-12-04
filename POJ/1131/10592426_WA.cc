#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
long long a[1000000],b;
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
			tmp=0; b=0;
			while (tmp || b==0)
			{
				tmp=tmp*10+a[b];
				a[b]=tmp/8;
				tmp%=8;
				b++;
			}
		}
		cout<<s<<" [8] = 0.";
		while(a[a[0]]==0 && a[0]>0)a[0]--;
		for(int i=1;i<b;i++)
			cout<<a[i];
		cout<<" [10]\n";
	}
	
	return 0;
}
