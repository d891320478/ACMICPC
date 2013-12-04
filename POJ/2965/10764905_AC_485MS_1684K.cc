#include <cstdio>
#include <cstring>
int po[18],head,tail;
int vis[70000];
char s[6];
struct que
{
	int x,y,t,pre;
}q[70000];
void fff(int tail)
{
	int xxx=q[tail].t;
	for(int i=0;i<16;i++)
	{
		if(xxx & (1<<i))printf("-");
		else printf("+");
		if((i+1)%4==0)printf("\n");
	}
}
void print(int tail)
{
	if(q[tail].pre!=-1) print(q[tail].pre);
	else return;
	//fff(tail);
	printf("%d %d\n",q[tail].x,q[tail].y);
}
int main ()
{
	po[0]=1;
	for(int i=1;i<=16;i++) po[i]=2*po[i-1];
	q[0].t=0; q[0].pre=-1;
	for(int i=0;i<4;i++)
	{
		scanf("%s",s);
		for(int j=0;j<4;j++)
			if(s[j]=='-') q[0].t+=po[4*i+j];
	}
	if(q[0].t==po[16]-1)
	{
		printf("0\n");
		return 0;
	}
	memset(vis,-1,sizeof(vis));
	vis[q[0].t]=0;
	head=tail=0;
	while (head<=tail)
	{
		int i,j,x;
		for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			x=q[head].t;
			x=x^(1<<(4*i)); x=x^(1<<(4*i+1)); x=x^(1<<(4*i+2)); x=x^(1<<(4*i+3));
			x=x^(1<<(j)); x=x^(1<<(j+4)); x=x^(1<<(j+8)); x=x^(1<<(j+12));
			x=x^(1<<(4*i+j));
			if(vis[x]==-1)
			{
				vis[x]=vis[q[head].t]+1;
				tail++;
				q[tail].t=x;
				q[tail].x=i+1;
				q[tail].y=j+1;
				q[tail].pre=head;
				if(x==po[16]-1)
				{
					printf("%d\n",vis[x]);
					print(tail);
					return 0;
				}
			}
		}
		head++;
	}
	//printf("%d %d\n",head,tail);
	return 0;
}