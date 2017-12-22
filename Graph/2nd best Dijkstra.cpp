#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>
#define inf 10000000
using namespace std;
struct edge
{
    int to, weight;
    edge(){}
    edge(int t, int w):to(t), weight(w){}
    bool operator<(const edge &p)const
    {
        return weight > p.weight;
    }
}temp;
priority_queue<edge> pq;
vector <edge> e[100];
int dis[110], dis2[110];
void dijkstra(int s)
{
    int u, v, i, w;
    dis[s] = 0;
    pq.push(edge(s, 0));
    while(!pq.empty())
    {
        temp = pq.top();
        pq.pop();
        u = temp.to;
        for(i=0; i<(int)e[u].size(); i++)
        {
            v = e[u][i].to;
            w = e[u][i].weight;
            if(dis[v]>dis[u]+w)
            {
                if(dis[v]==inf)
                {
                    dis[v]=dis[u]+w;
                    pq.push(edge(v, dis[v]));
                }
                else
                {
                    dis2[v] = min(dis[v], dis2[v]);
                    dis[v]=dis[u]+w;
                    pq.push(edge(v, dis[v]));
                    pq.push(edge(v, dis2[v]));
                }
            }
            else
            {
                if(dis2[v]>temp.weight+w && dis[v]<temp.weight+w)
                {
                    dis2[v] =  temp.weight +w;
                    pq.push(edge(v, dis2[v]));
                }
            }
        }
    }
}
void reset(int n)
{
    int i;
    for(i=0; i<=n ;i++)
    {
        dis[i]=inf;
        dis2[i] = inf;
    }
}
int main()
{
    int n,m,a,b,w,i,q,start,end, tcase=1;
    while(scanf("%d %d", &n,&m)!=EOF)
    {
        for(i=0; i<=n; i++)
        e[i].clear();
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            e[a].push_back(edge(b,w));
            e[b].push_back(edge(a,w));
        }
        scanf("%d", &q);
        printf("Set #%d\n", tcase++);
        for(i=0; i<q; i++)
        {
            reset(n);
            scanf("%d %d", &start, &end);
            dijkstra(start);
            if(dis2[end]==inf)printf("?\n");
            else printf("%d\n", dis2[end]);
        }
    }
    return 0;

}
