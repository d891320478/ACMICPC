#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string a,b,c;
int g[20];
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
			for(int j=0;j<a.size();j++)
			{
				if(g[a[j]-'A']==-1)g[a[j]-'A']=2;
				else if(g[a[j]-'A']==1)g[a[j]-'A']=0;
				if(g[b[j]-'A']==-1)g[b[j]-'A']=1;
				else if(g[b[j]-'A']==2)g[b[j]-'A']=0;
			}
			if(c=="down")
			for(int j=0;j<a.size();j++)
			{
				if(g[a[j]-'A']==-1)g[a[j]-'A']=1;
				else if(g[a[j]-'A']==2)g[a[j]-'A']=0;
				if(g[b[j]-'A']==-1)g[b[j]-'A']=2;
				else if(g[b[j]-'A']==1)g[b[j]-'A']=0;
			}
		}
		for(char i='A';i<='L';i++)
		{
			if(g[i-'A']==1)
			{
				cout<<i<<" is the counterfeit coin and it is "<<"light."<<endl;
				break;
			}
			if(g[i-'A']==2)
			{
				cout<<i<<" is the counterfeit coin and it is "<<"heavy."<<endl;
				break;
			}
		}
	}
	return 0;
}