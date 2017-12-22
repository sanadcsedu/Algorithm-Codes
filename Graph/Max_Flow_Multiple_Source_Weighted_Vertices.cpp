#include<bits/stdc++.h>
using namespace std;
#define inf 1<<21
int n;
int cap[210][210];
int flow[210][210];
int parent[210];
int vis[210];
bool BFS()
{
    int u, v, i;
    memset(vis, 0, sizeof(vis));
    queue<int > q;
    vis[0] = true;
    q.push(0);
    while(!q.empty())
    {
        u = q.front();
        if(u == n) return true;
        q.pop();
        for(i=1; i<=n ; i++)
        {
            v = i;
            if(!vis[v] && (cap[u][v] - flow[u][v] > 0))
            {
                q.push(v);
                parent[v] = u;
                vis[v] = true;
            }
        }
    }
    return false;
}

int Edmond_Karp()
{
    int u, v, inc, max_flow;
    max_flow = 0;
    memset(flow, 0, sizeof(flow));
    while(BFS())
    {
        inc = inf;
        for(v = n; parent[v] > 0 ; v = parent[v])
        {
            u = parent[v];
            inc = min(inc, cap[u][v] - flow[u][v]);
        }
        for(v = n; parent[v] > 0 ; v = parent[v])
        {
            u = parent[v];
            flow[u][v] += inc;
            flow[v][u] -= inc;
        }
        max_flow += inc;
    }
    return max_flow;
}

int main()
{
    int i, tcase, t, a, b, d, cost,z , m;
    cin >> tcase;
    for(t=0; t<tcase; t++)
    {
         cin >> n;
        memset(cap, 0, sizeof(cap));

        for(i=1; i<=n; i++)
        {
            cin >> z;
            cap[i][i+n] = z;
        }
        cin >> m;
        for(i=0; i<m; i++)
        {
            cin >> a >> b >> cost;
            cap[a+n][b] = cost;
        }
        cin >> b >> d;
        for(i=0; i<b; i++)
        {
            cin >> z;
            cap[0][z] = inf;
        }
        for(i=0; i<d; i++)
        {
            cin >> z;
            cap[z+n][2*n + 1] = inf;
        }
        n = 2*n + 1;

        cout << "Case " << t+1 << ": " << Edmond_Karp() << endl;
    }
    return 0;
}
