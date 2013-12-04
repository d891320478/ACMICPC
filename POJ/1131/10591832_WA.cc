#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
long long a[100000],b[100000],w;
string s;
int main ()
{
	while (cin>>s)
	{
		memset(a,0,sizeof(a));
		w=1;
		for(int i=2;i<s.size();i++)
		{
			int x=s[i]-'0',tmp;
			tmp=x;
			b[0]=0;
			w*=8;
			while (tmp)
			{
				b[++b[0]]=tmp/w;
				tmp%=w;
				tmp*=10;
			}
			for(int j=b[0];j>0;j--)
			{
				a[j]+=b[j];
				if(a[j]>=10)
				{
					a[j-1]+=a[j]/10;
					a[j]%=10;
				}
			}
			a[0]=b[0]>a[0]?b[0]:a[0];
		}
		cout<<s<<" [8] = 0.";
		while(a[a[0]]==0 && a[0]>0)a[0]--;
		for(int i=1;i<=a[0];i++)
			cout<<a[i];
		cout<<" [10]\n";
	}
	
	return 0;
}
