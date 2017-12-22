#include<stdio.h>
#include<string.h>
#include<math.h>
#define INF 200000000;
int I[1000000],L[1000000],sequence[1000000],output[1000000];
int LIS_nLogk(int n)
{
    int start,end,mid,LISlength,i;
    LISlength = 0;
    for(i=0;i<=n;i++)
    {
        start = 0;
        end = LISlength;
        while(start <= end)
        {
            mid = (start + end)/2;
            if(I[mid] < sequence[i])start = mid +1;
            else end = mid - 1;
        }
        I[start] = sequence[i];
        L[i] =  start;
        if(LISlength<start)
            LISlength = start;
    }
    return LISlength;
}
int main()
{
    int n,i,result,j;
    n = 0;
    while(scanf("%d",&sequence[n++])!=EOF);
    n = n-2;
    I[0] = -INF;
    for(i=1;i<999999;i++)
        I[i] = INF;
    result = LIS_nLogk(n);
    printf("%d\n",result);
    printf("-\n");
    for(j=result,i=n;j>=1;i--)
        if(L[i]==j)
            output[j--] = sequence[i];

    for(i=1;i<=result;i++)
        printf("%d\n",output[i]);
    return 0;
}
