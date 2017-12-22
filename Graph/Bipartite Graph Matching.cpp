#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int vis[400];
int main()
{
    int n, i, j, a, b, u, v;
    vector <int> edges[500];
    queue <int > Q;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<=n;i++)edges[i].clear();
        for(;;)
        {
             scanf("%d %d",&a,&b);
             if(a==0 && b==0)break;
             edges[a].push_back(b);
             edges[b].push_back(a);
        }
        while(!Q.empty())Q.pop();
        memset(vis, 0, sizeof(vis));
        bool bipartite = true;
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                Q.push(i);
                vis[i] = 1;
                while(!Q.empty())
                {
                    u = Q.front();
                    Q.pop();
                    for(j=0; j< (int)edges[u].size(); j++ )
                    {
                        v = edges[u][j];
                        if(!vis[v])
                        {
                            vis[v] = 3 - vis[u];
                            Q.push(v);
                        }
                        else if( vis[u] == vis[v] && u!=v)bipartite = false;
                    }
                    if(!bipartite)break;
                }
            }
            if(!bipartite)break;
        }
        if(bipartite)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
