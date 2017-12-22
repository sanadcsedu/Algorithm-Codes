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
#define MAX 105
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define mod 100000007
#define inf 100000
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
int dp[MAX][MAX];
bool flag[MAX];

void floyd_warshall(int n)
{
    int i , j, k;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                dp[j][i] = dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}
void reset()
{
    int i , j;
    for(i=0; i<101; i++)
    {
        for(j=0; j<101; j++)
            dp[i][j] = inf;

        dp[i][i] = 0;
    }

}
int main()
{
    int tcase, t, a, b, x, y, z, i, j;

    cin >> tcase;
    for(t=1; t<= tcase; t++)
    {
        scanf("%d %d", &a, &b);
        reset();
        for(i=0; i<b ; i++)
        {
            cin >> x >> y >> z;

            if(dp[x][y] > z)dp[y][x] = dp[x][y] = z;
        }
        floyd_warshall(a);
        int equi, _min;
        _min = inf;
        mem(flag);
        for(i=6; i<=a; i++)
        {
            flag[i] = true;

            for(j=2; j<=5 ; j++)
            {
                if((dp[i][j] != dp[i][1] || dp[i][j] == inf))
                {
                    flag[i] = false;
                    break;
                }
            }
        }
        int total;
        for(i=6; i<=a; i++)
        {
            if(flag[i])
            {
                total = -1;
                bool check = true;
                for(j=1; j<=a; j++)
                {
                    if(dp[i][j] == inf)
                    {
                        check = false;
                        break;
                    }
                    if(total < dp[i][j] && i!=j)
                            total = dp[i][j];

                }
                if(_min > total && check)
                    _min = total;
            }
        }
        if(_min == inf)printf("Map %d: -1\n", t);
        else printf("Map %d: %d\n",t, _min);
    }
	return 0;
}
