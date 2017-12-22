/******************************
*	Sanad Saha            *
*	University of Dhaka   *
******************************/

#include<bits/stdc++.h>

#define EPS 1e-9
#define MAX 505
#define pb push_back
#define mp make_pair
#define ins insert
#define x first
#define y second
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
#define _max3(a,b,c) max(a, max(b,c))
#define _min3(a,b,c) min(a, min(b,c))
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


inline bool within_rect(pdd d , pdd b, pdd p , pdd q)
{
   int _maxx, _maxy, _minx, _miny;
   _maxx=max(d.x, b.x);
   _maxy=max(d.y, b.y);
   _minx=min(d.x, b.x);
   _miny=min(d.y, b.y);
   if(p.x>=_minx && p.x<=_maxx && p.y>=_miny && p.y<=_maxy && q.x>=_minx && q.x<=_maxx && q.y>=_miny && q.y<=_maxy) return true;
   return false;
}
inline double direction(pdd a, pdd b, pdd c)
{
    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}

/*inline double direction(pdd a, pdd b, pdd c) // computes area of tringle area,if 0,then same line
{
   double area = a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
   return area;
}*/

inline bool on_segment(pdd a, pdd b, pdd c)
{
    double _minx, _miny, _maxx, _maxy;
    _minx = min(a.x, b.x);
    _miny = min(a.y, b.y);
    _maxx = max(a.x, b.x);
    _maxy = max(a.y, b.y);
    if(c.x>=_minx && c.x<=_maxx && c.y>=_miny && c.y<=_maxy) return true;
    else return false;
}
inline bool intersect(pdd p, pdd q, pdd a, pdd b)
{
    double d1, d2, d3, d4;
    d1 = direction(a, b, p);
    d2 = direction(a, b, q);
    d3 = direction(p, q, a);
    d4 = direction(p, q, b);

    if(d1*d2 < 0 && d3*d4 < 0) return true;
    else if(d1 == 0 && on_segment(a, b, p)) return true;
    else if(d2 == 0 && on_segment(a, b, q)) return true;
    else if(d3 == 0 && on_segment(p, q, a)) return true;
    else if(d4 == 0 && on_segment(p, q, b)) return true;
    else return false;
}
int main()
{
    //READ("input.txt");
    int tcase;
    SD(tcase);
    bool ans;
    pdd a, b, c, d, p, q;
    while(tcase--)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p.x, &p.y, &q.x, &q.y, &d.x, &d.y, &b.x, &b.y);
        a.x = d.x, a.y = b.y;
        c.x = b.x, c.y = d.y;
        if(intersect(p, q, a, b)) ans = true;
        else if(intersect(p, q, b, c)) ans = true;
        else if(intersect(p, q, c, d)) ans = true;
        else if(intersect(p, q, d, a))ans = true;
        else if(within_rect(d, b, p, q)) ans = true;
        else ans = false;

        if(ans)printf("T\n");
        else printf("F\n");
    }
	return 0;
}



