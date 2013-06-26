/*
    插入:INSERT pos n c1...cn (pos后面插入n个数字)
    删除:DELETE pos n (删除pos开始的n个数字)
    修改:MAKE-SAME pos n c (pos开始的n个数字修改为c)
    翻转:REVERSE pos n (pos开始的n个数字翻转)
    求和:GET-SUM pos n (pos开始的n个数字求和)
    求和最大的子序列:MAX-SUM (整个区间的和最大的子序列)
*/
#define INF 1<<30
#define N 500010
int n,m;			int num[N];
struct node{	node *ch[2],*pre;	int sz,val,sum,ls,rs,ss;	bool lzy1;	int lzy2;	};
struct SplayTree
{
	node *root,*null,*pool[N],data[N];		int n,cnt,top;
	void rotate(node *x,int f)//旋转
	{
		node *y=x->pre,*z=y->pre;
		push_down(y);		push_down(x);
		y->ch[!f]=x->ch[f];		x->ch[f]->pre=y;
		x->ch[f]=y;		y->pre=x;		x->pre=z;
		if(x->pre!=null) z->ch[z->ch[1]==y]=x;
		push_up(y);
	}
	void splay(node *x,node *goal)//把x节点转到goal下面，goal为0表示转到根
	{
		push_down(x);
		while (x->pre!=goal)
		{
			if(x->pre->pre==goal) rotate(x,x->pre->ch[0]==x);
			else
			{
				node *y=x->pre,*z=y->pre;			int f=(z->ch[0]==y);
				if(y->ch[f]==x) rotate(x,!f);			else rotate(y,f);
				rotate(x,f);
			}
		}
		push_up(x);
		if(goal==null) root=x;
	}
	void rotateto(int k,node *goal)//把第k位转到goal下面
	{
		node *x=root;		push_down(x);
		while (x->ch[0]->sz!=k)
		{
			if(k<x->ch[0]->sz) x=x->ch[0];
			else{	k-=x->ch[0]->sz+1;		x=x->ch[1];		}
			push_down(x);
		}
		splay(x,goal);
	}
	//以上函数基本不用变
	void clear()
	{
		n=top=0;
		null=newnode(-INF);		null->sz=null->sum=0;
		null->val=null->ls=null->rs=null->ss=-INF;
		null->lzy1=0;		null->lzy2=-INF;
		root=newnode(-INF);		root->ch[1]=newnode(-INF);    	root->ch[1]->pre=root;
		root->sz=2;
	}
	node *newnode(int c)
	{
		node *x;
		if (top) x=pool[top--];		else x=&data[n++];
		x->ch[0]=x->ch[1]=x->pre=null;		x->sz=1;
		x->val=x->ls=x->rs=x->ss=x->sum=c;
		x->lzy1=0;		x->lzy2=-INF;
		return x;
	}
	void push_up(node *x)
	{
		node *lx=x->ch[0],*rx=x->ch[1];
		
		x->sz=1+lx->sz+rx->sz;
		x->sum=x->val+lx->sum+rx->sum;
		
		x->ls=max(lx->ls,lx->sum+x->val+max(0,rx->ls));
		x->rs=max(rx->rs,rx->sum+x->val+max(0,lx->rs));
		
		x->ss=max(0,lx->rs)+x->val+max(0,rx->ls);
		x->ss=max(x->ss,max(lx->ss,rx->ss));
	}
	void update_rev(node *x)
	{
		if(x==null) return;		swap(x->ch[0],x->ch[1]);		swap(x->ls,x->rs);
		x->lzy1^=1;
	}
	void update_same(node *x,int v)
	{
		if(x==null) return;
		x->val=v;		x->sum=v*x->sz;		x->ss=x->ls=x->rs=max(v,v*x->sz);
		x->lzy2=v;
	}
	void push_down(node *x)
	{
		if(x->lzy1)
		{	update_rev(x->ch[0]);		update_rev(x->ch[1]);		x->lzy1=0;	}
		if(x->lzy2!=-INF)
		{
			update_same(x->ch[0],x->lzy2);
			update_same(x->ch[1],x->lzy2);
			x->lzy2=-INF;
		}
	}
	void init(int pos,int tot)
	{
		clear();		cnt=tot;		rotateto(pos,null);		rotateto(pos+1,root);
		root->ch[1]->ch[0]=build(1,tot,root->ch[1]);
		push_up(root->ch[1]);		push_up(root);
	}
	node *build(int l,int r,node *f)
	{
		if(l>r) return null;		push_down(f);		int mid=(l+r)>>1;
		node *x=newnode(num[mid]);
		x->ch[0]=build(l,mid-1,x);		x->ch[1]=build(mid+1,r,x);
		x->pre=f;		push_up(x);		return x;
	}
	void ins(int pos,int len)
	{
		cnt+=len;		rotateto(pos,null);		rotateto(pos+1,root);
		root->ch[1]->ch[0]=build(1,len,root->ch[1]);
		push_up(root->ch[1]);		push_up(root);
	}
	void erase(node *x)
	{		if(x==null) return;	pool[++top]=x;	erase(x->ch[0]);	erase(x->ch[1]);	}
	void del(int l,int r)
	{
		rotateto(l-1,null);		rotateto(r+1,root);		node *key=root->ch[1]->ch[0];
		root->ch[1]->ch[0]=null;		cnt-=key->sz;		erase(key);
		push_up(root->ch[1]);		push_up(root);
	}
	void change(int l,int r,int c)
	{
		rotateto(l-1,null);		rotateto(r+1,root);
		node *key=root->ch[1]->ch[0];
		update_same(key,c);		push_up(root->ch[1]);		push_up(root);
	}
	void flip(int l,int r)
	{
		rotateto(l-1,null);		rotateto(r+1,root);
		node *key=root->ch[1]->ch[0];		update_rev(key);
	}
	int get_sum(int l,int r)
	{
		rotateto(l-1,null);		rotateto(r+1,root);
		node *key=root->ch[1]->ch[0];
		return key->sum;
	}
	int max_sum()
	{
		rotateto(0,null);		rotateto(cnt+1,root);
		node *key=root->ch[1]->ch[0];		return key->ss;
	}
	void print(node *x)
	{
		if(x->ch[0]!=null) print(x->ch[0]);
		printf("%d ",x->val);
		if(x->ch[1]!=null) print(x->ch[1]);
	}
}spl;
int main ()
{
	 int tt;	 	int i,j,t;		 int a,b,c;		 char op[30];
	 scanf("%d",&tt);
	 while (tt--)
	 {
	 	scanf("%d%d",&n,&m);
	 	for(i=1;i<=n;i++) scanf("%d",&num[i]);
	 	spl.init(0,n);
	 	while (m--)
	 	{
	 		scanf("%s",op);
	 		if(op[0]=='I')
	 		{
	 			scanf("%d%d",&a,&n);
	 			for(i=1;i<=n;i++) scanf("%d",&num[i]);
	 			spl.ins(a,n);
	 		}else	if(op[0]=='D')
	 		{
	 			scanf("%d%d",&a,&b);
	 			spl.del(a,a+b-1);
	 		}else	if(op[0]=='M' && op[2]=='K')
	 		{
	 			scanf("%d%d%d",&a,&b,&c);
	 			spl.change(a,a+b-1,c);
	 		}else	if(op[0]=='R')
	 		{
	 			scanf("%d%d",&a,&b);
	 			spl.flip(a,a+b-1);
	 		}else	if(op[0]=='G')
	 		{
	 			scanf("%d%d",&a,&b);
	 			printf("%d\n",spl.get_sum(a,a+b-1));
	 		}
	 		else if(op[0]=='M') printf("%d\n",spl.max_sum());
	 	}
	 }
	return 0;
}
