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
	n=i;
	sort(a,a+n);
	for(i=0;t[i];i++)
		b[t[i]-'A']++;
	sort(b,b+n);
	for(i=0;i<n;i++)
		if(a[i]!=b[i])
		{
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	
	return 0;
}