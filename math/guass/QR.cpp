#define EPS 1e-8
int dcmp(double x)
{
	if(x>EPS) return 1;
	if(x<-EPS) return -1;
	return 0;
}
int guass(double a[][N],int n,int m)
{
	int i,j,k,r;
	double tmp;
	for(i=r=1;i<m;i++)
	{
		for(j=r;j<=n && !dcmp(a[j][i]);j++);
		if(j>n) continue;
		if(j>r) for(k=1;k<=m;k++) swap(a[j][k],a[r][k]);
		for(j=1;j<=n;j++)
		if(j!=r && dcmp(a[j][i]))
		{
			tmp=a[j][i]/a[r][i];
			for(k=1;k<=m;k++)
				a[j][k]-=tmp*a[r][k];
		}
		r++;
	}
	for(i=n;i>0;i--)
	if(dcmp(a[i][m]))
	{
		for(j=1;j<m && !dcmp(a[i][j]);j++);
		if(j>=m) return -1;
	}
	return r-1;
}
