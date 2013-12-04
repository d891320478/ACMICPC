#include <iostream>
#include <string>
using namespace std;
string s;
int a[3000],b[3000];
int main ()
{
	while (cin>>s && s!="0")
	{
		a[0]=s.size();
		for(int i=0;i<a[0];i++)
			a[a[0]-i]=s[i]-'0';
		while (a[0]!=1)
		{
			for(int i=0;i<=a[0];i++)
				b[i]=a[i];
			a[0]=1;
			a[1]=b[1];
			for(int i=2;i<=b[0];i++)
			{
				a[1]+=b[i];
				for(int j=2;j<=a[0];j++)
				{
					a[j]+=a[j-1]/10;
					a[j-1]%=10;
				}
				if(a[a[0]]>=10)
				{
					a[0]++;
					a[a[0]]=a[a[0]-1]/10;
					a[a[0]-1]%=10;
				}
			}
		}
		cout<<a[1]<<endl;
	}
	
	return 0;
}
