//POJ 3648
#define N 100
#define M 10010
int n,m;
int head[N],next[M],e[M],cnt;
int nhead[N],nnext[M],ne[M],ncnt;
int shead[N],snext[M],se[M],scnt;
int dfn[N],low[N],tot,step,point,ins[N],stack[N];
int into[N],color[N],color2[N];
void addedge(int *head,int *next,int *e,int *cnt,int u,int v)
{	next[*cnt]=head[u]; e[*cnt]=v; head[u]=(*cnt)++;	}
void tarjan(int s)
{
	int i,j;
	dfn[s]=low[s]=++step;	stack[++tot]=s;		ins[s]=1;
	for(i=head[s];i!=-1;i=next[i])
	{
		if(! dfn[e[i]])
		{	tarjan(e[i]);	low[s]=low[s]<low[e[i]]?low[s]:low[e[i]];	}
		else if(ins[e[i]]) low[s]=low[s]<dfn[e[i]]?low[s]:dfn[e[i]];
	}
	if(dfn[s]==low[s])
	{
		do{		j=stack[tot--]; color[j]=point; ins[j]=0;		} while (j!=s);
		point++;
	}
}
bool twosat(int n)
{
	for(int i=0;i+1<n;i+=2)	if(color[i]==color[i+1]) return 0;
	return 1;
}
void COLOR(int s)
{
	color2[s]=1;
	for(int i=nhead[s];i!=-1;i=nnext[i])
		if(color2[ne[i]]==-1) COLOR(ne[i]);		
}
void findans(int n)
{
	memset(into,0,sizeof(into));
	memset(color2,-1,sizeof(color2));
	memset(shead,-1,sizeof(shead));
	scnt=0;
	for(int i=0;i<n;i++)	addedge(shead,snext,se,&scnt,color[i],i);
	ncnt=0;	memset(nhead,-1,sizeof(nhead));
	for(int i=0;i<n;i++)
	for(int j=head[i];j!=-1;j=next[j])
		if(color[i]!=color[e[j]])
		{	addedge(nhead,nnext,ne,&ncnt,color[e[j]],color[i]);	into[color[i]]++;		}
	queue<int> Q;
	for(int i=0;i<point;i++)	if(into[i]==0) Q.push(i);
	while (! Q.empty())
	{
		int x=Q.front();		Q.pop();
		if(color2[x]!=-1)continue;		color2[x]=0;
		for(int i=nhead[x];i!=-1;i=nnext[i])
		{	into[ne[i]]--;	if(into[ne[i]]==0) Q.push(ne[i]);	}
		for(int i=shead[x];i!=-1;i=snext[i])
			if(color2[color[se[i]^1]]==-1)	COLOR(color[se[i]^1]);
	}
	memset(color,0,sizeof(color));
	for(int i=0;i<point;i++)	if(color2[i]==1)
	for(int j=shead[i];j!=-1;j=snext[j])	color[se[j]]=1;
	bool flag=0;
	for(int i=2;i<n;i++)
		if(color[i]==0)
		{
			if(flag) printf(" ");	else flag=1;
			printf("%d",i/2);	if(i%2)printf("w");	else printf("h");
		}
	printf("\n");
}
int main ()
{
	while (scanf("%d%d",&n,&m) && (n || m))
	{
		cnt=0;		memset(head,-1,sizeof(head));
		addedge(head,next,e,&cnt,0,1);
		while (m--)
		{
			int u,v; char a,b;
			scanf("%d%c %d%c",&u,&a,&v,&b);
			if(a=='h')u=u*2+1;			else u=u*2;
			if(b=='h')v=v*2+1;			else v=v*2;
			addedge(head,next,e,&cnt,u,v^1);
			addedge(head,next,e,&cnt,v,u^1);
		}
		point=tot=step=0;
		memset(dfn,0,sizeof(dfn));
		for(int i=0;i<2*n;i++)	if(! dfn[i]) tarjan(i);
		if(twosat(n*2)) findans(n*2);
		else printf("bad luck\n");
	}
	return 0;
}
