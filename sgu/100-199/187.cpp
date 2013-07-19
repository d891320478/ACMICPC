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
#define SET(a,b) memset(a,b,sizeof(a))
#define N 130010
#define M 10010
struct splaytree
{
    void rotate(int x,int f)
    {
        int y=pre[x],z=pre[y];
        push_down(y);
        push_down(x);
        ch[y][!f]=ch[x][f];
        pre[ch[x][f]]=y;
        ch[x][f]=y;
        pre[y]=x;
        pre[x]=z;
        if(pre[x]) ch[z][ch[z][1]==y]=x;
        push_up(y);
    }
    void splay(int x,int goal)
    {
        push_down(x);
        while (pre[x]!=goal)
        {
            if(pre[pre[x]]==goal) rotate(x,ch[pre[x]][0]==x);
            else
            {
                int y=pre[x],z=pre[y];
                int f=(ch[z][0]==y);
                if(ch[y][f]==x) rotate(x,!f);
                else rotate(y,f);
                rotate(x,f);
            }
        }
        push_up(x);
        if(goal==0) root=x;
    }
    void rotateto(int k,int goal)
    {
        int x=root;
        push_down(x);
        while (sz[ch[x][0]]!=k)
        {
            if(k<sz[ch[x][0]]) x=ch[x][0];
            else
            {
                k-=sz[ch[x][0]]+1;
                x=ch[x][1];
            }
            push_down(x);
        }
        splay(x,goal);
    }
    void clear()
    {
        flag=0;
        ch[0][0]=ch[0][1]=pre[0]=sz[0]=0;
        root=n=0;
        val[0]=lzy[0]=0;
        newnode(root,-INF);
        newnode(ch[root][1],-INF);
        pre[n]=root;
        sz[root]=2;
    }
    void newnode(int &x,int c)
    {
        x=++n;
        ch[x][0]=pre[x]=ch[x][1]=0;
        sz[x]=1;
        val[x]=c;
        lzy[x]=0;
    }
    void push_up(int x)
    {
        sz[x]=sz[ch[x][0]]+1+sz[ch[x][1]];
    }
    void push_down(int x)
    {
        if(lzy[x])
        {
            int l=ch[x][0],r=ch[x][1];
            if(l) lzy[l]^=1;
            if(r) lzy[r]^=1;
            swap(ch[x][0],ch[x][1]);
            lzy[x]=0;
        }
    }
    void build(int &x,int l,int r,int f)
    {
        if(l>r) return;
        push_down(f);
        int mid=(l+r)>>1;
        newnode(x,mid);
        build(ch[x][0],l,mid-1,x);
        build(ch[x][1],mid+1,r,x);
        pre[x]=f;
        push_up(x);
    }
    void init(int n)
    {
        clear();
        build(ch[ch[root][1]][0],1,n,ch[root][1]);
        push_up(ch[root][1]);
        push_up(root);
    }
    void flip(int l,int r)
    {
        rotateto(l-1,0);
        rotateto(r+1,root);
        lzy[ch[ch[root][1]][0]]^=1;
    }
    void print(int rt)
    {
        push_down(rt);
        if(ch[rt][0]) print(ch[rt][0]);
        if(val[rt]>0)
        {
            if(! flag) flag=1;
            else printf(" ");
            printf("%d",val[rt]);
        }
        if(ch[rt][1]) print(ch[rt][1]);
    }
    int ch[N][2],sz[N],val[N],pre[N],lzy[N],root,n,flag;
}spl;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    spl.init(n);
    while (m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        spl.flip(l,r);
    }
    spl.print(spl.root);
    printf("\n");
    
    return 0;
}
