#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string a,b,c;
int g[20],h[20];
int main ()
{
	int t;
	cin>>t;
	while (t--)
	{
		memset(g,-1,sizeof(g));
		for(int i=0;i<3;i++)
		{
			cin>>a>>b>>c;
			if(c=="even")
			{
				for(int j=0;j<a.size();j++)
					g[a[j]-'A']=g[b[j]-'A']=0;
			}
			if(c=="up")
			{
				for(int j=0;j<20;j++) h[j]=g[j];
				memset(g,0,sizeof(g));
				for(int j=0;j<a.size();j++)
				{
					g[a[j]-'A']=2;
					g[b[j]-'A']=1;
				}
				for(int j=0;j<20;j++)
					if(h[j]>=0 && h[j]!=g[j])g[j]=0;
			}
			if(c=="down")
			{
				for(int j=0;j<20;j++) h[j]=g[j];
				memset(g,0,sizeof(g));
				for(int j=0;j<a.size();j++)
				{
					g[a[j]-'A']=1;
					g[b[j]-'A']=2;
				}
				for(int j=0;j<20;j++)
					if(h[j]>=0 && h[j]!=g[j])g[j]=0;
			}
		}
		for(char i='A';i<='L';i++)
		{
			if(g[i-'A']==1)
			{
				cout<<i<<" is the counterfeit coin and it is "<<"light."<<endl;
			}
			if(g[i-'A']==2)
			{
				cout<<i<<" is the counterfeit coin and it is "<<"heavy."<<endl;
			}
		}
	}
	return 0;
}