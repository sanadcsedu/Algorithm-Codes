#include <bits/stdc++.h>
#define fi first
#define se second

#define check(mask, k) (mask & (1 << k))
#define set1(mask, k) (mask | (1 << k))

using namespace std;

typedef long long ll;

#define MAX 101
#define MAXN 15
#define inf 1000000000000000ll

int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};

ll dis[MAX][MAX];
int q[MAX * MAX];
ll mp[MAXN][MAXN];
ll dp[MAXN][1 << MAXN];
ll knight_x[MAXN], knight_y[MAXN], target_x[MAXN], target_y[MAXN];

ll reduce(ll x, ll y)
{
    ll ret = 0, step;
    if(x < y) swap(x, y);
    while(x > 50 )
    {
        step = x / 2 / 2;
        ret += step;
        x -= step * 2;
        y -= step;
        if(y < 0) y = ((y % 2) + 2) % 2;
        if(x < y) swap(x, y);
    }
    ret += dis[x + (MAX >> 1)][y + (MAX >> 1)];
    return ret;
}
int n;
ll bitmask(int pos, int mask)
{
    if(pos == n) return 0;
    if(dp[pos][mask] != inf) return dp[pos][mask];
    ll &ret = dp[pos][mask];
    for(int i=0 ;i<n; i++)
    {
        if(!check(mask, i))
        {
            ret = min(ret, mp[pos][i] + bitmask(pos + 1, set1(mask, i)));
        }
    }
    return ret;
}
void pre_cal()
{
    int x, y, i, j, nx, ny;

    queue< pair<int, int> > q;
    pair<int, int> temp;

    for(i = 0; i < MAX; ++i)
		for(j = 0; j < MAX; ++j) dis[i][j] = inf;

    x = y = (MAX >> 1);
    dis[x][y] = 0;

    q.push(make_pair(x, y));
    while(! q.empty())
    {
        temp = q.front();
        q.pop();
        for(int i = 0; i < 8; i++)
		{
            nx = temp.fi + dx[i];
            ny = temp.se + dy[i];
            if(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX)
            {
                if(dis[nx][ny] > dis[temp.fi][temp.se] + 1)
                {
                    dis[nx][ny] = dis[temp.fi][temp.se] + 1;
                    q.push(make_pair(nx, ny));
                }

            }
        }
    }
}
int main()
{
    pre_cal();
	int cases = 1, i, j;
	while(scanf("%d", &n), n)
    {
		for(i = 0; i < n; ++i) scanf("%lld %lld", &knight_x[i], &knight_y[i]);
		for(i = 0; i < n; ++i) scanf("%lld %lld", &target_x[i], &target_y[i]);
		for(i = 0; i < n; ++i)
			for(j = 0; j < n; ++j)
				mp[i][j] = reduce(abs(knight_x[i] - target_x[j]), abs(knight_y[i] - target_y[j]));

		for(i = 0; i < n; ++i)
			for(j = 0; j < (1 << n); ++j) dp[i][j] = inf;

		printf("%d. %lld\n", cases++, bitmask(0, 0));
	}
	return 0;
}