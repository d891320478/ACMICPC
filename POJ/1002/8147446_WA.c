#include<stdio.h>

void qsort(long int *a,long int s,long int t)
{
    long int x=a[(s+t)/2],temp;
    long int i=s,j=t;
    
    do
    {    
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if(i<=j)
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
            j--;
        }
    }while(i<=j);
    if(i<t) qsort(a,i,t);
    if(j>s) qsort(a,s,j);
}

int num(char ch)
{
    if(ch>='A' && ch <='C') return 2;
    if(ch>='D' && ch <='F') return 3;
    if(ch>='G' && ch <='I') return 4;
    if(ch>='J' && ch <='L') return 5;
    if(ch>='M' && ch <='O') return 6;
    if(ch>='P' && ch <='S') return 7;
    if(ch>='T' && ch <='V') return 8;
    if(ch>='W' && ch <='Y') return 9;
}

int main()
{   
    char s[100];
    long int n,b=1,c;
    int i,j;
    long int l=0;
    long int a[100002];

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",s);
       
        a[i]=0;
        for(j=0;s[j];j++)
        {
            if(s[j]>='0' && s[j]<='9') c=s[j]-'0';
            else if(s[j]>='A' && s[j]<'Z' && s[j]!='Q')c=num(s[j]);
                 else c=-1;
            if(c!=-1) a[i]=a[i]*10+c;
        }
    }
    
    qsort(a,1,n);
    a[n+1]=-1;
    for(i=2;i<=n+1;i++)
    {    
        if(a[i]==a[i-1])b++;
        else 
        {
            if(b>1) printf("%d-%d %d\n",a[i-1]/10000,a[i-1]%10000,b);
            b=1;
        }
    }

    return 0;
}
