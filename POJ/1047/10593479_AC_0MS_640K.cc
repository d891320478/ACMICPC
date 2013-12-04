#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string s;
int a[600],l;
int main ()
{
	while (cin>>s)
	{
		l=a[0]=s.size();
		for(int i=a[0];i>0;i--)
			a[i]=s[a[0]-i]-'0';
		l++;
		for(int i=1;i<=a[0];i++)
		{
			a[i]*=l;
			if(i>1)
			{
				a[i]+=a[i-1]/10;
				a[i-1]%=10;
			}
		}
		while(a[a[0]]>=10)
		{
			a[a[0]+1]=a[a[0]]/10;
			a[a[0]]%=10;
			a[0]++;
		}
		bool flag=1;
		for(int i=1;i<=a[0];i++)
			if(a[i]!=9)
			{
				flag=0;
				break;
			}
		if(flag)cout<<s<<" is cyclic"<<endl;
		else cout<<s<<" is not cyclic"<<endl;
	}
	
	return 0;
}