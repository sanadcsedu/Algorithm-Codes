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

#define MAX 555

struct point
{
  double x, y;
} P[MAX], C[MAX], P0;

bool com(point a, point b)
{
    double d = area(P0, a, b);
    if(d<0) return false;
    if(d==0 && dis_twopoints(P0.x,P0.y, b.x, b.y) < dis_twopoints(P0.x,P0.y, a.x, a.y)) return false;
    return true;
}

int convexhull(int np)	//gets num of points,returns num of elements on convex hull
{
	int i,nc,pos = 0;
	for(i=1; i<np; i++)
		if( P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
            pos = i;
	swap(P[0], P[pos]);
	P0 = P[0];
	sort(P+1, P+np, com);
	C[0] = P[0];
	if(np>=2)    C[1] = P[1];
	for(i = nc = 2 ; i < np; i++)
	{
		while(nc>=2 && area(C[nc-2], C[nc-1], P[i]) <= 0) nc--;
		C[nc++] = P[i];
	}
	return nc;
}

int main()
{
    //READ("input.txt");
	int n , i, tcase, t;
	SD(tcase);
	printf("%d\n", tcase);
	for(t=1;t<=tcase;t++)
	{
		SD(n);
		FOR(i, n)
		{
            SLF(P[i].x);
            SLF(P[i].y);
		}
		int nc = convexhull(n);
        printf("%d\n", nc+1);

		for(i=0; i<nc; i++)
			printf("%.0lf %.0lf\n",C[i].x,C[i].y);

		if(nc!=1)   printf("%.0lf %.0lf\n",C[0].x,C[0].y);

		if(t != tcase)
        {
            SD(n);
            printf("%d\n",n);
        }

    }
	return 0;
}



