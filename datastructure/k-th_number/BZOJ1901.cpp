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
#define NN 10005
#define NM 10005
#define MM 2500010
int root[NN],a[NN],b[NN+NM],n,q,node,lb,poi;
int ord[NM][4]; int bit[NN];
struct sgtree{ int l,r,s; }tree[MM];
int sta[NM],top;
int fastget()
{
    char c; int ans=0; c=getchar();
    while (! (c>='0' && c<='9')) c=getchar();
    while (c>='0' && c<='9')
    {
        ans=(ans<<3)+(ans<<1)+c-'0';
        c=getchar();
    }
    return ans;
}
int search(int x)
{
    int l=1,r=b[0],mid;
    while (l<=r)
    {
        mid=l+r>>1; if(b[mid]==x) return mid;
        if(b[mid]<x) l=mid+1; else r=mid-1;
    }
}
int build(int l,int r)
{
    int k=++node;
    tree[k].s=0;
    if(l==r)
    {
        tree[k].l=tree[k].r=0;
        return k;
    }
    int mid=l+r>>1;
    if(l<=mid) tree[k].l=build(l,mid);
    if(r>mid) tree[k].r=build(mid+1,r);
    return k;
}
int sum(int x)
{
    int ans=0;
    for(;x;x-=lowbit(x)) ans+=tree[tree[bit[x]].l].s;
    return ans;
}
int query(int x,int y,int l,int r,int k)
{
    if(l==r) return l;
    int ans=sum(y)-sum(x);
    int mid=l+r>>1;
    if(ans>=k)
    {
        for(int i=x;i;i-=lowbit(i)) bit[i]=tree[bit[i]].l;
        for(int i=y;i;i-=lowbit(i)) bit[i]=tree[bit[i]].l;
        return query(x,y,l,mid,k);
    }
    else
    {
        for(int i=x;i;i-=lowbit(i)) bit[i]=tree[bit[i]].r;
        for(int i=y;i;i-=lowbit(i)) bit[i]=tree[bit[i]].r;
        return query(x,y,mid+1,r,k-ans);
    }
}
int update(int rt,int l,int r,int x,int d)
{
    int k;
    if(top) k=sta[--top];
    else k=++node;
    tree[k]=tree[rt];
    tree[k].s+=d;
    if(l==r)
    {
        tree[k].l=tree[k].r=0;
        return k;
    }
    int mid=l+r>>1;
    if(x<=mid)
    {
        if(tree[k].l>poi) sta[top++]=tree[k].l;
        tree[k].l=update(tree[rt].l,l,mid,x,d);
    }
    else
    {
        if(tree[k].r>poi) sta[top++]=tree[k].r;
        tree[k].r=update(tree[rt].r,mid+1,r,x,d);
    }
    return k;
}
int main()
{
        top=node=0;
        lb=n=fastget(); q=fastget();
        for(int i=1;i<=n;i++) b[i]=a[i]=fastget();
        for(int i=1;i<=q;i++)
        {
            char s[3]; scanf("%s",s);
            if(s[0]=='Q'){ ord[i][0]=1; ord[i][1]=fastget(); ord[i][2]=fastget(); ord[i][3]=fastget(); }
            else{ ord[i][0]=2; ord[i][1]=fastget(); b[++lb]=ord[i][2]=fastget(); }
        }
        sort(b+1,b+1+lb); b[0]=1;
        for(int i=2;i<=lb;i++) if(b[i]!=b[b[0]]) b[++b[0]]=b[i];
        for(int i=1;i<=n;i++) a[i]=search(a[i]);
        root[0]=build(1,b[0]); poi=node;
        for(int i=1;i<=n;i++) root[i]=root[0];
        for(int i=1;i<=n;i++)
        for(int x=i;x<=n;x+=lowbit(x))
            root[x]=update(root[x],1,b[0],a[i],1);
        for(int _=1;_<=q;_++)
        {
            if(ord[_][0]==1)
            {
                int u=ord[_][1],v=ord[_][2],w=ord[_][3];
                for(int i=u-1;i;i-=lowbit(i)) bit[i]=root[i];
                for(int i=v;i;i-=lowbit(i)) bit[i]=root[i];
                printf("%d\n",b[query(u-1,v,1,b[0],w)]);
            }
            else
            {
                int u=ord[_][1],w=ord[_][2];
                for(int i=u;i<=n;i+=lowbit(i)) root[i]=update(root[i],1,b[0],a[u],-1);
                a[u]=search(w);
                for(int i=u;i<=n;i+=lowbit(i)) root[i]=update(root[i],1,b[0],a[u],1);
            }
        }
    return 0;
}
