#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char digit[5][30]={{' ','-',' ',' ',' ',' ',' ','-',' ',' ','-',' ',' ',' ',' ',' ','-',' ',' ','-',' ',' ','-',' ',' ','-',' ',' ','-',' '},
                            {'|',' ','|',' ',' ','|',' ',' ','|',' ',' ','|','|',' ','|','|',' ',' ','|',' ',' ',' ',' ','|','|',' ','|','|',' ','|'},
                           {' ',' ',' ',' ',' ',' ',' ','-',' ',' ','-',' ',' ','-',' ',' ','-',' ',' ','-',' ',' ',' ',' ',' ','-',' ',' ','-',' '},
                           {'|',' ','|',' ',' ','|','|',' ',' ',' ',' ','|',' ',' ','|',' ',' ','|','|',' ','|',' ',' ','|','|',' ','|',' ',' ','|'},
                           {' ','-',' ',' ',' ',' ',' ','-',' ',' ','-',' ',' ',' ',' ',' ','-',' ',' ','-',' ',' ',' ',' ',' ','-',' ',' ','-',' '}};
string s;
int t;
void f(string s,int z,int t)
{
	int st,i,l=s.size(),j;
	for(i=0;i<l;i++)
	{
		st=(s[i]-'0')*3;
		cout<<digit[z][st];
		for(j=0;j<t;j++)
			cout<<digit[z][st+1];
		cout<<digit[z][st+2];
		if(i<l-1)cout<<' ';
	}
	cout<<endl;
}
int main()
{
	int i,j;
	while (cin>>t>>s,t)
	{
		for(i=0;i<5;i++)
		if(i%2)
			for(j=0;j<t;j++)
				f(s,i,t);
		else f(s,i,t);
		printf("\n");
	}
	
	return 0;
}