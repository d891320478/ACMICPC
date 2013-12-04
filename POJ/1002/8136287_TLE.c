#include<stdio.h>

struct asd
    {
        long int tel,sum;
    };

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

int search(struct asd *a,long int b,long int st,long int en)
{
    long int i=(st+en)/2;
    
    if(st==en)  if(a[st].tel!=b) return -1;
                else return st;
    if(a[i].tel>b) return search(a,b,st,i-1);
    else if(a[i].tel<b) return search(a,b,i+1,en);
         else if(a[i].tel==b) return i;
}

void insert(struct asd *a,int b,int l)
{
    struct asd temp;
    
    while(a[l].tel>b && l>=0) a[l+1]=a[l--];
    a[++l].tel=b;
    a[l].sum=1;
}

int main()
{
    char s[100];
    long int n,b,c;
    int i,j;
    long int l=0;
    struct asd a[100001];

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",s);
       
        b=0;
        for(j=0;s[j];j++)
        {
            if(s[j]>='0' && s[j]<='9') c=s[j]-'0';
            else if(s[j]>='A' && s[j]<'Z' && s[j]!='Q')c=num(s[j]);
                 else c=-1;
            if(c!=-1) b=b*10+c;
        }
        
        c=search(a,b,0,l);
        if(c!=-1) a[c].sum++;
        else {insert(a,b,l); l++;}
    }
    
    for(i=1;i<=l;i++)
        if(a[i].sum>1) printf("%d-%d %d\n",a[i].tel/10000,a[i].tel%10000,a[i].sum);
    
    system("pause");
    return 0;
}
