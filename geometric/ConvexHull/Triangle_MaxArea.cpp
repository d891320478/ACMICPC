//凸包最大面积三角形
//O(N^2)-----------------------------
void rotate(point *p,int n)
{
	if(n<3){	printf("0.00\n"); return;	}
	int i,j,k;	double ans=0.0,tmp;
	for(int i=0;i<n;i++)
	{	j=(i+1)%n; k=(j+1)%n;
		while (j!=k && i!=k)
		{
			while (fabs(xmult(p[i],p[j],p[k+1]))>fabs(xmult(p[i],p[j],p[k]))) k=(k+1)%n;
			tmp=fabs(xmult(p[i],p[j],p[k]));	ans=max(ans,tmp);		j=(j+1)%n;
		}
	}
	printf("%.2f\n",ans/2.0);
}
//O(N)-------------------------------
int ltj,ltk;
double area(int i,int j,int n,point *p)
{	int k=ltk;	if(k<=j) k=j+1;
	while (k+1<n && fabs(xmult(p[i],p[j],p[k]))<fabs(xmult(p[i],p[j],p[k+1]))) k++;
	ltk=k;	return fabs(xmult(p[i],p[j],p[k]));
}
void rotate(point *p,int n)
{	int i,j,k;	ltj=ltk=0;	double ans=0.0,tmp;
	for(i=0;i<n-2;i++)
	{	j=ltj;	if(j<=i) j=i+1;
		while (1)
		{	if(j+2>=n) break;	k=ltk;
			if(area(i,j,n,p)<area(i,j+1,n,p)) j++;
			else{ ltk=k; break; }
		}
		ltj=j; ans=max(ans,area(i,j,n,p));
	}
	printf("%.2f\n",ans/2.0);
}
