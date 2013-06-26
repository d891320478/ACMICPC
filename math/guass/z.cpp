int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int yf(int *a,int n)
{
	int i,j=0,k=0;
	for(i=1;i<=n;i++)
		if(b[i]) if(j) k=gcd(k,ABS(b[i])); else k=ABS(b[i]),j=1;
	if(k) for(i=1;i<=n;i++) b[i]/=k;
}
int guass(int a[][N],int n,int m)
{
	int i,j,k,r,t1,t2,d;
	for(i=r=1;i<m;i++)
	{
		for(j=r;j<=n && ! a[j][i];j++);
		if(j>n) continue;
		if(j>r) for(k=1;k<=m;k++) swap(a[r][k],a[j][k]);
		for(j=1;j<=n;j++)
		if(j!=r && a[j][i])
		{
			d=gcd(ABS(a[r][i]),ABS(a[j][i]));
			t1=a[j][i]/d;
			t2=a[r][i]/d;
			for(k=1;k<=m;k++)
				a[j][k]=(a[j][k]*t2-a[r][k]*t1)%7;
			//yf(a[j],m);
		}
		r++;
	}
	for(i=n;i>0;i--)
	if(a[i][m])
	{
		for(j=1;j<m && !a[i][j];j++);
		if(j==m) return -1;
	}
	return r-1;
}
