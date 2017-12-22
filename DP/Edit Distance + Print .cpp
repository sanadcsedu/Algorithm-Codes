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
#define pi acos(-1.0)
#define mod 100000007
#define inf 2147483647
#define ll long long int

#define FOR(i, n) for(i=0; i<n; i++)
#define FOR1(i, n) for(i=1; i<=n; i++)
#define mem(a) memset(a, 0, sizeof(a));
#define FORI(i, a, b) for(i=a; i>=b; i--)
#define FORab(i, a, b) for(i=a; i<=b; i++)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

using namespace std;
char str1[100], str2[100];
int p[100][100];
int dp[100][100];

int f(int x, int y)
{
    int ret1, ret2, ret3;
    dp[0][0] = 0;
    p[0][0] = -1;
    int i,j;
    for(i=1; i<100; i++)
    {
        dp[i][0] = i;
        dp[0][i] = i;
        p[0][i] = 1;//insert
        p[i][0] = 2;//delete
    }
    for(i=1 ;i<x; i++)
    {
        for(j=1; j<y; j++)
        {
            ret1 = dp[i-1][j-1] + ((str1[i] == str2[j]) ? 0 : 1);
            ret2 = dp[i-1][j] + 1;
            ret3 = dp[i][j-1] + 1;

            dp[i][j] = min(ret1, min(ret2, ret3));

            if(dp[i][j] == ret1)p[i][j] = 0;
            else if(dp[i][j] == ret2)p[i][j] = 2;
            else p[i][j] = 1;
        }
    }
    return dp[x-1][y-1];
}
char seq[200];
void print(int x, int y)
{
    mem(seq);
    int i,j , u, v, k, len;
    i = x-1;
    j = y-1;
    k = 0;
    while(true)
    {
        if(p[i][j] == -1)break;
        else if(p[i][j] ==0 )
        {
            if(str1[i] == str2[j])seq[k] = 'M';
            else seq[k] = 'S';

            i--;
            j--;
        }
        else if(p[i][j] == 1)
        {
            seq[k] = 'I';
            j--;
        }
        else
        {
            seq[k] = 'D';
            i--;
        }
        k++;
    }
    len = k;
    u = v = 1;
    i = j = 0;

    for(k= len-1; k>=0 ; k--)
    {
        if(seq[k] == 'M')
        {
            i++;
            j++;
            v++;
        }
        else if(seq[k] == 'S')
        {
            ++i;
			++j;
			printf("%d Replace %d,%c\n", u, v, str2[j]);
			++v;
			++u;
        }
        else if(seq[k] == 'I')
		{
			++j;
			printf("%d Insert %d,%c\n", u, v, str2[j]);
			++v;
			++u;
		}
		else if(seq[k] == 'D')
		{
			++i;
			printf("%d Delete %d\n", u, v);
			++u;
		}
    }
}
int main()
{
    str1[0] = str2[0] = ' ';
    int z, flag=0, x, y;
    while(gets(&str1[1]) != NULL)
    {
        gets(& str2[1]);
        if(flag)puts("");
        flag = 1;
        x = strlen(str1);
        y = strlen(str2);
        memset(dp,0,sizeof(dp));
        memset(p, -1, sizeof(p));
        z = f(x, y);
        cout << z << endl;
        print(x, y);

    }
	return 0;
}

