#include <cstdio>
#include <cstring>

char s1[200],s2[200],t[20][40],ch,s[5];
int i,j,l;

int main()
{
	scanf("White: %s%c",s1,&ch);
	scanf("Black: %s%c",s2,&ch);
	l=strlen(s1);
	s1[l]=',';s1[l+1]='\0';
	l=strlen(s2);
	s2[l]=',';s2[l+1]='\0';
	for(i=0;i<17;i+=2)
		strcpy(t[i],"+---+---+---+---+---+---+---+---+");
	for(i=1;i<17;i+=4)
		strcpy(t[i],"|...|:::|...|:::|...|:::|...|:::|");
	for(i=3;i<17;i+=4)
		strcpy(t[i],"|:::|...|:::|...|:::|...|:::|...|");
	for(i=0;s1[i];i++)
	{
		int ls=0,j,k;
		while(s1[i]!=',') s[ls++]=s1[i++];
		s[ls]='\0';
		if(ls==3)ch=s[0];
		else ch='P';
		j=s[ls-1]-'1'; k=s[ls-2]-'a';
		t[(7-j)*2+1][2+k*4]=ch;
	}
	for(i=0;s2[i];i++)
	{
		int ls=0,j,k;
		while(s2[i]!=',')s[ls++]=s2[i++];
		s[ls]='\0';
		if(ls==3)ch=s[0]+'a'-'A';
		else ch='p';
		j=s[ls-1]-'1'; k=s[ls-2]-'a';
		t[(7-j)*2+1][2+k*4]=ch;
	}
	for(i=0;i<17;i++)
		printf("%s\n",t[i]);
		
	return 0;
}