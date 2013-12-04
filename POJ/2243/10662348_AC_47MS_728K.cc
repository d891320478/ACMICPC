#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
const int x[]={1,1,2,2,-1,-1,-2,-2};
const int y[]={2,-2,1,-1,2,-2,1,-1};
string s1,s2;
int head,tail;
int q[100][3];
bool v[9][9];
int main ()
{
	while (cin>>s1>>s2)
	{
		cout<<"To get from "<<s1<<" to "<<s2<<" takes ";
		if(s1==s2)
		{
			cout<<0<<" knight moves."<<endl;
			continue;
		}
		head=tail=0;
		q[0][0]=s1[0]-'a';
		q[0][1]=s1[1]-'1';
		q[0][2]=0;
		SET(v,0);
		v[q[0][0]][q[0][1]]=1;
		bool flag=0;
		while (head<=tail)
		{
			int a=q[head][0],b=q[head][1];
			for(int i=0;i<8;i++)
			{
				if(a+x[i]>=0 && a+x[i]<8 && b+y[i]>=0 && b+y[i]<8)
				if(! v[a+x[i]][b+y[i]])
				{
					v[a+x[i]][b+y[i]]=1;
					tail++;
					q[tail][0]=a+x[i];
					q[tail][1]=b+y[i];
					q[tail][2]=q[head][2]+1;
					if(q[tail][0]==s2[0]-'a' && q[tail][1]==s2[1]-'1')
					{
						flag=1;
						break;
					}
				}
			}
			if(flag)break;
			head++;
		}
		cout<<q[tail][2]<<" knight moves."<<endl;
	}
	
	return 0;
}