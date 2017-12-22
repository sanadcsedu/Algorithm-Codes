#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 100000000
int a[105][105];
int dp[105][105];// stores row sum
int main()
{
    //freopen("input.txt", "r", stdin);
    //ios_base :: sync_with_stdio(0); cin.tie(0);
    int tcase, n, i, j , k;
    int _max, sum, ans;
    while(scanf("%d", &n) != EOF)
    {
        memset(dp, 0, sizeof(dp));

        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            {
                scanf("%d", &a[i][j]);
                dp[i][j] = dp[i-1][j] + a[i][j];
            }

        ans = -inf;
        for(i=1; i<=n; i++)
        {
            for(j=i; j<=n; j++)
            {
                sum = 0;
                _max = -inf;
                for(k=1; k<=n; k++)
                {
                    if(sum > 0) sum += dp[j][k] - dp[i-1][k];
                    else sum = dp[j][k] - dp[i-1][k];

                    _max = max(sum, _max);

                }
                ans = max(ans, _max);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
