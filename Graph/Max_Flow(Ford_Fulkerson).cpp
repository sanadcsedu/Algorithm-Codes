/******************************
*	Sanad Saha            *
*	University of Dhaka   *
******************************/

#include<bits/stdc++.h>

#define EPS 1e-9
#define pb push_back
#define mp make_pair
#define ins insert
#define fi first
#define se second
#define pi acos(-1.0)
#define mod 100000007
#define inf 100000000
#define ll long long int
#define sss stringstream
#define oss ostringstream
#define iss istringstream
#define llu long long unsigned

#define _sq(a) (a)*(a)
#define sz(a) ((int)a.size())
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define _max3(a, b, c) max(a, max(b, c))
#define _min3(a, b, c) min(a, min(b, c))
#define FOR(i, n) for(i=0; i<(int)n; i++)
#define FOR1(i, n) for(i=1; i<=(int)n; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define _set(a) memset(a,-1,sizeof(a))
#define FORI(i, a, b) for(i=a; i>=(int)b; i--)
#define FORab(i, a, b) for(i=a; i<=(int)b; i++)
#define popcount(n) __builtin_popcount(n)
#define popcountl(n) __builtin_popcountll(n)
#define ctz(x) __builtin_ctz(x) //number of trailing zeroes in a digit
#define ctzl(x) __builtin_ctzll(x)
#define clz(x) __builtin_clz(n)
#define clzl(x) __builtin_clzll(x) //number of leading zeroes in a digit
#define sort_rev(a) sort(a.rbegin(), a.rend())
#define sort_all(a) sort(a.begin(), a.end())
#define dis_twopoints(x1,y1,x2,y2) sqrt(_sq(x1-x2) + _sq(y1-y2))
#define area(a,b,c) (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y))
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)

//If Long Long (mask & (1LL << k))
#define check(mask, k) (mask & (1 << k))
#define set1(mask, k) (mask | (1 << k))
#define set0(mask ,k) (mask & (~(1<<k)))

#define SD(a) scanf("%d",&a)
#define SLF(a) scanf("%lf",&a)
#define SC(a) scanf("%c",&a)
#define SS(a) scanf("%s",a)
#define SLLD(a) scanf("%lld", &a)
#define Si64(a) scanf("%I64d", &a)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

using namespace std;

typedef pair <int, int> pii;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <double> vd;
typedef vector <string> vs;
typedef vector <vi> vvi;
typedef map<string , int> msi;
typedef map<int , int> mii;
typedef map<char , int> mci;
typedef map<int, string> mis;
typedef set<int> si;
typedef set<string> ss;

//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};

#define MAX 105

int flow[MAX][MAX];
int capacity[MAX][MAX];
int parent[MAX];
bool vis[MAX];
vector <int> edge[MAX];
int n;
bool BFS(int source, int dest)
{
    int u, v, i;
    mem(vis);
    queue<int > q;
    vis[source] = true;
    q.push(source);
    while(!q.empty())
    {
        u = q.front();
        if(u == dest) return true;
        q.pop();
        for(i=0; i< sz(edge[u]); i++)
        {
            v = edge[u][i];
            if(!vis[v] && (capacity[u][v] - flow[u][v] > 0))
            {
                q.push(v);
                parent[v] = u;
                vis[v] = true;
            }
        }
    }
    return false;
}
int ford_fulkerson(int source, int dest)
{
    int u, v, inc, max_flow;
    max_flow = 0;
    while(BFS(source, dest))
    {
        inc = inf;
        for(v = dest; parent[v] > 0 ; v = parent[v])
        {
            u = parent[v];
            inc = min(inc, capacity[u][v] - flow[u][v]);
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
int main()
{
    //READ("input.txt");
    //ios_base::sync_with_stdio(false);
    int source, dest, m, u, v, c, tcase=1, ans, i;
    while(scanf("%d", &n) && n)
    {
        FOR(i, n+2) edge[i].clear();

        scanf("%d %d %d", &source, &dest, &m);
        mem(capacity);
        mem(flow);
        mem(parent);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d", &u, &v, &c);

            edge[u].pb(v);
            edge[v].pb(u);

            capacity[u][v] += c;
            capacity[v][u] += c;
        }
        ans = ford_fulkerson(source, dest);
        printf("Network %d\n", tcase++);
        printf("The bandwidth is %d.\n\n", ans);
    }
    return 0;
}


