#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#define inf 10000000
#define MAX 1012
using namespace std;
struct edge
{
    int to, weight;
    edge (){}
    edge(int t, int w): to(t), weight(w){}
};
vector <edge> e[MAX];
int dis[MAX];
void reset(int n )
{
    for(int i=0; i<n; i++)
    {
        dis[i] = inf;
        e[i].clear();
    }
}
int main()
{
    int tcase, u, v, w, a, b, i, n, m, j, t;
    scanf("%d", &tcase);
    for(t=0; t<tcase; t++)
    {
        scanf("%d %d", &n, &m);
        reset(n);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d", &a, &b, &w);
            e[a].push_back(edge(b, w));
        }
        edge temp;
        dis[0] = 0;
        for(i=0; i<(n-1); i++)
        {
            u = i;
            for(j=0; j<(int) e[u].size(); j++)
            {
                temp = e[u][j];
                v = temp.to;
                if(dis[v] > dis[u] + temp.weight)
                {
                    dis[v] = dis[u] + temp.weight;
                }
            }
        }
        bool flag = true;
        for(i=0; i<n; i++)
        {
            u = i;
            for(j=0; j<(int)e[u].size(); j++)
            {
                temp = e[u][j];
                v = temp.to;
                if(dis[v] > dis[u] + temp.weight)
                {
                    flag = false;
                    break;
                }
            }
            if(!flag)break;
        }
        if(!flag)printf("possible\n");
        else printf("not possible\n");

    }
    return 0;
}
