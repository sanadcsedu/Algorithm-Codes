/******************************
*	Sanad Saha            *
*	University of Dhaka   *
******************************/

#include<bits/stdc++.h>

#define EPS 1e-9
#define MAX 1005
#define pb push_back
#define mp make_pair
#define ins insert
#define fi first
#define se second
#define pi acos(-1.0)
#define mod 1000000007
#define inf 2147483647
#define ll long long int
#define sss stringstream
#define oss ostringstream
#define llu long long unsigned

#define _sq(a) (a)*(a)
#define sz(a) ((int)a.size())
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
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

ll ncr[MAX][MAX];
ll fac[MAX];
void gen_nCr()
{
    int i, j;
    for(i=0; i<MAX; i++) ncr[i][0] = 1;
    ncr[1][1] = 1;
    for(i=2; i<MAX; i++)
        for(j=1; j<=i; j++)
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % mod;
}
void factorial()
{
    fac[0] = 1;
    for(int i=1; i<MAX; i++)
        fac[i] = (i * fac[i-1]) % mod;
}
int main()
{
	//ios_base ::sync_with_stdio(false);
	//READ("input.txt");
    gen_nCr();
    factorial();
	int t, x, y, tcase, z, i, j, m, n, k;
	scanf("%d", &tcase);
	ll ans;
	FOR(t, tcase)
	{
        scanf("%d %d %d", &n, &m, &k);
        ans = fac[n - k];
        z = -1;
        for(i = 1; i<= m-k; i++)
        {
            ans = ans + (ncr[m-k][i] * fac[n-k-i])%mod * z;
            ans = (ans + mod) % mod;
            z *= -1;
        }
        ans = (ans * ncr[m][k]) % mod;
        printf("Case %d: %lld\n", t+1, ans);
    }
	return 0;
}

