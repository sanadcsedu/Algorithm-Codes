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

// prime factorization, returns number of divisors , remember, for factorizing n, you need prime only upto sqrt(n)
// when n = (p1^c1)*(p2^c2)...(pm^cm) ,
// sumOfDivisors = ( (p1^(c1+1)-1)/(p1-1) ) * ( (p2^(c2+1)-1)/(p2-1) ) ... ( (pm^(cm+1)-1)/(pm-1) )
int prime[MAX];
bool status[MAX];

void sieve()
{
    memset(status, true, sizeof(status));
    status[0] = status[1] = false;
    int i, j, k = 0, sq;
    sq = sqrt(MAX);
    for(i = 2; i<= sq; i++)
    {
        if(status[i])
        {
            for(j= i+i; j<MAX; j+= i)
                status[j] = false;
        }
    }
    for(i =2 ; i< MAX; i++)
        if(status[i])prime[k++] = i;
}

llu NumOfDiv(llu n)
{
    int tmp = sqrt((double)n),i ;
    llu ret = 1 ;

    for(i=0;prime[i]<=tmp;i++)
    {
        if(n % prime[i] == 0)
        {
            llu cnt =  0 ;
            while(n % prime[i] == 0)
            {
                cnt ++ ;
                n /= (llu)prime[i] ;
            }
            ret *= (cnt+1) ;
            tmp = sqrt((double)n) ;
        }
    }

    if(n>1)     ret *= 2 ;

    return ret ;
}
int main()
{
    sieve();
	return 0;
}

