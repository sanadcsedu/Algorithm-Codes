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
#include<time.h>

#define EPS 1e-9
#define MAX 1000009
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

class TimeTracker {
    clock_t start, _end;
public:
    TimeTracker() {
        start = clock();
    }
    ~TimeTracker() {
        _end = clock();
        fprintf(stderr, "%.3lf s\n", (double)(_end - start) / CLOCKS_PER_SEC);
    }
};

int main()
{
    TimeTracker abc;
    return 0;
}

