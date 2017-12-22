/******************************
*	Sanad Saha            *
*	University of Dhaka   *
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
#define MAX 100005
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

struct data
{
    int _max, _min;

}tree[MAX*3];

int a[MAX];

void init(int node, int l, int r)
{
    if(l == r)
    {
        tree[node]._max = a[l];
        tree[node]._min = a[l];
        return;
    }
    int left, right, mid;
    left = node << 1 ;
    right = left + 1;
    mid = (l + r) >> 1;
    init(left, l, mid);
    init(right, mid+1, r);
    tree[node]._max = max(tree[left]._max, tree[right]._max);
    tree[node]._min = min(tree[left]._min, tree[right]._min);

    return;
}
int min_query(int node , int l ,int r, int i, int j)
{
    if(i > r || j < l) return inf;
    if(l >= i && r <= j) return tree[node]._min;
    int left , right, mid, ret1, ret2;

    left = node << 1;
    right = left + 1;
    mid = (l + r) >> 1;

    ret1 = min_query(left, l, mid, i, j);
    ret2 = min_query(right, mid + 1, r, i, j);
    return min(ret1 , ret2);

}
int max_query(int node , int l ,int r, int i, int j)
{
    if(i > r || j < l) return -inf;
    if(l >= i && r <= j) return tree[node]._max;
    int left , right, mid, ret1, ret2;

    left = node << 1;
    right = left + 1;
    mid = (l + r) >> 1;

    ret1 = max_query(left, l, mid, i, j);
    ret2 = max_query(right, mid + 1, r, i, j);
    return max(ret1 , ret2);
}
int main()
{
    //READ("input.txt");
    //ios_base::sync_with_stdio(false);
    int t, tcase, n, d, i, j, ans;
    SD(tcase);
    FOR1(t, tcase)
    {
        scanf("%d %d", &n , &d );
        //mem(tree);

        for(i=1; i<=n; i++)
            SD(a[i]);

        init(1, 1, n);

        ans = -inf;

        for(i=1; i<=n; i++)
        {
            j = max(1, i + d - 1);
            ans = max(ans, max_query(1, 1, n, i, j) -  min_query(1, 1, n, i, j));
        }

        printf("Case %d: %d\n", t, ans);

    }
    return 0;
}
