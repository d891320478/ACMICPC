#include <cstdio>
#include <algorithm>
using namespace std;
#define N 10100
int a[6],i,j,k;
int b[N],c[N],d[N];
int b0[N],c0[N],d0[N];
int main()
{
	b[0]=c[0]=0;
	for(i=1;i<=5;i++) scanf("%d",&a[i]);
	for(i=-50;i<=50;i++) if(i!=0)
	for(j=-50;j<=50;j++) if(j!=0)
		b[++b[0]]=a[1]*i*i*i+a[2]*j*j*j;
	for(i=-50;i<=50;i++) if(i!=0)
	for(j=-50;j<=50;j++) if(j!=0)
		c[++c[0]]=a[3]*i*i*i+a[4]*j*j*j;
	for(i=-50;i<=50;i++)
	if(i!=0) d[++d[0]]=a[5]*i*i*i;
	sort(b+1,b+1+b[0]); sort(c+1,c+1+c[0]); sort(d+1,d+1+d[0]);
	for(i=1,j=1;i<=b[0];i++)
		if(b[i]==b[j]) b0[j]++;
		else {b[++j]=b[i];b0[j]=1;}
	b[0]=j;
	for(i=1,j=1;i<=c[0];i++)
		if(c[i]==c[j]) c0[j]++;
		else {c[++j]=c[i];c0[j]=1;}
	c[0]=j;
	for(i=1,j=1;i<=d[0];i++)
		if(d[i]==d[j]) d0[j]++;
		else {d[++j]=d[i];d0[j]=1;}
	d[0]=j;
	int ans=0;
	for(i=1;i<=d[0];i++)
	{
		j=1;k=c[0];
		while (j<=b[0] && k>=1)
			if(b[j]+c[k]+d[i]==0) ans+=b0[j]*c0[k]*d0[i],j++,k--;
			else if(b[j]+c[k]+d[i]<0) j++;
				 else k--;
	}
	printf("%d\n",ans);
	
	return 0;
}