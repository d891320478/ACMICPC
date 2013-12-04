#include <cstdio>
#include <cstring>
char s[210];
long long b[210],lb,l;
long long m,i,j,a[100000];
long long tmp;
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
	while (scanf("%s %lld",s,&m))
	{
		if(m==0)break;
		lb=1; l=0;
		memset(b,0,sizeof(b));
		for(i=strlen(s)-1;i>=0;i--)
		{
			if(l==4)lb++,l=0;
			if(l==0)b[lb]+=s[i]-'0';
			if(l==1)b[lb]+=(s[i]-'0')*10;
			if(l==2)b[lb]+=(s[i]-'0')*100;
			if(l==3)b[lb]+=(s[i]-'0')*1000;
			l++;
		}
		i=a[0];
		for(i=1;a[i]<m && i<=a[0];i++)
		{
			flag=tmp=0;
			for(j=lb;j>0;j--)
			{
				tmp=tmp*10000+b[j];
				tmp%=a[i];
			}
			if(tmp==0){flag=1;break;}
		}
		if(flag)printf("BAD %lld\n",a[i]);
		else printf("GOOD\n");
	}
	
	return 0;
}
