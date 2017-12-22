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
#define MAX 1000000
#define pi acos(-1.0)
#define inf 2147483647
#define ll long long int
#define EPS 1e-9
#define mod 100000007
using namespace std;
int vis[30];
char a[30], b[30], input[30][30];
vector <int> edge[30], redge[30], topsort;
map <string, int> name;
void DFS1(int u)
{
    int v, i;
    vis[u] = 1;
    for(i=0; i<(int)edge[u].size(); i++)
    {
        v = edge[u][i];
        if(vis[v]==0)DFS1(v);
    }
    topsort.push_back(u);
}
void DFS2(int u)
{
    int i, v;
    vis[u] =  0;
    for(i=0; i<(int)redge[u].size(); i++)
    {
        v = redge[u][i];
        if(vis[v])
        {
            printf(", %s", input[v]);
            DFS2(v);
        }
    }
}
void reset()
{
    for(int i=0; i<30; i++)
    {
        edge[i].clear();
        redge[i].clear();
    }
    name.clear();
    topsort.clear();
    memset(vis, 0, sizeof(vis));
    memset(input, 0, sizeof(input));
}
int main()
{
    int t, n, m, i, k;
    for(t=1;;t++)
    {
        scanf("%d %d", &n, &m);
        if(n==0 && m==0)break;
        reset();
        for(i=0, k=1 ; i<m; i++)
        {
            scanf("%s %s", a, b);
            if(!name[a])
            {
                name[a] = k++;
                strcpy(input[name[a]], a);
            }
            if(!name[b])
            {
                name[b] = k++;
                strcpy(input[name[b]], b);
            }
            edge[name[a]].push_back(name[b]);
            redge[name[b]].push_back(name[a]);
        }
        for(i=1; i<k; i++)
            if(!vis[i])DFS1(i);
        if(t>1)printf("\n");
        printf("Calling circles for data set %d:\n", t);
        for(i=topsort.size()-1; i>=0; i--)
        {
            if(vis[topsort[i]])
            {
                printf("%s", input[topsort[i]]);
                DFS2(topsort[i]);
                printf("\n");
            }
        }
    }
    return 0;
}
