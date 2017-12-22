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
int weight[25], n, cost[25];
int dp [25][1002];
bool vis[25][1002];
int knapsack(int item , int left)
{
    if(left < 0 )return -inf;
    if(item + 1 == n )return 0;

    if(vis[item][left])return dp[item][left];

    int ret1 = cost[item] + knapsack(item + 1, left - weight[item]);
    int ret2 = knapsack(item + 1, left);

    dp[item][left]  = max(ret1, ret2);
    vis[item][left] = true;

    return dp[item][left];

}
int main()
{
    int w, i;
    while(cin >> w)
    {
        cin >> n;

        for(i=0; i<n; i++)
            cin >> weight[i];
        for(i=0; i<n; i++)
            cin >> cost[i];
        mem(vis);
        int ans = knapsack(0, w);
        cout << ans << endl;
    }
    return 0;
}
