#include<bits/stdc++.h>
using namespace std;
#define MAX 110
#define inf 1000000000

int n;
int cap[MAX][MAX];
int flow[MAX][MAX];
int parent[MAX];
bool vis[MAX];
vector <int> edge[MAX];

bool BFS(int source, int dest)
{
    int u, v, i;
    memset(vis, 0, sizeof(vis));
    queue<int > q;
    vis[source] = true;
    q.push(source);
    while(!q.empty())
    {
        u = q.front();
        if(u == dest) return true;
        q.pop();
        for(i=1; i<=n; i++)
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
int Edmond_Karp(int source, int dest)
{
    int u, v, inc, max_flow;
    max_flow = 0;
    memset(flow, 0, sizeof(flow));
    while(BFS(source, dest))
    {
        inc = inf;
        for(v = dest; parent[v] > 0 ; v = parent[v])
        {
            u = parent[v];
            inc = min(inc, cap[u][v] - flow[u][v]);
        }
        for(v = dest; parent[v] > 0 ; v = parent[v])
        {
            u = parent[v];
            flow[u][v] += inc;
            flow[v][u] -= inc;
        }
        max_flow += inc;
    }
    return max_flow;
}
void DFS(int u)
{
    vis[u] = 1;
    int v, i;
    for(i=1; i<=n; i++)
    {
        v = i;
        if(!vis[v] && (cap[u][v] - flow[u][v]) > 0 && flow[u][v] && cap[u][v])
            DFS(v);
    }
}
void Mincut()
{
    int u, v;
    for(u=1; u<=n; u++)
    {
        if(!vis[u]) continue;
        for(v=1; v<=n; v++)
        {
            if(!vis[v] && (flow[u][v] == cap[u][v] ) && cap[u][v]) printf("%d %d\n", u, v);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int m, a, b, i, cost;
    while(scanf("%d %d", &n, &m))
    {
        if(n == 0 && m == 0) break;
        memset(cap, 0, sizeof(cap));
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d", &a, &b, &cost);
            cap[a][b] = cost;
            cap[b][a] = cost;
        }
        Edmond_Karp(1, 2);
        memset(vis, 0, sizeof(vis));
        DFS(1);
        Mincut();
        printf("\n");
    }
    return 0;
}
