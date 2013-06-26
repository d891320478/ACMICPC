给定一个排列求排列后的第m个排列
int n,m,a[10010],p,q,x,y,i;
int main ()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	while (m--)
	{
		p=n-1;		while (a[p]>a[p+1]) p--;
		if(p>0)
		{
			q=n;	while(a[q]<a[p]) q--;	swap(a[p],a[q]);	x=p+1;	y=n;
			while (x<y){	swap(a[x],a[y]);		x++;y--;		}
		}
	}
	for(i=1;i<n;i++) printf("%d ",a[i]);	printf("%d\n",a[n]);
	return 0;
}
//-------------------------------------------------------------
int n,m,a[10010],p,q,x,y,i;
int main ()
{
	int t;	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		while (m--) next_permutation(a+1,a+1+n);
		for(i=1;i<n;i++) printf("%d ",a[i]);	printf("%d\n",a[n]);
	}
	return 0;
}
