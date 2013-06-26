#define NN 310
#define MOD 10007
int a[NN][NN];
int n,r;
struct point
{
	int x,y;
}p[NN];
int exteuclid(int a,int b,int &x,int &y)
{
    int tmp,d;
    if(b==0) {   x=1;  y=0; return a;    }
    d=exteuclid(b,a%b,x,y);
    tmp=x;    x=y;    y=tmp-a/b*y;
    return d;
}
int guass(int a[][NN],int n)
{
	int i,j,k,r,ans=1,flg=1;
	for(i=1;i<=n;i++)
	{
		if(! a[i][i])
		{
			for(j=i+1;j<=n;j++) if(a[j][i]) break;
			if(j>n) return -1;
			flg^=1;
			for(k=i;k<=n;k++)
				swap(a[i][k],a[j][k]);
		}
		ans=ans*a[i][i]%MOD;
		int x,y;
		int t=exteuclid(a[i][i],MOD,x,y);
		for(k=i+1;k<=n;k++)
			a[i][k]=a[i][k]*x%MOD;
		for(j=i+1;j<=n;j++)
		for(k=i+1;k<=n;k++)
		{
			a[j][k]=(a[j][k]-a[j][i]*a[i][k])%MOD;
			if(j==k) a[j][k]=(a[j][k]+MOD)%MOD;
		}
	}
	ans=(ans%MOD+MOD)%MOD;
	return flg?ans:MOD-ans;
}
int xmult(point p0,point p1,point p2)
{ return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x); }
int ins(int a,int b)
{
	for(int i=1;i<=n;i++)
		if(i!=a && i!=b)
		{
			if(p[i].x>=min(p[a].x,p[b].x) && p[i].x<=max(p[a].x,p[b].x))
			if(p[i].y>=min(p[a].y,p[b].y) && p[i].y<=max(p[a].y,p[b].y))
				if(xmult(p[i],p[a],p[b])==0) return 1;
		}
	return 0;
}
int main()
{
freopen("1.in","r",stdin);
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d%d",&n,&r);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
		for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			if(ins(i,j)) continue;
			if((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y)<=r*r)
			{
				a[i][i]++;
				a[j][j]++;
				a[i][j]=a[j][i]=-1;
			}
		}
		cout<<guass(a,n-1)<<endl;
		/*
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%lld ",a[i][j]);
			printf("\n");
		}
		*/
	}
	return 0;
}
