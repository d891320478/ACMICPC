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
int select(int x,int k)
{
	if(k<=0) return -1;
	if(k<=tp[tp[x].ch[0]].sz) return select(tp[x].ch[0],k);
	if(k<=tp[tp[x].ch[0]].sz+tp[x].count) return tp[x].key;
	return select(tp[x].ch[1],k-tp[tp[x].ch[0]].sz-tp[x].count);
}
