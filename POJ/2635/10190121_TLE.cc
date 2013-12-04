#include <cstdio>
#include <cstring>
char s[110];
int m,tmp,i,j,a[100000];
bool f[1000001]={1,1,0},flag;
int main()
{
	for(i=2;i<=1000000;i++)
	if(! f[i])
	{
		a[++a[0]]=i;
		for(j=2;i*j<=1000000;j++)
			f[i*j]=1;
	}
	while (scanf("%s %d",s,&m))
	{
		if(!strcmp(s,"0") && m==0)break;
		for(i=1;a[i]<=m && i<=a[0];i++)
		{
			flag=tmp=0;
			for(j=0;s[j];j++)
			{
				tmp=tmp*10+s[j]-'0';
				tmp%=a[i];
			}
			if(tmp==0){flag=1;break;}
		}
		if(flag)printf("BAD %d\n",a[i]);
		else printf("GOOD\n");
	}
	
	return 0;
}
