#include <cstdio>
#define N ((1<<21)+10)
int h,n,la,i;
int a[N*2],b[N];
void dfs(int s)
{
	if(s>n) return;
	dfs(s*2);
	dfs(s*2+1);
	if(s%2 && s!=1) a[++la]=b[s]-1;
	a[++la]=b[s];
}
int search(int l,int r,int x)
{
	int mid;
	while (l<r)
	{
		mid=(l+r)>>1;
		if(b[mid]>x) r=mid;
		else l=mid+1;
	}
	return l;
}
int main ()
{scanf("%d",&h);
	n=1;
	while (scanf("%d",&b[n])!=-1) n++;
	n--;
	dfs(1);
	b[0]=1;
	b[1]=a[1];
	for(i=2;i<=la;i++)
	{
		if(a[i]>=b[b[0]]) b[++b[0]]=a[i];
		else b[search(1,b[0],a[i])]=a[i];
	}
	printf("%d\n",la-b[0]);
	
	return 0;
}