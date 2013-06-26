//http://en.wikipedia.org/wiki/Tutte_matrix/
//高斯消元求矩阵的秩
#define N 110
#define MOD 111
#define ABS(x) ((x)>0?(x):-(x))
int a[N][N]; int n,x;
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
void yuefen(int *a,int n)
{
	int i,flag=0,k=0;
	for(i=1;i<=n;i++)
		if(a[i])
		if(! flag) flag=1,k=ABS(a[i]);
		else k=gcd(ABS(a[i]),k);
	if(k) for(i=1;i<=n;i++) a[i]/=k;
}
int guass(int n,int m)
{
	int i,j,k,r,tmp,ans=n,flag;
	for(i=r=1;i<n && r<=m;i++,r++)
	{
		j=i;
		for(k=i+1;k<=n;k++) if(ABS(a[k][r])>ABS(a[j][r])) j=k;
		if(j!=i) for(k=1;k<=m;k++) swap(a[i][k],a[j][k]);
		if(a[i][r]==0) { i--; continue; }
		for(j=i+1;j<=n;j++)
		{
			tmp=a[j][r];
			for(k=i;k<=m;k++)
				a[j][k]=a[j][k]*a[i][r]-a[i][k]*tmp;
			yuefen(a[j],m);
		}
	}
	for(i=n;i>0;i--)
	{
		flag=1;
		for(j=1;j<=m;j++) if(a[i][j]){ flag=0; break;}
		ans-=flag;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	srand((unsigned long long)time(0));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		scanf("%d",&x);
		if(i==j || !x) a[i][j]=0;
		else if(x)
		{
			if(i<j) a[i][j]=rand()%MOD+1;
			else a[i][j]=-a[j][i];
		}
	}
	printf("%d\n",guass(n,n)/2);
	return 0;
}
