#include<stdio.h>
#include<string.h>

char s1[202],s2[202],s3[202];
int i;


int main()

{

    
    gets(s1);
    while(strcmp(s1,"START")==0)
    {
        gets(s2);
        gets(s3);
        for(i=0;s2[i];i++)
        {
        	if(s2[i]>='A' && s2[i]<='Z')
        	{
            	if(s2[i]>'E')printf("%c",s2[i]-5);
            	else printf("%c",s2[i]+21);
        	}
        	else printf("%c",s2[i]);
        }
        printf("\n");        
        gets(s1);
    }
	    

    return 0;

}
