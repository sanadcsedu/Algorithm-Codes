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
#include<sstream>
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

vector <int>G[110];
int dfs_discovery[110];
int dfs_low[110];
int dfs_root;
int deep;
bool found[110];
bool vis[110];

void Articulation_point(int u, int parent)
{
    int v, i, child;
    vis[u] = 1;
    child = 0;
    dfs_discovery[u] = dfs_low[u] = deep++;

    for(i=0; i<(int)G[u].size(); i++)
    {
        v = G[u][i];
        if(v == parent) continue;
        if(vis[v] == 0)
        {
            Articulation_point(v, u);
            child ++;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);

            if((u == dfs_root && child>1) || (u != dfs_root  && dfs_discovery[u] <= dfs_low[v]))
                found[u] = true;
        }
        else dfs_low[u] = min(dfs_low[u], dfs_discovery[v]);
    }
}
void reset(int n)
{
    mem(found);
    mem(dfs_discovery);
    mem(dfs_low);
    mem(vis);
    for(int i=0; i<=n; i++)
        G[i].clear();
}
int main()
{
    int n, x, y, i;
    string s;
    stringstream ss;
    while(scanf("%d", &n) && n)
    {
        reset(n);
        while(getline(cin , s ) && s!= "0" )
        {
            ss.clear();
            ss << s;
            ss >> x;
            while(ss >> y)
            {
                G[x].push_back(y);
                G[y].push_back(x);
            }
        }
        deep = 1;
        for(i=1; i<=n; i++)
        {
            dfs_root = i;
            if(vis[i] == 0)Articulation_point(i, -1);
        }
        int cnt = 0;
        for(i=1; i<=n; i++)
            if(found[i]) cnt++;

        cout << cnt << endl;
    }
	return 0;
}
