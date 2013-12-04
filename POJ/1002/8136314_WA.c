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
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    }while(i<=j);
    if(i<t) qsort(a,i,t);
    if(j>s) qsort(a,s,j);
}

int num(char s)
{
    switch(s)
    {
        case 'A':;
        case 'B':;
        case 'C':return 2;break;
        case 'D':;
        case 'E':;
        case 'F':return 3;break;
        case 'G':;
        case 'H':;
        case 'I':return 4;break;
        case 'J':;
        case 'K':;
        case 'L':return 5;break;
        case 'M':;
        case 'N':;
        case 'O':return 6;break;
        case 'P':;
        case 'R':;
        case 'S':return 7;break;
        case 'T':;
        case 'U':;
        case 'V':return 8;break;
        case 'W':;
        case 'X':;
        case 'Y':return 9;break;
    }
}

int main()
{   
    char s[100];
    long int n,b=1,c;
    int i,j;
    long int l=0;
    long int a[100001]={0};

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",s);
       
        for(j=0;s[j];j++)
        {
            if(s[j]>='0' && s[j]<='9') c=s[j]-'0';
            else if(s[j]>='A' && s[j]<'Z' && s[j]!='Q')c=num(s[j]);
                 else c=-1;
            if(c!=-1) a[i]=a[i]*10+c;
        }
    }
    
    qsort(a,1,n);
    
    for(i=2;i<=n;i++)
    {    
        if(a[i]==a[i-1])b++;
        else 
        {
            if(b>1) printf("%d-%d %d\n",a[i-1]/10000,a[i-1]%10000,b);
            b=1;
        }
    }
    if(b>1) printf("%d-%d %d\n",a[i-1]/10000,a[i-1]%10000,b);
    
    system("pause");
    return 0;
}
