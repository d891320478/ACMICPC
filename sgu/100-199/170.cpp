#include <cstdio>
#include <iostream>
#define N 10010
char s[N],t[N];
int a;
int main ()
{
	gets(s);
	gets(t);
	a=0;
	for(int i=0;s[i];++i) if(s[i]=='+') ++a;
	for(int i=0;t[i];++i) if(t[i]=='+') --a;
	if(a)
	{
		printf("-1\n");
		return 0;
	}
	int ans=0;
	for(int i=0;s[i];++i)
	if(s[i]!=t[i])
	for(int j=i+1;t[j];++j)
	if(s[i]==t[j])
	{
		ans+=j-i;
		std::swap(t[i],t[j]);
		break;
	}
	printf("%d\n",ans);
	return 0;
}
