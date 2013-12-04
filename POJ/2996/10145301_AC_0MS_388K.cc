#include <cstdio>

char s[9][9],t[17][40];
int i,j,flag;

void f1(char ch)
{
	for(int i=7;i>=0;i--)
	for(int j=0;j<8;j++)
	{
		if(s[i][j]==ch)
		{
			if(flag)printf(",");
			flag=1;
			if(ch!='P') printf("%c",ch);
			printf("%c%d",'a'+j,8-i);
		}
	}
}

void f2(char ch)
{
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	{
		if(s[i][j]==ch)
		{
			if(flag)printf(",");
			flag=1;
			if(ch!='p') printf("%c",ch-('a'-'A'));
			printf("%c%d",'a'+j,8-i);
		}
	}
}

int main()
{
	for(i=0;i<17;i++)
		scanf("%s",t[i]);
	for(i=1;i<17;i+=2)
	{
		int ls=0;
		for(j=2;j<33;j+=4)
			s[i/2][ls++]=t[i][j];
		s[i/2][ls]='\0';
	}
	printf("White: ");
	flag=0;
	f1('K'); f1('Q'); f1('R'); f1('B'); f1('N'); f1('P');
	printf("\nBlack: ");
	flag=0;
	f2('k'); f2('q'); f2('r'); f2('b'); f2('n'); f2('p');
	printf("\n");
	
	return 0;
}
