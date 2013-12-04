//标签： poj2635
//思路：大数模运算，让比L小的所有素数去除K，如果余数为0则表示存在。先预处理打一张素数表，然后对K按1000000000进制进行分解，(按1000~1000000000进制都是可行的，其中1000跑了800多MS，100进制就TLE了)，然后按照公式(A+B)%C = ((A%C)+(B%C))%C进行模运算。

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int nMax = 1000010;
const int mMax = 80000;
typedef long long LL;



bool p[nMax];
int pri[mMax];
int cnt, num[50];



void priList(){        //   打素数表的模板。
    int i, j;
    memset(p, true, sizeof(p));
    for(i = 2; i * i < nMax; i ++)
        if(p[i]){
            for(j = 2*i; j < nMax; j += i)
                p[j] = false;
        }
    for(j = 0, i = 2; i < nMax; i ++)
        if(p[i]) pri[j ++] = i;
}



int mod(int Mod){      //   判断K除以素数Mod的余数。
    LL ans = 0;
    for(int i = cnt; i >= 0; i --)
        ans = (ans*1000000000 + num[i]) % Mod;
    return (int)ans;
}



int main(){
    freopen("xx.in","r",stdin);
    freopen("xx.out","w",stdout);
    char K[110];
    int L, i, k;
    priList();
    while(scanf("%s%d", K, &L) && L){
        memset(num, 0, sizeof(num));
        cnt = 0;
        for(k = 1, i = strlen(K)-1; i >= 0; i --, k *= 10){     //  对K进行分解。
            if(k == 1000000000){
                k = 1; cnt ++;
            }
            num[cnt] += (K[i]-'0') * k;
        }
        bool flag = false;
        for(i = 0; pri[i] < L; i ++)
            if(mod(pri[i]) == 0){
                flag = true;
                break;
            }
        if(flag) printf("BAD %d\n", pri[i]);
        else printf("GOOD\n");
    }
    return 0;
}