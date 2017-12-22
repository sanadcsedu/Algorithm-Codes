/******************************
*	Sanad Saha            *
*	University of Dhaka   *
******************************/
//source: http://codeforces.com/blog/entry/3327

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
#define inf 2147483647
#define ll long long int
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
typedef vector <int> vi;
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

int N, n;
int t_max[200005][20];
int t_min[200005][20];
int a[200005];

//max
void init_max() {
  for (int x = 0; x < N; x++)
    t_max[x][0] = a[x];
  for (int y = 1; y <= n; y++)
    for (int x = 0; x < N; x+=(1<<y))
      t_max[x][y] = max(t_max[x][y-1], t_max[x+(1<<(y-1))][y-1]);
}

void set_max(int x, int v) {
  t_max[x][0] = a[x] = v;
  for (int y = 1; y <= n; y++) {
    int xx = x-(x&((1<<y)-1));
    t_max[xx][y] = max(t_max[xx][y-1], t_max[xx+(1<<(y-1))][y-1]);
  }
}

int get_max(int i, int j) {
  int res = -inf , h = 0; j++;
  while (i+(1<<h) <= j) {
    while ((i&((1<<(h+1))-1)) == 0 && i+(1<<(h+1)) <= j) h++;
    res = max(res, t_max[i][h]);
    i += (1<<h);
  }
  while (i < j) {
    while (i+(1<<h) > j) h--;
    res = max(res, t_max[i][h]);
    i += (1<<h);
  }
  return res;
}

//min
void init_min() {
  for (int x = 0; x < N; x++)
    t_min[x][0] = a[x];
  for (int y = 1; y <= n; y++)
    for (int x = 0; x < N; x+=(1<<y))
      t_min[x][y] = min(t_min[x][y-1], t_min[x+(1<<(y-1))][y-1]);
}

void set_min(int x, int v) {
  t_min[x][0] = a[x] = v;
  for (int y = 1; y <= n; y++) {
    int xx = x-(x&((1<<y)-1));
    t_min[xx][y] = min(t_min[xx][y-1], t_min[xx+(1<<(y-1))][y-1]);
  }
}

int get_min(int i, int j) {
  int res = inf, h = 0; j++;
  while (i+(1<<h) <= j) {
    while ((i&((1<<(h+1))-1)) == 0 && i+(1<<(h+1)) <= j) h++;
    res = min(res, t_min[i][h]);
    i += (1<<h);
  }
  while (i < j) {
    while (i+(1<<h) > j) h--;
    res = min(res, t_min[i][h]);
    i += (1<<h);
  }
  return res;
}

int main()
{
    //READ("input.txt");
    int i, z, L , R, Q;
    double aa, bb, d;
    while(SD(N)!= EOF)
    {
        n = log2(N);
        //cout << n << endl;
        FOR(i, N)
             SD(a[i]);

        init_max();
        init_min();

        SD(Q);
        FOR(i, Q)
        {
            SD(L);
            SD(R);
            aa = max(get_max(0, L-1), get_max(R+1, N-1));
            d = get_min(L, R);
            aa += d;
            bb = (get_max(L, R) - d)/2.0 + d;
            printf("%.1lf\n", max(aa, bb));
        }
    }
    return 0;
}
