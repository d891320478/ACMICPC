#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 1000010
char s[N],a[N<<1];
int p[N<<1],la,ans;
void lpd()
{
	int mx=0,id;
	for(int i=1;i<la;i++)
	{
		if(mx>i) p[i]=min(p[id*2-i],mx-i);
		else p[i]=1;
		for(;a[i+p[i]]==a[i-p[i]];p[i]++);
		if(p[i]+i>mx)
		{
			mx=p[i]+i;
			id=i;
		}
		ans=max(ans,p[i]-1);
	}
	
}
int main ()
{
	int tt=0;
	while (scanf("%s",s))
	{
		if(strcmp(s,"END")==0) break;
		a[0]='$';
		a[1]='#';
		la=2;
		for(int i=0;s[i];i++)
		{
			a[la++]=s[i];
			a[la++]='#';
		}
		a[la++]=0;
		ans=0;
		lpd();
		printf("Case %d: %d\n",++tt,ans);
	}
	
	return 0;
}