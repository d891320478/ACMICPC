#include <cstdio>
#include <algorithm>
using namespace std;

char s[110],t[110];
int a[30],b[30],i,n;

int main ()
{
	scanf("%s%s",s,t);
	for(i=0;s[i];i++)
		a[s[i]-'A']++;
	sort(a,a+26);
	for(i=0;t[i];i++)
		b[t[i]-'A']++;
	sort(b,b+26);
	for(i=0;i<26;i++)
		if(a[i]!=b[i])
		{
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	
	return 0;
}