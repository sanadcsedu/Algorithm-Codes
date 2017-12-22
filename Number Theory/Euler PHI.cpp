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

//phi(n) = n*(1-1/p1)*(1-1/p2)....(1-1/pm)    ….[n = (p1^c1)*(p2^c2)...(pm^cm)]
int phi[MAX] ;
void sievePHI(){

    long long i,j;
    for( i=2;i<MAX;i++)
    {
        if( phi[i]==0)
        {
            phi[i] = i-1;
            for( j = i*2; j<MAX; j+=i)
            {
                if( phi[j] == 0 )phi[j] = j;

                phi[j] /= i ;

                phi[j] *= (i-1) ;
            }
        }
    }
}

int main()
{
    sievePHI();
	return 0;
}
