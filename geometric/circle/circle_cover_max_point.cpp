//给定半径圆覆盖最多点
#define PI acos(-1.0)
#define N 500
struct point{	double x,y;	}p[N];
double dist[N][N];
struct lis{	double a;	bool flag;	int id;	}list[10*N];
int cnt;
double dis(point a,point b){	return sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0));	}
int cmp(const lis &a,const lis &b){ if(a.a<b.a)return 1; if(a.a==b.a)return a.id>b.id; return 0; }
int main ()
{
	int n,i,j,ans,num;
	double r,theta,delta,a1,a2;
	while (scanf("%d",&n) && n)
	{
		r=1.0;		r+=1e-7;		r*=2.0;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
			for(j=0;j<i;j++)	dist[i][j]=dist[j][i]=dis(p[i],p[j]);
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			cnt=0;
			for(j=0;j<n;j++)
				if(j!=i && dist[i][j]<=r)
				{
					theta=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
					if(theta<0.0)theta+=2*PI;
					delta=acos(dist[i][j]/r);
					a1=theta-delta;		a2=theta+delta;
					list[cnt].a=a1;		list[cnt].flag=2;	list[cnt].id=cnt++;
					list[cnt].a=a2;		list[cnt].flag=0;	list[cnt].id=cnt++;
				}
			sort(list,list+cnt,cmp);		num=0;
			for(j=0;j<cnt;j++)
				if(list[j].flag)	{	num++;		ans=ans>num?ans:num;		}
				else num--;
		}
		printf("%d\n",ans+1);
	}
	return 0;
}
