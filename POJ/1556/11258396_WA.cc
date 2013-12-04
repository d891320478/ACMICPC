/*
author:jxy
lang:C/C++
university:China,Xidian University
**If you need to reprint,please indicate the source**
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <queue>
#define INF 1E9
using namespace std;
struct node

{

    double x,y;

    node(double a,double b)

    {

        x=a;y=b;

    }

    node(){}

};

double dx[20];

double dy[20][4];

double dis[80][80]={0};

node pp[80];

int n,cnt;

double d(node a,node b)

{

    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}

int p(node a,node b,double x,double y)//小于0，点c在直线ab下，反之上方

{

    return (b.x-a.x)*(y-a.y)-(x-a.x)*(b.y-a.y);

}

bool isok(node a,node b)

{

    int i,j;

    for(i=0;i<n&&dx[i]<=a.x;i++);

    bool flag=1;

    for(;i<n&&dx[i]<b.x;i++)

    {

        flag=0;

        for(j=0;j<4;j+=2)

           if(p(a,b,dx[i],dy[i][j])*p(a,b,dx[i],dy[i][j+1])<=0)flag=1;

        if(!flag)return 0;

    }

    return 1;

}

bool input()

{

    scanf("%d",&n);

    if(n==-1)return 0;

    int i,j;

    cnt=0;

    pp[cnt++]=node(0,5);

    for(i=0;i<n;i++)

    {

        scanf("%lf",&dx[i]);

        for(j=0;j<4;j++)

        {

            scanf("%lf",&dy[i][j]);

            pp[cnt++]=node(dx[i],dy[i][j]);

        }

    }

    pp[cnt++]=node(10,5);

    for(i=0;i<cnt;i++)

    {

        for(j=i+1;j<cnt;j++)

        {

            dis[i][j]=dis[j][i]=INF;

            if(pp[i].x==pp[j].x)continue;

            if(!isok(pp[i],pp[j]))continue;

            dis[i][j]=dis[j][i]=d(pp[i],pp[j]);

          //  cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;

        }

    }

    return 1;

}

double dd[80];

bool inq[80];

double solve()

{

    int u,v;

    memset(dd,127,sizeof(dd));

    memset(inq,0,sizeof(inq));

    queue<int> q;

    q.push(0);

    dd[0]=0;

    double t;

    while(!q.empty())

    {

        v=q.front();q.pop();

        inq[v]=0;

        for(u=0;u<cnt;u++)

           if(dd[u]>(t=dd[v]+dis[v][u]))

           {

               dd[u]=t;

               if(inq[u])continue;

               q.push(u);inq[u]=1;

           }

    }

    return dd[cnt-1];

}

int main()

{

   while(input())

   {

       printf("%.2f\n",solve());

   }

}