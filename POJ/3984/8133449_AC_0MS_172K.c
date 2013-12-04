#include<stdio.h>

struct asd
    {
        int x,y;
    }c[5][5];

void print(int xx,int yy)
{
     if(xx==0 && yy==0)return;
     print(c[xx][yy].x,c[xx][yy].y);
     printf("(%d, %d)\n",xx,yy);
}

int main()
{
    int a[5][5]={0},b[5][5]={0};
    int i,j;
    int dx,dy;
    int x[25][2]={{0,0}};
    int open=0,closed=0;
    
    for(i=0;i<=4;i++)
    for(j=0;j<=4;j++)
        scanf("%d",&a[i][j]);
    
    b[0][0]=0;
    do
    {
        dx=x[open][0]; dy=x[open][1];
        if(dx+1<=4)
            if(! a[dx+1][dy])
                if(! b[dx+1][dy]) 
                {
                    b[dx+1][dy]=b[dx][dy]+1;
                    closed++;
                    x[closed][0]=dx+1;
                    x[closed][1]=dy;
                    c[dx+1][dy].x=dx;
                    c[dx+1][dy].y=dy;
                }
        if(dy+1<=4)
            if(! a[dx][dy+1])
                if(! b[dx][dy+1]) 
                {
                    b[dx][dy+1]=b[dx][dy]+1;
                    closed++;
                    x[closed][0]=dx;
                    x[closed][1]=dy+1;
                    c[dx][dy+1].x=dx;
                    c[dx][dy+1].y=dy;
                }
        if(dx-1>=0)
            if(! a[dx-1][dy])
                if(! b[dx-1][dy]) 
                {
                    b[dx-1][dy]=b[dx][dy]+1;
                    closed++;
                    x[closed][0]=dx-1;
                    x[closed][1]=dy;
                    c[dx-1][dy].x=dx;
                    c[dx-1][dy].y=dy;
                }
        if(dy-1>=0)
            if(! a[dx][dy-1])
                if(! b[dx][dy-1]) 
                {
                    b[dx][dy-1]=b[dx][dy]+1;
                    closed++;
                    x[closed][0]=dx;
                    x[closed][1]=dy-1;
                    c[dx][dy-1].x=dx;
                    c[dx][dy-1].y=dy;
                }
                
        open++;
    }
    while(open<=closed);
    
    printf("(0, 0)\n");
    print(c[4][4].x,c[4][4].y);
    printf("(4, 4)\n");
    
    return 0;
}
