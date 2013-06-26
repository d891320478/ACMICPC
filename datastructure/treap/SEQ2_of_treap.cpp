#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
int rands()
{
	static int x=1364684679;
	x+=(x<<2)+1;
	return x;
}
#define INF 2000000000
#define N 500010
struct Node;
Node *null,*root;
struct Node
{
    int w,sz,val,sum,ls,rs,ss,lzy1,lzy2;
    Node *lft,*rht;
    void split(int,Node*&,Node*&);
    void same(int v)
    {
        if(this==null) return;
        lzy2=val=v;
        sum=v*sz;
        ls=rs=ss=max(sum,v);
    }
    void rev()
    {
        if(this==null) return;
        lzy1^=1;
        swap(lft,rht);
        swap(ls,rs);
    }
    Node *pushup()
    {
        sz=lft->sz+1+rht->sz;
        sum=lft->sum+val+rht->sum;
  
        ls=max(lft->ls,lft->sum+val+max(0,rht->ls));
        rs=max(rht->rs,rht->sum+val+max(0,lft->rs));
  
        ss=max(0,lft->rs)+val+max(0,rht->ls);
        ss=max(ss,max(lft->ss,rht->ss));
  
        return this;
    }
    Node *pushdown()
    {
        if(lzy1)
        {
            lft->rev();
            rht->rev();
            lzy1=0;
        }
        if(lzy2!=-INF)
        {
            lft->same(lzy2);
            rht->same(lzy2);
            lzy2=-INF;
        }
        return this;
    }
};
Node *merge(Node *p,Node *q)
{
    if(p==null) return q;
    if(q==null) return p;
    if(p->w<q->w)
    {
        p->pushdown();
        p->rht=merge(p->rht,q);
        return p->pushup();
    }
    q->pushdown();
    q->lft=merge(p,q->lft);
    return q->pushup();
}
void Node::split(int need,Node *&p,Node *&q)
{
    if(this==null)
    {
    	p=q=null;
    	return;
    }
    pushdown();
    if(lft->sz>=need)
    {
        lft->split(need,p,q);
        lft=null;
        pushup();
        q=merge(q,this);
        return;
    }
    rht->split(need-(lft->sz+1),p,q);
    rht=null;
    pushup();
    p=merge(this,p);
    return;
}
Node data[N],*pool[N];
int top,cnt;
Node* newnode(int c)
{
    Node *x;
    if(top) x=pool[top--];
    else x=&data[cnt++];
    x->lft=x->rht=null;
    x->sz=1; x->lzy1=0; x->lzy2=-INF;
    x->val=x->sum=x->ls=x->rs=x->ss=c;
    x->w=rands();
    return x;
}
void init()
{
    //srand((unsigned long long)time(0));
    cnt=1; top=0;
    null=&data[0];
    null->sz=null->sum=0;
    null->val=null->ls=null->rs=null->ss=-INF;
    null->lzy1=0;
    null->lzy2=-INF;
    null->lft=null->rht=null;
}
//---------------------------------------------------------
void erase(Node *rt)
{
    if(rt==null) return;
    erase(rt->lft);
    erase(rt->rht);
    pool[++top]=rt;
}
int n,m;
char ord[20];
int a,b,c;
int main ()
{
init();
        root=null;
        n=fastget();
        m=fastget();
        for(int i=0;i<n;i++)
        {
            a=fastget();
            root=merge(root,newnode(a));
        }
        while (m--)
        {
            scanf("%s",ord);
            Node *p,*q,*r,*s;
            if(ord[0]=='I')
            {
                a=fastget();
                n=fastget();
                root->split(a,p,q);
                for(int i=0;i<n;i++)
                {
                    b=fastget();
                    p=merge(p,newnode(b));
                }
                root=merge(p,q);
            }else if(ord[0]=='D')
            {
                a=fastget();
                b=fastget();
                b=a+b-1;
                root->split(a-1,p,q);
                q->split(b-a+1,r,s);
                erase(r);
                root=merge(p,s);
            }else if(ord[0]=='M' && ord[2]=='K')
            {
                a=fastget();
                b=fastget();
                c=fastget();
                b=b+a-1;
                root->split(a-1,p,q);
                q->split(b-a+1,r,s);
                r->same(c);
                root=merge(p,merge(r,s));
            }else if(ord[0]=='R')
            {
                a=fastget();
                b=fastget();
                b=b+a-1;
                root->split(a-1,p,q);
                q->split(b-a+1,r,s);
                r->rev();
                root=merge(p,merge(r,s));
            }else if(ord[0]=='G')
            {
                a=fastget();
                b=fastget();
                b=a+b-1;
                root->split(a-1,p,q);
                q->split(b-a+1,r,s);
                fastput(r->sum);
                root=merge(p,merge(r,s));
            }
            else if(ord[0]=='M') fastput(root->ss);
        }
     
    return 0;
}
