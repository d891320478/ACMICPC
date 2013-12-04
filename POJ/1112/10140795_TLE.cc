#include<iostream>
#include<fstream>
#include<cmath>
#include <cstdlib>

using namespace std;

int n;

struct e{
    int data;
    e *next;
};

e edge[101];
int v[101];


void add(int s,int t){
    e *p=new e;
    p->data=t;
    p->next=edge[s].next;
    edge[s].next=p;
}

int x[101],y[101],mark[101][101];

int dfs(int s,int kind,int f){
    v[s]=2*kind+f;
    if(f==-1) x[kind]++;
    else
        y[kind]++;
    e *p=edge[s].next;
    while(p)
    {
        if(v[p->data]==v[s]) return 1;
        if(v[p->data]==0)
        {
            if(dfs(p->data,kind,-1-f)) return 1;
        }
        p=p->next;
    }
    return 0;
}

int dp[101][101];

int ans[300];

void solve(){
    int i,j,k=0,s,t;
    for(i=1;i<=n;i++)
        if(v[i]==0)
        {
            k++;
            if(dfs(i,k,-1)) break;

        }
    if(i<=n) cout<<"No solution\n";
    else
    {
        dp[0][0]=1;
        for(i=0;i<k;i++)
            for(j=0;j<=n;j++)
                if(dp[i][j])
                {
                    dp[i+1][j+x[i+1]]=1;
                    dp[i+1][j+y[i+1]]=1;
                    mark[i+1][j+x[i+1]]=0;
                    mark[i+1][j+y[i+1]]=1;
                }
        j=n;
        for(i=1;i<=n;i++)
            if(dp[k][i])
            {
                if(abs(i-n+i)<j)
                {
                    j=abs(i-n+i);
                    s=i;
                }
            }
        for(i=k;i>=1;i--)
        {
            if(mark[i][s]==0)
            {
                ans[2*i-1]=1;
                s-=x[i];
            }
            else
            {
                ans[2*i]=1;
                s-=y[i];
            }
        }
        j=0;
        for(i=1;i<=n;i++)
            if(ans[v[i]]) j++;
        cout<<j<<' ';
        for(i=1;i<=n;i++)
            if(ans[v[i]]) cout<<i<<' ';
        cout<<endl;
        cout<<n-j<<' ';
        for(i=1;i<=n;i++)
            if(!ans[v[i]]) cout<<i<<' ';
        cout<<endl;
    }
}

int map[101][101];

void read(){
//    ifstream cin("in.txt");
    int i,j,k;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        while(cin>>j)
        {
            if(j==0) break;
            map[i][j]=1;
        }
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j&&!(map[i][j]==1&&map[j][i]==1))
                add(i,j);

    solve();
}

int main(){
    read();
    return 0;
}