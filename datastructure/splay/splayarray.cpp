/*
    插入:INSERT pos n c1...cn (pos后面插入n个数字)
    删除:DELETE pos n (删除pos开始的n个数字)
    修改:MAKE-SAME pos n c (pos开始的n个数字修改为c)
    翻转:REVERSE pos n (pos开始的n个数字翻转)
    求和:GET-SUM pos n (pos开始的n个数字求和)
    求和最大的子序列:MAX-SUM (整个区间的和最大的子序列)
*/
#define INF 2000000000
#define N 500010
int n,m;		int num[N];
struct SplayTree
{
	void rotate(int x,int f)//旋转
	{
		int y=pre[x],z=pre[y];
		push_down(y);		push_down(x);
		ch[y][!f]=ch[x][f];		pre[ch[x][f]]=y;
		ch[x][f]=y;		pre[y]=x;		pre[x]=z;
		if(pre[x]) ch[z][ch[z][1]==y]=x;
		push_up(y);
	}
	void splay(int x,int goal)//把x节点转到goal下面，goal为0表示转到根
	{
		push_down(x);
		while (pre[x]!=goal)
		{
			if(pre[pre[x]]==goal) rotate(x,ch[pre[x]][0]==x);
			else
			{
				int y=pre[x],z=pre[y];		int f=(ch[z][0]==y);
				if(ch[y][f]==x) rotate(x,!f);		else rotate(y,f);
				rotate(x,f);
			}
		}
		push_up(x);
		if(goal==0)root=x;
	}
	void rotateto(int k,int goal)//把第k位转到goal下面
	{
		int x=root;		push_down(x);
		while (sz[ch[x][0]]!=k)
		{
			if(k<sz[ch[x][0]]) x=ch[x][0];
			else{	k-=sz[ch[x][0]]+1;	x=ch[x][1];		}
			push_down(x);
		}
		splay(x,goal);
	}
	//以上函数基本不用变
	void clear()
	{
		ch[0][0]=ch[0][1]=pre[0]=sz[0]=0;
		root=n=0;
		val[0]=ls[0]=rs[0]=ss[0]=-INF;
		sum[0]=0;	lzy1[0]=0;	lzy2[0]=-INF;
		newnode(root,-INF);		newnode(ch[root][1],-INF);
		pre[n]=root;		sz[root]=2;
	}
	void newnode(int &x,int c)
	{
		if (top) x=pool[--top];
		else x=++n;
		ch[x][0]=ch[x][1]=pre[x]=0;		sz[x]=1;
		val[x]=ls[x]=rs[x]=ss[x]=sum[x]=c;
		lzy1[x]=0;		lzy2[x]=-INF;
	}
	void push_up(int x)
	{
		int lx=ch[x][0],rx=ch[x][1];
		sz[x]=1+sz[lx]+sz[rx];
		sum[x]=val[x]+sum[lx]+sum[rx];
		ls[x]=max(ls[lx],sum[lx]+val[x]+max(0,ls[rx]));
		rs[x]=max(rs[rx],sum[rx]+val[x]+max(0,rs[lx]));
		ss[x]=max(0,rs[lx])+val[x]+max(0,ls[rx]);
		ss[x]=max(ss[x],max(ss[lx],ss[rx]));
	}
	void update_rev(int x)
	{		if(! x) return;	swap(ch[x][0],ch[x][1]);		swap(ls[x],rs[x]);	lzy1[x]^=1;	}
	void update_same(int x,int v)
	{
		if(! x) return;		val[x]=v;		sum[x]=v*sz[x];
		ss[x]=ls[x]=rs[x]=max(v,v*sz[x]);		lzy2[x]=v;
	}
	void push_down(int x)
	{
		if(lzy1[x]){	update_rev(ch[x][0]);	update_rev(ch[x][1]);	lzy1[x]=0;	}
		if(lzy2[x]!=-INF)
		{
			update_same(ch[x][0],lzy2[x]);
			update_same(ch[x][1],lzy2[x]);
			lzy2[x]=-INF;
		}
	}
	void init(int pos,int tot)
	{
		clear();		cnt=tot;		top=0;
		rotateto(pos,0);		rotateto(pos+1,root);
		build(ch[ch[root][1]][0],1,tot,ch[root][1]);
		push_up(ch[root][1]);		push_up(root);
	}
	void build(int &x,int l,int r,int f)
	{
		if(l>r) return;		push_down(f);		int mid=(l+r)>>1;
		newnode(x,num[mid]);
		build(ch[x][0],l,mid-1,x);		build(ch[x][1],mid+1,r,x);
		pre[x]=f;		push_up(x);
	}
	void ins(int pos,int len)
	{
		cnt+=len;		rotateto(pos,0);		rotateto(pos+1,root);
		build(ch[ch[root][1]][0],1,len,ch[root][1]);
		push_up(ch[root][1]);		push_up(root);
	}
	void erase(int x)
	{		if(!x) return;	pool[top++]=x;	erase(ch[x][0]);	erase(ch[x][1]);	}
	void del(int l,int r)
	{
		rotateto(l-1,0);		rotateto(r+1,root);		int key=ch[ch[root][1]][0];
		ch[ch[root][1]][0]=0;		cnt-=sz[key];		erase(key);
		push_up(ch[root][1]);		push_up(root);
	}
	void change(int l,int r,int c)
	{
		rotateto(l-1,0);		rotateto(r+1,root);		int key=ch[ch[root][1]][0];
		update_same(key,c);		push_up(ch[root][1]);		push_up(root);
	}
	void flip(int l,int r)
	{
		rotateto(l-1,0);		rotateto(r+1,root);
		int key=ch[ch[root][1]][0];		update_rev(key);
	}
	int get_sum(int l,int r)
	{
		rotateto(l-1,0);		rotateto(r+1,root);
		int key=ch[ch[root][1]][0];		return sum[key];
	}
	int max_sum()
	{
		rotateto(0,0);		rotateto(cnt+1,root);
		int key=ch[ch[root][1]][0];		return ss[key];
	}
	int root,n,cnt,top;
	int ch[N][2],pre[N],sz[N];
	int val[N],sum[N],ls[N],rs[N],ss[N];
	bool lzy1[N];
	int lzy2[N];
	int pool[N];
}spl;
int main ()
{
	 int tt;	 int i,j,t;	 int a,b,c;	 char op[30];
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
