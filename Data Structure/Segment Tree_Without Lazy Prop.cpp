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
#define MAX 100005

int tree[MAX*3];
int a[MAX];

void init(int node, int l, int r )
{
	if(l == r)
	{
		tree[node] = a[l];
		return;
	}
	int left, right, mid;
	left = node * 2;
	right = node * 2 + 1;
	mid = (l + r) / 2;
	init(left, l, mid);
	init(right, mid + 1, r);
	tree[node] = tree[left] + tree[right];
}
int query(int node, int l, int r , int i, int j)
{
	if(i > r || j < l) return 0;
	if(l >= i && r <= j) return tree[node];
	int left, right, mid, ret1, ret2;
	left = node * 2;
	right = node * 2 + 1;
	mid = (l + r)/ 2;
	ret1 = query(left, l, mid, i, j);
	ret2 = query(right, mid + 1, r , i, j);
	return ret1 + ret2;
}
void update2(int node, int l, int r, int i, int newvalue)
{
	if(i > r || i < l) return;
	if(l >= i && r <= i)
	{
		tree[node] += newvalue;
		return ;
	}
	int left, right, mid;
	left = node * 2;
	right = node * 2 + 1;
	mid = (l + r)/ 2;
	update2(left, l, mid, i, newvalue);
	update2(right, mid + 1, r , i, newvalue);
	tree[node] = tree[left] + tree[right];
}
void update1(int node, int l, int r, int i, int newvalue)
{
	if(i > r || i < l) return;
	if(l >= i && r <= i)
	{
		tree[node] -= newvalue;
		return ;
	}
	int left, right, mid;
	left = node * 2;
	right = node * 2 + 1;
	mid = (l + r)/ 2;
	update1(left, l, mid, i, newvalue);
	update1(right, mid + 1, r , i, newvalue);
	tree[node] = tree[left] + tree[right];
}
int main()
{
    //READ("input.txt");
    //ios_base::sync_with_stdio(false);
    int aa, b, t, tcase, n, i, q, ch, v, get;
    SD(tcase);
    FOR1(t, tcase)
    {
		SD(n);
		SD(q);
		FOR(i, n)SD(a[i]);
		init(1, 0, n-1);
		printf("Case %d:\n", t);
		FOR(i, q)
		{
			SD(ch);
			if(ch == 1)
			{
				SD(aa);
				get = query(1, 0, n-1, aa, aa);
				update1(1, 0, n-1, aa, get);
				printf("%d\n", get);
			}
			else if(ch == 2)
			{
				SD(aa), SD(v);
				update2(1, 0, n-1, aa, v);
			}
			else
			{
				SD(aa), SD(b);
				printf("%d\n", query(1, 0, n-1, aa, b));
			}
		}
	}
    return 0;
}
