#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<string.h>
using namespace std;
#define MAX 10000
#define inf 10000000
vector <int > edge[MAX], cost[MAX], seq, G[MAX];
int dis[MAX];
bool vis[MAX];
int parent[MAX];
struct data
{
    int to, weight;
    data(){}
    data(int t, int w) : to(t), weight(w){}
    bool operator < (const data& p) const
    {
        return weight > p.weight;
    }
}temp;
priority_queue<data> pq;

int MST_Prims( int n)
{
    pq.push(data(1, 0));

    int i, v;
    for(i=0; i<=n; i++) dis[i] = inf;

    dis[1] = 0;
    int sum = 0;
    while(!pq.empty())
    {
        temp = pq.top();
        pq.pop();
        if( vis[temp.to] ) continue;
        seq.push_back(temp.to);
        vis[temp.to] = true;
        sum += temp.weight;
        for(i=0; i<(int)edge[temp.to].size(); i++)
        {
            v = edge[temp.to][i];

            if(!vis[v] && cost[temp.to][i] < dis[v])
            {
                dis[v] = cost[temp.to][i];
                pq.push(data(v, dis[v]));
                parent[v] = temp.to;
            }
        }
    }
    return sum;
}

int MST_second_best( int n, int a, int b)
{
    while (!pq.empty()) pq.pop();
    pq.push(data(1, 0));

    int i, v;

    memset(vis, false, sizeof(vis));
    for(i=0; i<=n; i++) dis[i] = inf;

    dis[1] = 0;
    int sum = 0;
    while(!pq.empty())
    {
        temp = pq.top();
        pq.pop();
        if( vis[temp.to] ) continue;
        vis[temp.to] = true;
        sum += temp.weight;
        for(i=0; i<(int)edge[temp.to].size(); i++)
        {
            v = edge[temp.to][i];
            if((temp.to == a && v == b) || (temp.to == b && v == a)) continue;

            if(!vis[v] && cost[temp.to][i] < dis[v])
            {
                dis[v] = cost[temp.to][i];
                pq.push(data(v, dis[v]));
            }
        }
    }
    return sum;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, i, u, v, w;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> u >> v >> w;
        edge[u].push_back(v);
        edge[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    int ans = MST_Prims(n);
    cout << "Minimum Cost : " << ans << endl;
    cout << "Tree: " ;
    int _min2 = inf;
    for(i=1; i< seq.size(); i++)
    {
        printf("%d-%d ", parent[seq[i]], seq[i]);
        _min2 = min(_min2, MST_second_best(n, parent[seq[i]], seq[i]));
    }
    puts("");
    if(_min2 == ans) cout << "Not Unique" << endl;
    else cout << "Unique" << endl;
    return 0;
}
