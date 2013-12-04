#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

#define min(a,b) (a<b ? a:b)

const int MAXN = 110;
const int INF = 0x7FFFFFFF;
int n,m,pre[MAXN];
double x[MAXN],y[MAXN];
bool circle[MAXN],visit[MAXN];
double ans,map[MAXN][MAXN];

inline double distance(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void dfs(int u){
    visit[u]=true;
    for(int i=2;i<=n;i++)
        if(!visit[i] && map[u][i]!=INF)
            dfs(i);
}
bool connected(){
    memset(visit,false,sizeof(visit));
    int i,cnt=0;
    for(i=1;i<=n;i++)
        if(!visit[i])
            dfs(i),cnt++;
    return cnt==1 ? true : false;
}
void min_arborescence(){
    int i,j,k;
    memset(circle,false,sizeof(circle));
    while(true){
        for(i=2;i<=n;i++){
            if(circle[i]) continue;
            pre[i]=i;
            map[i][i]=INF;
            for(j=1;j<=n;j++){
                if(circle[j]) continue;
                if(map[j][i]<map[pre[i]][i])
                    pre[i]=j;
            }
        }
        for(i=2;i<=n;i++){
            if(circle[i]) continue;
            j=i;
            memset(visit,false,sizeof(visit));
            while(!visit[j] && j!=1){
                visit[j]=true;
                j=pre[j];
            }
            if(j==1) continue;
            i=j;
            ans+=map[pre[i]][i];
            for(j=pre[i];j!=i;j=pre[j]){
                ans+=map[pre[j]][j];
                circle[j]=true;
            }
            for(j=1;j<=n;j++){
                if(circle[j]) continue;
                if(map[j][i]!=INF)
                    map[j][i]-=map[pre[i]][i];
            }
            for(j=pre[i];j!=i;j=pre[j])
                for(k=1;k<=n;k++){
                    if(circle[k]) continue;
                    map[i][k]=min(map[i][k],map[j][k]);
                    if(map[k][j]!=INF)
                        map[k][i]=min(map[k][i],map[k][j]-map[pre[j]][j]);
                }
            break;
        }
        if(i>n){
            for(j=2;j<=n;j++){
                if(circle[j]) continue;
                ans+=map[pre[j]][j];
            }
            break;
        }
    }
}
int main(){
    int i,j,u,v;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(ans=i=0;i<=n;i++) for(j=0;j<=n;j++) map[i][j]=INF;
        for(i=1;i<=n;i++) scanf("%lf %lf",&x[i],&y[i]);
        while(m--){
            scanf("%d %d",&u,&v);
            map[u][v]=distance(x[u],y[u],x[v],y[v]);
        }
        if(!connected()) puts("poor snoopy");
        else{
            min_arborescence();
            printf("%.2lf\n",ans);
        }
    }
    return 0;
}