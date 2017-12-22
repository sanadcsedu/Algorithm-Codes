int check(int mask,int k)
{
    return (mask)&(1<<k);
}
int set1(int mask,int k)
{
    return (mask)|(1<<k);
}
int f(int i,int mask)
{
    int ret=0,j;
    if(i==n) return 0;
    if(dp[mask]!=-1)   return dp[mask];
    for(j=0;j<n;j++)
    {
        if(check(mask,j))   continue;
        ret=min(ret,a[i][j]+f(i+1,set1(mask,j)));//(max or min or any operation)
    }
    return dp[mask]=ret;
}
