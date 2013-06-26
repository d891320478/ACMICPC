//最长回文子串
#define N 50010
#define M 20
int wx[N],wy[N],wss[N],wv[N];
bool cmp(int *r,int n,int a,int b,int l){ return a+l<n && b+l<n && r[a]==r[b] && r[a+l]==r[b+l]; }
void da(int s[],int sa[],int rank[],int height[],int n,int m)
{
	int *x=wx,*y=wy,p; int i,j,k;
	for(i=0;i<m;i++) wss[i]=0;
	for(i=0;i<n;i++) wss[x[i]=s[i]]++;
	for(i=1;i<m;i++) wss[i]+=wss[i-1];
	for(i=n-1;i>=0;i--) sa[--wss[x[i]]]=i;
	for(j=1,p=1;p<n && j<n;j*=2,m=p)
	{
		for(i=n-j,p=0;i<n;i++) y[p++]=i;
		for(i=0;i<n;i++) if(sa[i]-j>=0) y[p++]=sa[i]-j;
		for(i=0;i<n;i++) wv[i]=x[y[i]];
		for(i=0;i<m;i++) wss[i]=0;
		for(i=0;i<n;i++) wss[wv[i]]++;
		for(i=1;i<m;i++) wss[i]+=wss[i-1];
		for(i=n-1;i>=0;i--) sa[--wss[wv[i]]]=y[i];
		for(swap(x,y),p=1,i=1,x[sa[0]]=0;i<n;i++)
			x[sa[i]]=cmp(y,n,sa[i-1],sa[i],j)?p-1:p++;
	}
	for(i=0;i<n;i++) rank[sa[i]]=i;
	for(i=j=k=0;i<n;height[rank[i++]]=k)
		if(rank[i]>0)
		for(k?k--:0,j=sa[rank[i]-1];i+k<n && j+k<n && s[i+k]==s[j+k];k++);
	height[0]=0;
}
char s[N];	int str[N],sa[N],rank[N],height[N];
void init(char *s)
{ int len=strlen(s); for(int i=0;i<=len;i++) str[i]=s[i];
  da(str,sa,rank,height,len,128); }
int mx[M][N],idx[N],p[M];
void makermq(int val[],int n)
{	idx[0]=-1;
	for(int i=1;i<N;i++) idx[i]=idx[i-1]+(!(i&(i-1)));
	for(int i=0;i<M;i++) p[i]=(1<<i);
	for(int i=1;i<=n;i++) mx[0][i]=val[i];
	for(int i=1;p[i]<=n;i++) for(int j=1;j+p[i]-1<=n;j++)
		mx[i][j]=min(mx[i-1][j],mx[i-1][j+p[i-1]]);
}
int lcp(int x,int y)
{	x=rank[x],y=rank[y]; if(x>y) swap(x,y); if(x==y) return x-sa[x];
	x++; int k=idx[y-x+1]; return min(mx[k][x],mx[k][y-p[k]+1]);
}
char st[N];
int main()
{
	scanf("%s",st); int len=strlen(st); st[len]='#';
	for(int i=0;i<len;i++) st[len+i+1]=st[len-i-1];
	st[len*2+1]=0; init(st); makermq(height,len*2); int k,ans=0,t;
	for(int i=0,j=len*2;st[i]!='#';i++,j--)
	{	t=lcp(i,j); if(t*2-1>ans) ans=t*2-1,k=i-t+1;
		if(j==len*2) continue; t=lcp(i,j+1); if(t*2>ans) ans=t*2,k=i-t;
	}
	for(int i=0;i<ans;i++) printf("%c",st[k+i]); printf("\n");
	return 0;
}
