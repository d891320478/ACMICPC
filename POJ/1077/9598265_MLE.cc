#include<stdio.h>
#include<string.h>

int i;
char ch;
char a[10];
struct
{
    char s[10],func;
    int pre;
}x[10000000];
bool u[876543210]={0};
long int head=0,tail=0,sum;

int search()
{
    int i;
    for(i=0;a[i];i++)
        if(a[i]=='x')return i;
}

void su()
{
    int i;
    sum=0;
    for(i=0;a[i];i++)
    {
        if(a[i]=='x')sum=sum*10;
        else sum=sum*10+a[i]-'0';
    }
}

void print(long int t)
{
    if(x[t].pre!=-1)
    {
        print(x[t].pre);
        printf("%c",x[t].func);
    }

}

int main()
{
    for(i=0;i<9;i++)
        scanf("%c%c",&x[0].s[i],&ch);
    x[0].s[i]='\0';
    x[0].pre=-1;
    while(head<=tail)
    {
        strcpy(a,x[head].s);
        i=search();
        if(!(i==0 || i==1 || i==2))
        {
            ch=a[i];
            a[i]=a[i-3];
            a[i-3]=ch;
            su();
            if(u[sum]==0)
            {
                u[sum]=1;
                strcpy(x[++tail].s,a);
                x[tail].pre=head;
                x[tail].func='u';
                if(! strcmp(x[tail].s,"12345678x"))
                {
                    print(tail);
                    printf("\n");
                    return 0;
                }
            }
        }
        strcpy(a,x[head].s);
        i=search();
        if(!(i==6 || i==7 || i==8))
        {
            ch=a[i];
            a[i]=a[i+3];
            a[i+3]=ch;
            su();
            if(u[sum]==0)
            {
                u[sum]=1;
                strcpy(x[++tail].s,a);
                x[tail].pre=head;
                x[tail].func='d';
                if(! strcmp(x[tail].s,"12345678x"))
                {
                    print(tail);
                    printf("\n");
                    return 0;
                }
            }
        }
        strcpy(a,x[head].s);
        i=search();
        if(!(i==0 || i==3 || i==6))
        {
            ch=a[i];
            a[i]=a[i-1];
            a[i-1]=ch;
            su();
            if(u[sum]==0)
            {
                u[sum]=1;
                strcpy(x[++tail].s,a);
                x[tail].pre=head;
                x[tail].func='l';
                if(! strcmp(x[tail].s,"12345678x"))
                {
                    print(tail);
                    printf("\n");
                    return 0;
                }
            }
        }
        strcpy(a,x[head].s);
        i=search();
        if(!(i==2 || i==5 || i==8))
        {
            ch=a[i];
            a[i]=a[i+1];
            a[i+1]=ch;
            su();
            if(u[sum]==0)
            {
                u[sum]=1;
                strcpy(x[++tail].s,a);
                x[tail].pre=head;
                x[tail].func='r';
                if(! strcmp(x[tail].s,"12345678x"))
                {
                    print(tail);
                    printf("\n");
                    return 0;
                }
            }
        }
        head++;
    }
    printf("unsolvable\n");

    return 0;
}
