#include<stdio.h>
#include<string.h>
char a[1005],b[1005];
int LCS[1005][1005];
int main()
{
    int i,j,x,y;
    while(gets(a)!=NULL)
    {
        gets(b);
        x = strlen(a);
        y = strlen(b);
        memset(LCS,0,sizeof(LCS));
        for(i=1;i<=x;i++)
        {
            for(j=1;j<=y;j++)
            {
                if(a[i-1]==b[j-1])LCS[i][j] = LCS[i-1][j-1] + 1;
                else if(LCS[i][j-1]<=LCS[i-1][j])LCS[i][j] = LCS[i-1][j];
                else LCS[i][j] = LCS[i][j-1];
            }
        }
        printf("%d\n",LCS[x][y]);
    }
    return 0;
}
