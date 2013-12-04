#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <iostream>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 1000010
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[NN],wb[NN],wv[NN],wss[NN];
int c0(int *r,int a,int b)
{
	return r[a]==r[b] && r[a+1]==r[b+1] && r[a+2]==r[b+2];
}
int c12(int k,int *r,int a,int b)
{
	if(k==2) return r[a]<r[b] || r[a]==r[b] && c12(1,r,a+1,b+1);
	else return r[a]<r[b] || r[a]==r[b] && wv[a+1]<wv[b+1];
}
void sort(int *r,int *a,int *b,int n,int m)
{
	int i;
	for(i=0;i<n;i++) wv[i]=r[a[i]];
	for(i=0;i<m;i++) wss[i]=0;
	for(i=0;i<n;i++) wss[wv[i]]++;
	for(i=1;i<m;i++) wss[i]+=wss[i-1];
	for(i=n-1;i>=0;i--) b[--wss[wv[i]]]=a[i];
}
void dc3(int *r,int *sa,int n,int m)
{
	int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
	r[n]=r[n+1]=0;
	for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;
	sort(r+2,wa,wb,tbc,m);
	sort(r+1,wb,wa,tbc,m);
	sort(r,wa,wb,tbc,m);
	for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++)
		rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
	if(p<tbc) dc3(rn,san,tbc,p);
	else for(i=0;i<tbc;i++) san[rn[i]]=i;
	for(i=0;i<tbc;i++)
		if(san[i]<tb) wb[ta++]=san[i]*3;
	if(n%3==1) wb[ta++]=n-1;
	sort(r,wb,wa,ta,m);
	for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;
	for(i=j=p=0;i<ta && j<tbc;p++)
		sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
	for(;i<ta;p++) sa[p]=wa[i++];
	for(;j<tbc;p++) sa[p]=wb[j++];
}
int rank[NN],height[NN],sa[NN*3],str[NN*3];
void init(char *buf)
{
	int n=strlen(buf),i,j,k;
	memset(str,0,sizeof(str));
	for(i=0;i<n;i++) str[i]=buf[i];
	dc3(str,sa,n+1,128);
	for(i=0;i<n;i++)
	{
		sa[i]=sa[i+1];
		rank[sa[i]]=i;
	}
	for(i=j=k=0;i<n;height[rank[i++]]=k)
		if(rank[i]>0)
		for(k?k--:0,j=sa[rank[i]-1];i+k<n && j+k<n && str[i+k]==str[j+k];k++);
	height[0]=0;
}
int rmq[NN];
char s[NN];
int main()
{
	while (scanf("%s",s))
	{
		if(s[0]=='.') break;
		init(s);
		int n=strlen(s),i;
		/*
		for(int i=0;i<n;i++) printf("%d ",sa[i]); printf("\n");
		for(int i=0;i<n;i++) printf("%d ",rank[i]); printf("\n");
		for(int i=0;i<n;i++) printf("%d ",height[i]); printf("\n");
		*/
		rmq[0]=n;
		for(int i=rank[0]-1;i>=0;i--)
			rmq[sa[i]]=min(rmq[sa[i+1]],height[i+1]);
		for(int i=rank[0]+1;i< n;i++)
			rmq[sa[i]]=min(rmq[sa[i-1]],height[i]);
		//for(int i=0;i<n;i++) printf("%d ",rmq[i]); printf("\n");
		int flag=0;
		for(int i=1;i<=n/2;i++)
		if(n%i==0)
		if(rmq[i]==n-i)
		{
			printf("%d\n",n/i);
			flag=1;
			break;
		}
		if(! flag) printf("%d\n",1);
	}
	return 0;
}