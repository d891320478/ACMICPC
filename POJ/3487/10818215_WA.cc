#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#define N 30
using namespace std;
map<char,int>q;
int ms,ws,n;
int a[N],b[N];
char s[200],ch;
int ls;
struct people
{
	bool state;
	int opp,tag;
	int list[N];
	void clear(){state=tag=0;}
}man[N],woman[N];
struct R
{
	int opp,own;
}requst[N];
void stablematch()
{
	int k;
	for(k=0;k<n;k++)
	{
		int i,id=0;
		for(i=0;i<n;i++)
			if(man[i].state==0)
			{
				requst[id].opp=man[i].list[man[i].tag];
				requst[id].own=i;
				man[i].tag+=1;
				id++;
			}
		if(id==0)break;
		for(i=0;i<id;i++)
		{
			if(woman[requst[i].opp].state==0)
			{
				woman[requst[i].opp].opp=requst[i].own;
				woman[requst[i].opp].state=1;
				man[requst[i].own].state=1;
				man[requst[i].own].opp=requst[i].opp;
			}
			else
			{
				if(woman[requst[i].opp].list[woman[requst[i].opp].opp]>woman[requst[i].opp].list[requst[i].own])
				{
					man[woman[requst[i].opp].opp].state=0;
					woman[requst[i].opp].opp=requst[i].own;
					man[requst[i].own].state=1;
					man[requst[i].own].opp=requst[i].opp;
				}
			}
		}
	}
}
int main ()
{
	int tttt,i,j;
	scanf("%d",&tttt);
	while (tttt--)
	{
		scanf("%d%c",&n,&ch);
		ms=ws=0;
		q.clear();
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		gets(s); ls=strlen(s);
		for(i=0;i<ls;i+=2)
		{
			if(s[i]>='a')
			{
				q[s[i]]=ms;
				a[ms]=s[i]-'a';
				ms++;
			}
			else
			{
				q[s[i]]=ws;
				b[ws]=s[i]-'A';
				ws++;
			}
		}
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			int now=q[s[0]];
			man[now].clear();
			for(j=2;s[j];j++)
				man[now].list[j-2]=q[s[j]];
		}
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			int now=q[s[0]];
			woman[now].clear();
			for(j=2;s[j];j++)
				woman[now].list[q[s[j]]]=j-2;
		}
		stablematch();
		for(i=0;i<n;i++)
			printf("%c %c\n",a[i]+'a',b[man[i].opp]+'A');
		if(tttt)printf("\n");
	}
	
	return 0;
}