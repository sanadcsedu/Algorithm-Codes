#include<set>
#include<map>
#include<list>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

#define EPS 1e-9
#define MAX 1000000
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define mod 100000007
#define inf 2147483647
#define ll long long int
#define llu long long unsigned

#define FOR(i, n) for(i=0; i<n; i++)
#define FOR1(i, n) for(i=1; i<=n; i++)
#define mem(a) memset(a, 0, sizeof(a));
#define FORI(i, a, b) for(i=a; i>=b; i--)
#define FORab(i, a, b) for(i=a; i<=b; i++)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

using namespace std;

char str1[100], str2[100];
int dp[100][100];
int task[100][100];
int f(int i, int j)
{
    if(i<0 || j<0)
    {
        if(i < 0)
        {
            for(int x = j; x > 0; x--)
                task[1][x] = 2;

            return (j+1);
        }
        else if(j<0)
        {
            for(int x = i; x > 0; x--)
                 task[x][1] = 1;

            return (i+1);
        }
    }

    if(dp[i][j] != -1)return dp[i][j];
    int ret1, ret2, ret3;

    ret1 = 1 + f(i-1, j);
    ret2 = 1 + f(i, j-1);
    ret3 = (str1[i] == str2[j]) ? f(i-1, j-1) : 1 + f(i-1, j-1) ;

    dp[i][j] = min(ret3 , min(ret1, ret2));

    if(dp[i][j] == ret1)
    {
        task[i][j] = 1;
    }
    else if(dp[i][j] == ret2)
    {
        task[i][j] = 2;
    }
    else if(dp[i][j] == ret3)
    {
         task[i][j] = (str1[i] == str2[j]) ? 0 : 3 ;
    }
    return dp[i][j];
}
int cnt;

void print(int i, int j)
{
    if(i<=0 || j<=0 || task[i][j] == -1 )return ;
    if(task[i][j] == 0)
    {
        print(i-1, j-1);
        return ;
    }
    else if(task[i][j] == 1)
    {
        print(i-1, j);
        printf("%d Delete %d\n", cnt++, i);
    }
    else if(task[i][j] == 2)
    {
        print(i, j-1);
        printf("%d Insert %d,%c\n", cnt++, i, str2[j]);
    }
    else if(task[i][j] == 3)
    {
        print(i-1, j-1);
        printf("%d Replace %d,%c\n", cnt++, i , str2[j]);
    }
}
int main()
{
    int x , y, flag = 0, i, j;
    while(gets(str1) != NULL)
    {
        gets(str2);

        x = strlen(str1);
        y = strlen(str2);
        memset(dp, -1, sizeof(dp));
        memset(task, -1, sizeof(task));

        cnt = 1;
        if(flag)printf("\n");
        int z = f(x, y);

        for(int i=1 ; i<=x; i++)
        {
            for(int j=1 ; j<=y; j++)
                printf("%d ", task[i][j]);
            puts("");
        }

        cout <<z << endl;
        print(x, y);
        flag =1 ;
    }
	return 0;
}
