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
#include<vector>
#include<utility>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 100010
int fastget()
{
	char c; int ans=0; c=getchar();
	int sign=1;
	while (! (c>='0' && c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while (c>='0' && c<='9')
	{
		ans=(ans<<3)+(ans<<1)+c-'0';
		c=getchar();
	}
	return ans*sign;
}
void fastput(int x)
{
	char s[12]; int a=0;
	if(x==0) puts("0");
	else
	{
		if(x<0) putchar('-'),x=-x;
		while (x) { s[a++]=x%10+'0'; x/=10; }
		for(a--;a>=0;a--) putchar(s[a]);
		putchar('\n');
	}
}
struct treap
{
    int key,wht,count,sz,ch[2];
}tp[N*2];
int nodecount,root;
void init()
{
    tp[0].sz=0;
    tp[0].wht=-INF;
    nodecount=0;
    root=0;
}
void update(int x)
{
    tp[x].sz=tp[tp[x].ch[0]].sz+tp[x].count+tp[tp[x].ch[1]].sz;
}
void rotate(int &x,int t)
{
    int y=tp[x].ch[t];
    tp[x].ch[t]=tp[y].ch[!t];
    tp[y].ch[!t]=x;
    update(x);
    update(y);
    x=y;
}
void insert(int &x,int t)
{
    if(! x)
    {
        x=++nodecount;
        tp[x].key=t;
        tp[x].wht=rand();
        tp[x].count=1;
        tp[x].ch[0]=tp[x].ch[1]=0;
    }
    else if(tp[x].key==t)  tp[x].count++;
    else
    {
        int k=tp[x].key<t;
        insert(tp[x].ch[k],t);
        if(tp[x].wht<tp[tp[x].ch[k]].wht) rotate(x,k);
    }
    update(x);
}
void erase(int &x,int t)
{
    if(tp[x].key==t)
    {
        if(tp[x].count==1)
        {
            if(! tp[x].ch[0] && ! tp[x].ch[1])
            {
                x=0;
                return;
            }
            rotate(x,tp[tp[x].ch[0]].wht<tp[tp[x].ch[1]].wht);
            erase(x,t);
        }
        else tp[x].count--;
    }
    else erase(tp[x].ch[tp[x].key<t],t);
    update(x);
}
int getmin(int rt)
{
	if(tp[rt].ch[0]) return getmin(tp[rt].ch[0]);
	return tp[rt].key;
}
int n,m;
int a[N],f[N],q[N],head,tail;
int main()
{
	init();
	n=fastget();
	m=fastget();
	int flag=1;
	for(int i=1;i<=n;++i)
	{
		a[i]=fastget();
		if(a[i]>m) flag=0;
	}
	if(! flag)
	{
		printf("-1\n");
		return 0;
	}
	head=f[0]=0;
	tail=-1;
	for(int i=1,sum=0,p=1;i<=n;++i)
	{
		sum+=a[i];
		while(sum>m) sum-=a[p++];
		while(head<=tail && q[head]<p)
		{
			if(head<tail) erase(root,f[q[head]]+a[q[head]+1]);
			++head;
		}
		while(head<=tail && a[i]>=a[q[tail]])
		{
			if(head<tail) erase(root,f[q[tail]-1]+a[q[tail]]);
			--tail;
		}
		q[++tail]=i;
		//printf("%d %d\n",head,tail);
		if(head<tail) insert(root,f[q[tail]-1]+a[q[tail]]);
		f[i]=a[q[head]]+f[p-1];
		//printf("%d\n",f[i]);
		if(head<tail) f[i]=min(f[i],getmin(root));
	}
	printf("%d\n",f[n]);
	return 0;
}