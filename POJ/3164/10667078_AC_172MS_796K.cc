#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 110
#define INF 0x7FFFFFFF
int n,m,pre[N],cnt;
double x[N],y[N],ans,a[N][N];
bool cir[N],vis[N];
inline double distance(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void dfs(int u)
{
	vis[u]=1; cnt++;
	for(int i=2;i<=n;i++)
		if(a[u][i]<INF && ! vis[i]) dfs(i);
}
void min_arborescence(){
    int i,j,k;
    memset(cir,false,sizeof(cir));
    while(true){
        for(i=2;i<=n;i++){
            if(cir[i]) continue;
            pre[i]=i;
            a[i][i]=INF;
            for(j=1;j<=n;j++){
                if(cir[j]) continue;
                if(a[j][i]<a[pre[i]][i])
                    pre[i]=j;
            }
        }
        for(i=2;i<=n;i++){
            if(cir[i]) continue;
            j=i;
            memset(vis,false,sizeof(vis));
            while(!vis[j] && j!=1){
                vis[j]=true;
                j=pre[j];
            }
            if(j==1) continue;
            i=j;
            ans+=a[pre[i]][i];
            for(j=pre[i];j!=i;j=pre[j]){
                ans+=a[pre[j]][j];
                cir[j]=true;
            }
            for(j=1;j<=n;j++){
                if(cir[j]) continue;
                if(a[j][i]!=INF)
                    a[j][i]-=a[pre[i]][i];
            }
            for(j=pre[i];j!=i;j=pre[j])
                for(k=1;k<=n;k++){
                    if(cir[k]) continue;
                    a[i][k]=min(a[i][k],a[j][k]);
                    if(a[k][j]!=INF)
                        a[k][i]=min(a[k][i],a[k][j]-a[pre[j]][j]);
                }
            break;
        }
        if(i>n){
            for(j=2;j<=n;j++){
                if(cir[j]) continue;
                ans+=a[pre[j]][j];
            }
            break;
        }
    }
}
int main(){
    int i,j,u,v;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(ans=i=0;i<=n;i++) for(j=0;j<=n;j++) a[i][j]=INF;
        for(i=1;i<=n;i++) scanf("%lf %lf",&x[i],&y[i]);
        while(m--){
            scanf("%d %d",&u,&v);
            a[u][v]=distance(x[u],y[u],x[v],y[v]);
        }
        memset(vis,0,sizeof(vis));
        cnt=0; dfs(1);
		if(cnt<n) puts("poor snoopy");
        else{
            min_arborescence();
            printf("%.2f\n",ans);
        }
    }
    return 0;
}