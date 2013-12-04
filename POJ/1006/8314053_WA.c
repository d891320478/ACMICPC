#include<stdio.h>

int a[4];
int i=0;
int j;

int min()
{
    int d,e;

    d=a[0]<a[1]?a[0]:a[1];
    e=a[0]<a[1]?0:1;
    e=d<a[2]?e:2;

    return e;
}

int main()
{
    while(1)
    {
        scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
        i++;
        if((a[0]==-1) && (a[1]==-1) && (a[2]==-1)){printf("\n");break;}
        if((a[0]==a[1]) && (a[1]==a[2]))
        {
            printf("Case %d: the next triple peak occurs in %d days.\n",i,21252-a[3]);
            continue;
        }
        while( !((a[0]==a[1]) && (a[1]==a[2])) )
        {
            j=min();
            if(j==0) a[j]+=23;
            else if(j==1) a[j]+=28;
                 else a[j]+=33;
        }
        printf("Case %d: the next triple peak occurs in %d days.\n",i,a[0]-a[3]);
    }

    return 0;
}
