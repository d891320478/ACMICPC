//http://acm.buaa.edu.cn:4567/problems/26
#define N 15
#define M 2
int m;	char s[N];
struct trie
{ int m,x;	trie *p[M];
  void clear(){	for(int i=0;i<M;i++) p[i]=NULL; m=x=0;	}
}*root;
void ins(trie *head,int i)
{	if(! s[i])
	{
		(head->m)++; head->x=head->m;
		for(int i=0;i<M;i++) if(head->p[i]) head->x+=head->p[i]->x;
		return;
	}
	if(! head->p[s[i]-'a'])
	{ head->p[s[i]-'a']=(trie*)malloc(sizeof(trie));
	  head->p[s[i]-'a']->clear();
	}
	ins(head->p[s[i]-'a'],i+1);
	head->x=head->m;
	for(int i=0;i<M;i++)
		if(head->p[i]) head->x+=head->p[i]->x;
}
trie* find(trie *head)
{
	for(int i=1;s[i];i++)
		if(head->p[s[i]-'a']) head=head->p[s[i]-'a'];
		else return NULL;
	return head;
}
int main()
{    root=(trie*)malloc(sizeof(trie));
     root->clear();
     scanf("%d",&m);	getchar();
     while (m--)
     { gets(s); trie *head=root;
       if(s[0]=='+') ins(head,1);
       else
       { trie *u=find(head); if(u) printf("%d\n",u->x); else printf("0\n"); }
	return 0;
}
