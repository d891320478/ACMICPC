int dfs(int i)
{
    for(int j=head[i];j!=-1;j=next[j])
  		if(! u[e[j]])
  		{	u[e[j]]=1;
   			if( q[e[j]]==0 || dfs(q[e[j]]) )
   			{    	q[e[j]]=i;		h[i]=e[j];		return 1;		}
  		}
    return 0;
}