#include <cstdio>
#include <cstdlib>
#include <cstring>
struct tree
{
	char t[40];
	int a;
	tree *l,*r;
}*head,*p;
int n=1;
char s[40];
void tr(tree *q)
{
	if(q->l!=NULL)tr(q->l);
	printf("%s %.4f\n",q->t,(q->a)*100.0/n);
	if(q->r!=NULL)tr(q->r);
}
int main ()
{

	gets(s);
	head=(tree *)malloc(sizeof(tree));
	strcpy(head->t,s);
	head->a=1;
	head->l=head->r=NULL;
	while (gets(s)!=NULL)
	{
		n++;
		p=head;
		while(p!=NULL)
		{
			int f=strcmp(p->t,s);
			if(f==0)
			{
				(p->a)++;
				break;
			}
			else
			if(f==1)
			{
				if(p->l)p=p->l;
				else
				{
					p->l=(tree *)malloc(sizeof(tree));
					p=p->l;
					strcpy(p->t,s);
					p->a=1;
					p->l=p->r=NULL;
					break;
				}
			}
			else
			{
				if(p->r)p=p->r;
				else
				{
					p->r=(tree *)malloc(sizeof(tree));
					p=p->r;
					strcpy(p->t,s);
					p->a=1;
					p->l=p->r=NULL;
					break;
				}
			}
		}
	}
	tr(head);
	
	return 0;
}