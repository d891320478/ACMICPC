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
#define ID(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 100010
#define M 10010
int id(int l,int r){ return l+r | l!=r; }
int tree[N<<1];
struct treap{ int key,wht,count,sz,ch[2]; }tp[N*30];
int nodecount;
void init(){ tp[0].sz=0; tp[0].wht=-INF; tp[0].key=-1; nodecount=0; }
void update(int x)
{ tp[x].sz=tp[tp[x].ch[0]].sz+tp[x].count+tp[tp[x].ch[1]].sz; }
void rotate(int &x,int t)
{ int y=tp[x].ch[t]; tp[x].ch[t]=tp[y].ch[!t]; tp[y].ch[!t]=x;
  update(x); update(y); x=y;
}
void insert(int &x,int t)
{   if(! x)
    { x=++nodecount; tp[x].key=t; tp[x].wht=rand(); tp[x].count=1;
      tp[x].ch[0]=tp[x].ch[1]=0;
    }else if(tp[x].key==t) tp[x].count++;
    else
    { int k=tp[x].key<t; insert(tp[x].ch[k],t);
      if(tp[x].wht<tp[tp[x].ch[k]].wht) rotate(x,k);
    }
    update(x);
}
int select(int x,int k)
{   if(! x) return 0;
    if(k<tp[x].key) return select(tp[x].ch[0],k);
    int q=0,p=tp[tp[x].ch[0]].sz+tp[x].count;
    if(k>tp[x].key) q=select(tp[x].ch[1],k);
    return p+q;
}
int a[N],n,m,ans;
void treeinsert(int l,int r,int i,int x)
{   insert(tree[id(l,r)],x); if(l==r) return; int m=(l+r)>>1;
    if(i<=m) treeinsert(l,m,i,x); if(i>m) treeinsert(m+1,r,i,x);
}
void query(int l,int r,int L,int R,int x)
{   if(L<=l && R>=r){ ans+=select(tree[id(l,r)],x); return; }
    int m=(l+r)>>1; if(L<=m) query(l,m,L,R,x); if(R>m) query(m+1,r,L,R,x);
}
int main()
{
	int mn=INF,mx=-INF;
    while (scanf("%d%d",&n,&m)!=-1)
    { init(); memset(tree,0,sizeof(tree));
      for(int i=1;i<=n;i++){ scanf("%d",&a[i]); treeinsert(1,n,i,a[i]); mn=min(a[i],mn); mx=max(a[i],mx); }
      while (m--)
      { int x,y,c;
         scanf("%d %d %d",&x,&y,&c); int l=mn,r=mx;int mid;
          while (l<r)
          { ans=0; mid=(l+r)>>1; query(1,n,x,y,mid);
            if(ans<c) l=mid+1; else r=mid;
          }
          printf("%d\n",l);
       }
    }
    return 0;
}