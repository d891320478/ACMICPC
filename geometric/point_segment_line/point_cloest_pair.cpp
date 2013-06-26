#define N 100010
#define INF 1e20
struct point{	double x,y;	void init(){scanf("%lf %lf",&x,&y);}	}p[N];
int n,tmpt[N];
int cmpxy(point a,point b){	return a.x<b.x || a.x==b.x && a.y<b.y;	}
int cmpy(int a,int b){	return p[a].y<p[b].y;	}
double dist(point a,point b){	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));	}
double closest_pair(int l,int r)
{
	double d=INF;		if(l==r) return d;	if(r-l==1) return dist(p[l],p[r]);
	int mid=(l+r)>>1;	double d1=closest_pair(l,mid),d2=closest_pair(mid+1,r);
	d=min(d1,d2);		int i,j,k=0;
	for(i=l;i<=r;i++)		if(fabs(p[mid].x-p[i].x)<=d) tmpt[k++]=i;
	sort(tmpt,tmpt+k,cmpy);
	for(i=0;i<k;i++)
	for(j=i+1;j<k && p[tmpt[j]].y-p[tmpt[i]].y<d;j++)
		d=min(d,dist(p[tmpt[i]],p[tmpt[j]]));
	return d;
}
int main ()
{
	while (scanf("%d",&n) && n)
	{	for(int i=0;i<n;i++) p[i].init();		sort(p,p+n,cmpxy);
		printf("%.2lf\n",closest_pair(0,n-1)/2);
	}
	return 0;
}
