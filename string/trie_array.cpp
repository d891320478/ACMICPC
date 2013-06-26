#define N 100010
#define M 12
int trie[N][M],lt,end[N],root;	char s[M];
int newnode(){ int nw=lt; lt++; return nw; }
void init()
{ memset(trie,0,sizeof(trie)); memset(end,0,sizeof(end)); lt=0; root=newnode();}
void insert(char *buf)
{	int now=root,l=strlen(buf);
	for(int i=0;i<l;i++)
	{		if(! trie[now][buf[i]-'0']) trie[now][buf[i]-'0']=newnode();
			now=trie[now][buf[i]-'0'];
	}
	end[now]=1;
}
