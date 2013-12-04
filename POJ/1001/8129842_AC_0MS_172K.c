#include<stdio.h>
#include<string.h>

int main()
{
    char s[7];
    int d=0;
    int i,j,l,z,n,nn;
    
    while(scanf("%s%d",s,&nn)==2)
    {
        int a[201]={0},b[201]={0};
        
        d=strcspn(s,".");
        if(d!=0 || s[0]=='.') d=(5-d)*nn;
        
        for(i=0;i<6;i++)
            if(s[5-i]!='.') a[++a[0]]=s[5-i]-'0';
        for(i=0;i<=a[0];i++)
            b[i]=a[i];
        
        for(z=2;z<=nn;z++)
        {
            int c[201]={0};
            for(i=1;i<=b[0];i++)
            for(j=1;j<=a[0];j++)
            {
                n=i+j-1;
                c[n]+=b[i]*a[j];
                c[n+1]+=c[n]/10;
                c[n]%=10;
            }
            c[0]=b[0]+a[0]-1;
            if(c[c[0]+1]>0)c[0]++;
            for(i=c[0];i>=0;i--)
                b[i]=c[i];
        }
        
        for(;(b[b[0]]==0 && b[0]>d);b[0]--);
        for(i=1;(b[i]==0 && i<=d);i++);
        for(;b[0]>=i;b[0]--)
        {
            if(b[0]==d) printf(".");
            printf("%d",b[b[0]]);
        }
        printf("\n");
    }
    return 0;
}
