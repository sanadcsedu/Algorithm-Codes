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
#define pi acos(-1.0)
#define mod 100000007
#define inf 2147483647
#define ll long long int

#define FOR(i, n) for(i=0; i<n; i++)
#define FOR1(i, n) for(i=1; i<=n; i++)
#define mem(a) memset(a, 0, sizeof(a));
#define FORI(i, a, b) for(i=a; i>=b; i--)
#define FORab(i, a, b) for(i=a; i<=b; i++)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

using namespace std;
int x[9], lineCounter, a, b;
bool place(int q, int row)
{
    for(int i = 1; i<=q-1; i++)
    {
        if(x[i]==row || (fabs(x[i]-row) == fabs(i - q)))
            return false;
    }
    return true;
}
void backtrack(int queen)
{
    for (int row = 1; row <= 8; row++)
    if (place(queen, row))
    {
        x[queen] = row;
        if (queen == 8 && x[b] == a)
        {
            printf("%2d      %d", ++lineCounter, x[1]);
            for (int j = 2; j <= 8; j++) printf(" %d", x[j]);
            printf("\n");
        }
        else
        backtrack(queen + 1);
    }
}
int main()
{
    int tcase;
    scanf("%d", &tcase);
    while(tcase --)
    {
        scanf("%d %d", &a, &b);
        mem(x);
        lineCounter = 0;
        //x[b] = a;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(1);
        if(tcase)puts("");
    }
	return 0;
}
