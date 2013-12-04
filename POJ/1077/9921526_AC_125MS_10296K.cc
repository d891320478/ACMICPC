#include<cstdio>
#include<cmath>

long z[10] = {1,1,2,6,24,120,720,5040,40320,362880};
long num;
struct
{
	char ch;
	int a[10],pre;
}x[400000];
int u[400000]={0},b[10];

void cantor(int s[])
{
	int i,j,temp;

	num=1;
	for(i=0;i<8;i++)
	{
		temp=0;
		for(j=i+1;j<9;j++)
		{
			if(s[j]<s[i]) temp++;
		}
		num+=z[8-i]*temp;
	}
}

int fact(long ttt)
{
	for (unsigned int i = 0; i < 8; i += 1)
	{
		if(x[ttt].a[i]!=i+1)return 0;
	}
	return 1;
}

void print(long h)
{
	if(x[h].pre!=-1)
	{
		print(x[h].pre);
		printf("%c",x[h].ch);
	}
}

int main()
{
	char c,d;
	long head=0,tail=0,j;

    for (unsigned int i = 0; i < 9; i += 1)
    {
    	scanf("%c%c",&c,&d);
    	if (c=='x') x[0].a[i]=0;
    	else x[0].a[i]=c-'0';
    }
    cantor(x[0].a);
    u[num]=1;
    x[0].pre=-1;
    while(head<=tail)
    {
        for (unsigned int i = 0; i < 9; i += 1)
    	{
			b[i]=x[head].a[i];
			if(b[i]==0) j=i;
		}
		if(j>2)
		{
			b[j]=b[j-3];
			b[j-3]=0;
			cantor(b);
    		if(u[num]==0)
    		{
    			u[num]=1;
    			tail++;
    			x[tail].pre=head;
    			x[tail].ch='u';
    			for (unsigned int i = 0; i < 9; i += 1)
					x[tail].a[i]=b[i];
				if(fact(tail))
				{
					print(tail);
					printf("\n");
					return 0;
				}
    		}
		}
		for (unsigned int i = 0; i < 9; i += 1)
    	{
			b[i]=x[head].a[i];
			if(b[i]==0) j=i;
		}
		if(j<6)
		{
		    
			b[j]=b[j+3];
			b[j+3]=0;
			cantor(b);
    		if(u[num]==0)
    		{
    			u[num]=1;
    			tail++;
    			x[tail].pre=head;
    			x[tail].ch='d';
    			for (unsigned int i = 0; i < 9; i += 1)
					x[tail].a[i]=b[i];
				if(fact(tail))
				{
					print(tail);
					printf("\n");
					return 0;
				}
    		}
		}
		for (unsigned int i = 0; i < 9; i += 1)
    	{
			b[i]=x[head].a[i];
			if(b[i]==0) j=i;
		}
		if(j!=0 && j!=3 && j!=6)
		{
			b[j]=b[j-1];
			b[j-1]=0;
			cantor(b);
    		if(u[num]==0)
    		{
    		    u[num]=1;
    			tail++;
    			x[tail].pre=head;
    			x[tail].ch='l';
    			for (unsigned int i = 0; i < 9; i += 1)
					x[tail].a[i]=b[i];
				if(fact(tail))
				{
					print(tail);
					printf("\n");
					return 0;
				}
    		}
		}
    	for (unsigned int i = 0; i < 9; i += 1)
    	{
			b[i]=x[head].a[i];
			if(b[i]==0) j=i;
		}
		if(j!=2 && j!=5 && j!=8)
		{
			b[j]=b[j+1];
			b[j+1]=0;
			cantor(b);
    		if(u[num]==0)
    		{
    		    u[num]=1;
    			tail++;
    			x[tail].pre=head;
    			x[tail].ch='r';
    			for (unsigned int i = 0; i < 9; i += 1)
					x[tail].a[i]=b[i];
				if(fact(tail))
				{
					print(tail);
					printf("\n");
					return 0;
				}
    		}
		}
		head++;
    }
    printf("unsolvable\n");

	return 0;
}