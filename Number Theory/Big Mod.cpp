/*
	Sanad Saha
	University of Dhaka
*/
#include<set>
#include<map>
#include<list>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

#define EPS 1e-9
#define MAX 1000000
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define mod 100000007
#define inf 2147483647
#define ll long long int
#define llu long long unsigned

#define FOR(i, n) for(i=0; i<n; i++)
#define FOR1(i, n) for(i=1; i<=n; i++)
#define mem(a) memset(a, 0, sizeof(a));
#define FORI(i, a, b) for(i=a; i>=b; i--)
#define FORab(i, a, b) for(i=a; i<=b; i++)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

using namespace std;

ll bigmod(ll b,ll p, ll m)
{
    //calculates b^p mod m in logarithmic time.
    ll x = 1,power;
    power = b%m;
    while(p)
    {
        if( p & 1 )x = (power*x)%m;
        power = (power*power)%m;
        p>>=1;
    }
    return x;
}
int main()
{
    ll B,p,M,z;
    while(scanf("%d %d %d",&B,&p,&M)!=EOF)
    {
        z = bigmod(B,p,M);
        printf("%d\n",z);
    }
    return 0;
}
