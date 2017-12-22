/******************************
*	Sanad Saha                *
*	University of Dhaka       *
******************************/


#include<set>
#include<map>
#include<list>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<bitset>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

#define EPS 1e-9
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define mod 100000007
#define inf 1 << 25
#define ll long long int
#define llu long long unsigned

#define sz(a) ((int)a.size())
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define FOR(i, n) for(i=0; i<n; i++)
#define FOR1(i, n) for(i=1; i<=n; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define _set(a) memset(a,-1,sizeof(a))
#define all(a) sort(a.begin(), a.end())
#define FORI(i, a, b) for(i=a; i>=b; i--)
#define FORab(i, a, b) for(i=a; i<=b; i++)
#define popcount(n) __builtin_popcount(n)
#define popcountl(n) __builtin_popcountll(n)
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
#define SLLU(a) scanf("%llu", &a)
#define Si64(a) scanf("%I64d", &a)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

using namespace std;

typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef map<string , int> msi;
typedef map<int , int> mii;
typedef map<int, string> mis;
typedef set<int> si;
typedef set<string> ss;

#define MAX 250
using namespace std;

struct edge
{
    int from, to, weight;
    edge (){}
    edge(int f, int t, int w):from(f) , to(t), weight(w){}
};
vector <edge> e;

int dis[MAX];
int x[MAX];
bool neg[MAX];

void reset()
{
    for(int i=0; i<205; i++)
    {
        dis[i] = inf;
    }
    e.clear();
}
int main()
{
    //READ("input.txt");
    int tcase, u, v, w, a, b, i, n, m, j, q, t;
    scanf("%d", &tcase);
    for(t=0; t<tcase; t++)
    {
        reset();
        SD(n);
        FOR1(i, n)
            SD(x[i]);

        SD(m);
        for(i=0; i<m; i++)
        {
            scanf("%d %d", &a, &b);
            w = pow((x[b]-x[a]), 3);

            e.pb(edge(a, b, w));
        }

        dis[1] = 0;

        for(i=1; i<=(n-1); i++)
        {
            for(j=0; j<sz(e) ; j++)
            {
                if(dis[e[j].from] != inf)
                dis[e[j].to] = min(dis[e[j].to], dis[e[j].from] + e[j].weight );
            }
        }

        memset(neg, true, sizeof(neg));

        for(j=0; j<sz(e) ; j++)
        {
                if(dis[e[j].to] > dis[e[j].from] + e[j].weight )
                    neg[e[j].to] = false;
                else neg[e[j].to] = true;
        }
        SD(m);
        printf("Case %d:\n", t+1);
        FOR(i, m)
        {
            SD(v);
            if (dis[v]==inf || dis[v] < 3 || !neg[v])
                cout << "?" << endl;
            else cout << dis[v] << endl;
        }

    }
    return 0;
}
