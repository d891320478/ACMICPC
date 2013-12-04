#include<stdio.h>

int a[4];
int i=0;
int j;

int main()
{
    while(1)
    {
        scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
        i++;
        if((a[0]==-1) && (a[1]==-1) && (a[2]==-1)){printf("\n");break;}
        if((a[0]==a[1]) && (a[1]==a[2]))
        {
            printf("Case %d: the next triple peak occurs in %d days.\n",i,21252+a[0]-a[3]);
            continue;
        }
        for(j=21252;! ( ((j-a[0]) % 23==0) && ((j-a[1]) % 28==0) && ((j-a[2]) % 33==0) );j--);
        printf("Case %d: the next triple peak occurs in %d days.\n",i,j-a[3]);
    }

    return 0;
}
