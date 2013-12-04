#include<stdio.h>
#include<string.h>

char ss[10]="000000000",s0[10]="\0";
struct
{
	char s[10];
	int a;
	int b;
}x[500000]={"\0",0,0};
int f[500000];
long int z;
int n,i,j;
int open=0,closed=0;

char s90(char s)
{
     s=s+1;
     if(s=='4')s='0';
     return s;
}

long int search()
{
    long int i,j=1;
    long int sum=0;
    
    for(i=8;i>=0;i--)
    {
        sum=sum+(s0[i]-'0')*j;
        j*=4;
    }
    return sum;
}

void print(int cl)
{
     if(x[cl].a != 0)
     {
         print(x[cl].a);
         printf(" %d",x[cl].b);
     }
     else printf("%d",x[cl].b);
}

void add()
{
     strcpy(x[++closed].s,s0);
     x[closed].a=open;
     x[closed].b=i;
}

int main()
{
	for(i=1;i<=9;i++)
	{	
		scanf("%d",&n);
		x[0].s[i-1]=n+'0';
	}
    while(open<=closed)
	{
		for(i=1;i<=9;i++)
		{
            strcpy(s0,x[open].s);
			if(i==1)
			{
				s0[0]=s90(s0[0]);
				s0[1]=s90(s0[1]);
				s0[3]=s90(s0[3]);
				s0[4]=s90(s0[4]);
				z=search();
                if(! f[z])
				{
                    f[z]=1;
                    add();
                }
			}
			if(i==2)
			{
				s0[0]=s90(s0[0]);
				s0[1]=s90(s0[1]);
				s0[2]=s90(s0[2]);
				z=search();
                if(! f[z])
				{
                    f[z]=1;
                    add();
                }
			}
            if(i==3)
            {
				s0[1]=s90(s0[1]);
				s0[2]=s90(s0[2]);
				s0[4]=s90(s0[4]);
				s0[5]=s90(s0[5]);
				z=search();
                if(! f[z])
				{
                    f[z]=1;
                    add();
                }
			}
			if(i==4)
			{
				s0[0]=s90(s0[0]);
				s0[3]=s90(s0[3]);
				s0[6]=s90(s0[6]);
				z=search();
                if(! f[z])
				{
                    f[z]=1;
                    add();
                }
			}
			if(i==5)
			{
				s0[1]=s90(s0[1]);
				s0[3]=s90(s0[3]);
				s0[4]=s90(s0[4]);
				s0[5]=s90(s0[5]);
				s0[7]=s90(s0[7]);
				z=search();
                if(! f[z])
				{
                    f[z]=1;
                    add();
                }
			}
			if(i==6)
			{
				s0[2]=s90(s0[2]);
				s0[5]=s90(s0[5]);
				s0[8]=s90(s0[8]);
				z=search();
                if(! f[z])
				{
                    f[z]=1;
                    add();
                }
			}
			if(i==7)
			{
				s0[3]=s90(s0[3]);
				s0[4]=s90(s0[4]);
				s0[6]=s90(s0[6]);
				s0[7]=s90(s0[7]);
				z=search();
                if(! f[z])
				{
                    f[z]=1;
                    add();
                }
			}
			if(i==8)
			{
				s0[8]=s90(s0[8]);
				s0[6]=s90(s0[6]);
				s0[7]=s90(s0[7]);
				z=search();
                if(! f[z])
				{
                    f[z]=1;
                    add();
                }
			}
			if(i==9)
			{
				s0[5]=s90(s0[5]);
				s0[4]=s90(s0[4]);
				s0[8]=s90(s0[8]);
				s0[7]=s90(s0[7]);
				z=search();
                if(! f[z])
				{
                    f[z]=1;
                    add();
                }
			}
            if(strcmp(x[closed].s,ss)==0)
			{
                print(closed);
                printf("\n");
                return 0;
            }
		}
		open++;
	}
	
	return 0;
}
