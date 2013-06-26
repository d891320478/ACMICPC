void kmp(char *s1,char *s2)
{
	int ls1,ls2,i,j, p[100]={-1};
	ls1=strlen(s1);	ls2=strlen(s2);	j=-1;
	for(i=1;i<ls2;i++)
	{
		while(j>-1 && s2[j+1]!=s2[i])j=p[j];
		if(s2[j+1]==s2[i])j++;	p[i]=j;
	}
	j=-1;
	for(i=0;i<ls1;i++)
	{
		while(j>-1 && s2[j+1]!=s1[i])j=p[j];
		if(s2[j+1]==s1[i])j++;
		if(j==ls2-1){	printf("%d\n",i-ls2+1);	j=p[j];	}
	}
}
