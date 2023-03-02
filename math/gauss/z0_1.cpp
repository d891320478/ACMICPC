int guass(int a[][NN],int n,int m)
{
	int i,j,k,r;
	for(i=r=1;i<m;i++)
	{
		for(j=r;j<=n && ! a[j][i];j++);
		if(j>n) continue;
		if(j>r) for(k=1;k<=m;k++) swap(a[r][k],a[j][k]);
		for(j=1;j<=n;j++) if(j!=r && a[j][i])
		for(k=i;k<=m;k++) if(a[r][k]) a[j][k]^=1;
		++r;
	}
	return r-1;//rank
}
