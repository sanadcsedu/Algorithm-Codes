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
#include<sstream>

#define EPS 1e-9
#define MAX 100000
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

int discovery[MAX], low[MAX];
bool vis[MAX];
vector<int>G[MAX];
//pair <int, int > pii;
vector < pair <int, int > > ans;
int dfs_time ;

void Bridge(int u, int parent)
{
    int v;
    discovery[u] = low[u] = dfs_time++;
    vis[u] = 1;
    for(int i=0; i<(int)G[u].size(); i++)
    {
        v = G[u][i];
        if(v == parent)continue;
        if(!vis[v])
        {
            Bridge(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > discovery[u])
            {
                int x = u, y = v;
                if(x>y) swap(x, y);
                ans.push_back(make_pair(x,y));
            }
        }
        else low[u] = min(low[u], discovery[v]);
    }
}
void reset(int n)
{
    mem(vis);
    mem(discovery);
    mem(low);
    for(int i=0; i<=n; i++)
        G[i].clear();
    ans.clear();
}
int main()
{
    int i, tcase, t, x, n, m, y;
    scanf("%d", &tcase);
    for(t=0; t<tcase; t++)
    {
        scanf("%d", &n);
        reset(n);
        string s;
        for(int j=0; j<n; j++)
        {
            cin >> x >> s;

            s.erase(s.begin());
            s.erase(s.end()-1);
            istringstream sin(s);
            sin >> m;

            for(i=0; i<m; i++)
            {
                scanf("%d", &y);
                G[x].push_back(y);
                G[y].push_back(x);
            }
        }
        dfs_time = 0;
        for(i=0; i<n; i++)
        {
            if(!vis[i])
            {
                Bridge(i, -1);
            }
        }
        printf("Case %d:\n", t+1);
        cout<<ans.size()<<" critical links"<<endl;
        sort(ans.begin(), ans.end());
        for(i=0; i<ans.size(); i++)
        {
            printf("%d - %d\n", ans[i].first, ans[i].second);
        }
        //puts("");
    }
    return 0;
}
