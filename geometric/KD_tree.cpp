//HDU 4347
#define INF 1<<30
#define SET(a,b) memset(a,b,sizeof(a))
#define N 50010
#define D 10
int n,d;//d维
struct point
{   int z[D],id;
    void init(int d) {for(int i=1;i<=d;i++) scanf("%d",&z[i]);}
}p[N],ansp,a;
int diy[N];//切割方向
int vis[N];  int kk;
int ans,ansid;	int idtp;//比较维度
int cmp(const point &a,const point &b)
{    return a.z[idtp]<b.z[idtp];	}
void build_kd(int l,int r,point *p)//建树
{
    if(l>r) return;    int mid=(l+r)>>1;    int i,j,minn,maxx,mnf=-1;
    for(i=1;i<=d;i++)
    {
    	idtp=i;
    	minn=min_element(p+l,p+r+1,cmp)->z[i];
    	maxx=max_element(p+l,p+r+1,cmp)->z[i];
    	if(maxx-minn>=mnf) {diy[mid]=i; mnf=maxx-minn;}
    }	
    idtp=diy[mid];    nth_element(p+l,p+mid,p+r+1,cmp);
    build_kd(l,mid-1,p);    build_kd(mid+1,r,p);
}
int dist(point a,point b)
{	int ans=0;	  for(int i=1;i<=d;i++)	ans+=(a.z[i]-b.z[i])*(a.z[i]-b.z[i]);  return ans;   }
void find(int l,int r,point a,point *p)
{
    if(l>r) return;    int mid=(l+r)>>1;    int dis=dist(a,p[mid]);
    if(! vis[mid]) if(ans>dis || ans==-1) {ans=dis; ansid=mid; ansp=p[mid];}
    int d=a.z[diy[mid]]-p[mid].z[diy[mid]];
    int l1=l,l2=mid+1,r1=mid-1,r2=r;
    if(d>0) swap(l1,l2),swap(r1,r2);
    find(l1,r1,a,p);    if(d*d<ans || ans==-1) find(l2,r2,a,p);
}
int main()
{
    int i,j;
    while (scanf("%d%d",&n,&d)!=-1)
    {
        for(i=1;i<=n;i++) p[i].init(d);
        SET(diy,0);    build_kd(1,n,p);     int pro;
        scanf("%d",&pro);
        while (pro--)
        {
        	memset(vis,0,sizeof(vis));
        	a.init(d);    	scanf("%d",&kk);
        	printf("the closest %d points are:\n",kk);
        	while (kk--)
        	{
        		ans=-1;	find(1,n,a,p);		vis[ansid]=1;
        		for(i=1;i<=d;i++)
        		{	printf("%d",ansp.z[i]);	if(i<d)printf(" ");	else printf("\n");	}
        	}
        }
    }
    return 0;
}
