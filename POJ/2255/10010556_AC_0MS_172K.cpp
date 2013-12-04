#include <cstdio>
#include <cstring>

char s[30];
int l,m;

void f(char *a,char *b)
{
	char c[30],d[30];
	int i,k;

	if(a[0]=='\0')return;
	for(k=0;b[k]!=a[0];k++);
	for(i=0;i<k;i++) c[i]=a[i+1];
	c[i]='\0';
	for(i=0;i<k;i++) d[i]=b[i];
	d[i]='\0';
	f(c,d);
	for(i=k+1;a[i];i++) c[i-k-1]=a[i];
	c[i-k-1]='\0';
	for(i=k+1;b[i];i++) d[i-k-1]=b[i];
	d[i-k-1]='\0';
	f(c,d);
	s[m++]=a[0];
}

int main ()
{
	char s1[30],s2[30];

	while (scanf("%s%s",s1,s2)!=EOF)
	{
		l=strlen(s1);
		s[l]='\0';
		m=0;
		f(s1,s2);
		printf("%s\n",s);
	}
	
	return 0;
}
