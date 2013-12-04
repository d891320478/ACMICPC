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
#include<ctime>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 30010
#define M 10010
int m;
int pnt[N],dis[N],cnt[N];
char s[5];
int x,y;
int find(int x)
{
    if(x==pnt[x]) return pnt[x];
    int y=pnt[x];
    pnt[x]=find(pnt[x]);
    dis[x]+=dis[y];
    return pnt[x];
}
int main()
{
    while (scanf("%d",&m)!=-1)
    {
        for(int i=1;i<=30000;i++)
        {
            pnt[i]=i;
            dis[i]=0;
            cnt[i]=1;
        }
        while (m--)
        {
            scanf("%s",s);
            if(s[0]=='M')
            {
                scanf("%d %d",&x,&y);
                x=find(x);
                y=find(y);
                pnt[y]=x;
                dis[y]=cnt[x];
                cnt[x]+=cnt[y];
            }
            else
            {
                scanf("%d",&x);
                y=find(x);
                //printf(" %d\n",y);
                printf("%d\n",cnt[y]-1-dis[x]);
            }
        }
    }
    return 0;
}