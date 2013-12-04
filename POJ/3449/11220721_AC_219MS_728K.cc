#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 40
#define M 10010
struct point
{
	double x,y;
};
struct geo
{
	char id;
	int n;
	point p[N];
}g[N];
int lg;
char ch,st[100];
int cmp(geo a,geo b)
{
	return a.id<b.id;
}
double xmult(point p0,point p1,point p2)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
int intersection(point u1,point u2,point v1,point v2)
{
	return (max(u1.x,u2.x)>=min(v1.x,v2.x))&&(max(v1.x,v2.x)>=min(u1.x,u2.x))
		 &&(max(u1.y,u2.y)>=min(v1.y,v2.y))&&(max(v1.y,v2.y)>=min(u1.y,u2.y))
		 &&(xmult(u1,v1,u2)*xmult(u1,u2,v2)>=0)&&(xmult(v1,u1,v2)*xmult(v1,v2,u2)>=0);
}
int cross(int a,int b)
{
	for(int i=0;i<g[a].n-1;i++)
	for(int j=0;j<g[b].n-1;j++)
		if(intersection(g[a].p[i],g[a].p[i+1],g[b].p[j],g[b].p[j+1])) return 1;
	return 0;
}
int main()
{
	while (1)
	{
		lg=0;
		while (1)
		{
			scanf("%c",&ch);
			//printf("ch = %c\n",ch);
			if(ch=='.')return 0;
			if(ch=='-'){getchar();break;}
			g[lg].id=ch;
			scanf("%s",st);
			if(strcmp(st,"square")==0)
			{
				g[lg].n=5;
				scanf(" (%lf,%lf)",&g[lg].p[0].x,&g[lg].p[0].y);
				scanf(" (%lf,%lf)",&g[lg].p[2].x,&g[lg].p[2].y);
				double x=(g[lg].p[0].x+g[lg].p[2].x)/2.0,y=(g[lg].p[0].y+g[lg].p[2].y)/2.0;
				g[lg].p[1].x=y-g[lg].p[0].y+x;
				g[lg].p[1].y=g[lg].p[0].x-x+y;
				g[lg].p[3].x=y-g[lg].p[2].y+x;
				g[lg].p[3].y=g[lg].p[2].x-x+y;
				g[lg].p[4]=g[lg].p[0];
			}
			if(strcmp(st,"line")==0)
			{
				g[lg].n=2;
				scanf(" (%lf,%lf)",&g[lg].p[0].x,&g[lg].p[0].y);
				scanf(" (%lf,%lf)",&g[lg].p[1].x,&g[lg].p[1].y);
			}
			if(strcmp(st,"triangle")==0)
			{
				g[lg].n=4;
				scanf(" (%lf,%lf)",&g[lg].p[0].x,&g[lg].p[0].y);
				scanf(" (%lf,%lf)",&g[lg].p[1].x,&g[lg].p[1].y);
				scanf(" (%lf,%lf)",&g[lg].p[2].x,&g[lg].p[2].y);
				g[lg].p[3]=g[lg].p[0];
			}
			if(strcmp(st,"polygon")==0)
			{
				scanf("%d",&g[lg].n);
				for(int i=0;i<g[lg].n;i++)
					scanf(" (%lf,%lf)",&g[lg].p[i].x,&g[lg].p[i].y);
				g[lg].p[g[lg].n]=g[lg].p[0];
				g[lg].n++;
			}
			if(strcmp(st,"rectangle")==0)
			{
				g[lg].n=5;
				scanf(" (%lf,%lf)",&g[lg].p[0].x,&g[lg].p[0].y);
				scanf(" (%lf,%lf)",&g[lg].p[1].x,&g[lg].p[1].y);
				scanf(" (%lf,%lf)",&g[lg].p[2].x,&g[lg].p[2].y);
				g[lg].p[3].x=g[lg].p[2].x-g[lg].p[1].x+g[lg].p[0].x;
				g[lg].p[3].y=g[lg].p[2].y-g[lg].p[1].y+g[lg].p[0].y;
				g[lg].p[4]=g[lg].p[0];
			}
			lg++;
			getchar();
		}
		sort(g,g+lg,cmp);
		/*
		for(int i=0;i<lg;i++)
		{
			for(int j=0;j<g[i].n;j++)
				printf("%.2f %.2f  ",g[i].p[j].x,g[i].p[j].y);
			printf("\n");
		}
		*/
		for(int i=0;i<lg;i++)
		{
			int ans=0;
			char as[N];
			for(int j=0;j<lg;j++)
				if(i!=j)
				if(cross(i,j)) as[ans++]=g[j].id;
			printf("%c",g[i].id);
			if(! ans) printf(" has no intersections\n");
			else if(ans==1)
			printf(" intersects with %c\n",as[0]);
			else if(ans==2) printf(" intersects with %c and %c\n",as[0],as[1]);
			else
			{
				printf(" intersects with");
				for(int j=0;j<ans-1;j++)
					printf(" %c,",as[j]);
				printf(" and %c\n",as[ans-1]);
			}
		}
		printf("\n");
	}
	return 0;
}