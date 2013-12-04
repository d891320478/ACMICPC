#include <string>
#include <iostream>
using namespace std;
string s,t;
int a[100000],b[100000],c[200000],i;
int main ()
{
	cin>>s>>t;
	a[0]=s.size();
	b[0]=t.size();
	for(i=1;i<=a[0];i++)
		a[i]=s[a[0]-i]-'0';
	for(i=1;i<=b[0];i++)
		b[i]=t[b[0]-i]-'0';
	c[0]=a[0]+b[0]-1;
	for(int i=1;i<=a[0];i++)
	for(int j=1;j<=b[0];j++)
	{
		c[i+j-1]+=a[i]*b[j];
		c[i+j]+=c[i+j-1]/10;
		c[i+j-1]%=10;
	}
	if(c[c[0]+1]>0) c[0]++;
	for(int i=c[0];i>0;i--)
		cout<<c[i];
	cout<<endl;
	
	return 0;
}