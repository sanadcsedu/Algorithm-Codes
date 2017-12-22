#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<deque>
#include<set>
#include<string>
#define MAX 1000005
#define pi acos(-1.0)
#define inf 2147483647
#define ll long long int
#define EPS 1e-9
#define mod 100000007
using namespace std;
vector <int> res;
vector <int> G[MAX];
bool cycle ;
int vis[MAX], ans[MAX];
void DFS(int u)
{
    int v, i;
    vis[u] = 2;
    for(i=0; i<(int)G[u].size(); i++)
    {
        v = G[u][i];
        if(vis[v]==0)DFS(v);
        if(vis[v]==2)
        {
            cycle = true;
            return;
        }
    }
    res.push_back(u);
    vis[u] = 1;
}
void reset(int n)
{
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<=n; i++)
            G[i].clear();
    res.clear();
    memset(ans, 0, sizeof(ans));
}
int main()
{
    int n, m, a, b, i, z;
    while(cin >> n >> m)
    {
        if(n==0 && m==0)break;
        reset(n);
        for(i=0; i<m; i++)
        {
            cin >> a >> b;
            G[a].push_back(b);
        }
        cycle = false;
        for(i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                DFS(i);
                if(cycle)break;
            }
        }
        if(cycle)printf("IMPOSSIBLE\n");
        else
        {
            z = res.size();
            for(i=0; i<z; i++)
                ans[i] = res[i];
            reverse(ans, ans+n);
            for(i=0; i<n; i++)
                cout << ans[i] << endl;
        }
    }
    return 0;
}

