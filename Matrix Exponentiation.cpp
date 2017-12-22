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
#define inf 2147483647
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
#define sort_rev(a) sort(a.rbegin(), a.rend())
#define sort_all(a) sort(a.begin(), a.end())
#define dis_twopoints(x1,y1,x2,y2) sqrt(_sq(x1-x2) + _sq(y1-y2))
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

#define MAX 505

struct matrix
{
    ll mat[16][16];
};
ll f[16];
ll n, m;
int d;
matrix operator *(matrix &a, matrix &b)
{
    matrix ret;
    int i, j, k;
    for(i=0; i<d; i++)
    {
        for(j=0; j<d; j++)
        {
            ret.mat[i][j] = 0;
            for(k=0; k<d; k++)
            {
                ret.mat[i][j] = (ret.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % m;
            }
        }
    }
    return ret;
}
matrix operator ^ (matrix b, ll p)
{
    if(p == 1) return b;
    matrix ret = b ^ (p/2);
    ret = ret * ret;
    if(p&1) ret = ret * b;
    return ret;
}
int main()
{
    //READ("input.txt");
    //ios_base::sync_with_stdio(false);
    matrix _mm, res;
    //memset(_mm.mat, 0, sizeof(_mm.mat));
    int i;
    ll ans;
    while(scanf("%d %lld %lld", &d, &n, &m))
    {
        if(d+n+m == 0) return 0;
        memset(_mm.mat, 0, sizeof(_mm.mat));
        for(i=0; i<d; i++)
        {
            scanf("%lld", &_mm.mat[0][i]);
            if(i) _mm.mat[i][i-1] = 1;
        }
        for(i=d-1; i>=0; i--) scanf("%lld", &f[i]);

        if(n <= d)
        {
            printf("%lld\n", f[d-n]);
        }
        else
        {
            ans = 0;
            res = _mm ^ (n-d);
            for(i=0; i<d; i++)
            {
                ans = (ans + f[i] * res.mat[0][i]) % m;
            }
            printf("%lld\n", ans);
        }

    }
    return 0;
}



