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

string seq1[103], seq2[103];

int p[200][200];
int dp[200][200];

int LIS(int i, int j)
{
    if(i < 0 || j<0) return 0;

    if(dp[i][j] != -1 )return dp[i][j];

    int ret3 = (seq1[i] == seq2[j]) ? (1 + LIS(i-1, j-1) ) : 0;
    int ret1 = LIS(i, j-1);
    int ret2 = LIS(i-1, j);

    dp[i][j] = max(ret1, max(ret2, ret3));

    if(dp[i][j] == ret1)p[i][j] = 1;
    else if(dp[i][j] == ret2) p[i][j] = 2;
    else p[i][j] = 3;

    return dp[i][j];
}

int sh(int i, int j)
{
    if(i < 0 || j < 0)return 0;

    if(p[i][j] == 1)return sh(i, j-1);
    else if (p[i][j] == 2)return sh(i-1, j);
    else if(p[i][j] == 3)
    {
        int blank = sh(i-1,j-1);
        if (blank)
            cout << " ";
        cout << seq1[i];
        return 1+blank;
    }
    return 0;
}

int main()
{
    int n1=0, n2=0;
    while(cin >> seq1[n1])
    {
        n1++;
        while(cin >> seq1[n1] && seq1[n1] != "#")
            n1++;

        while(cin >> seq2[n2] && seq2[n2] != "#")
            n2++;

        memset(dp, -1, sizeof(dp));
        mem(p);
        LIS(n1-1, n2-1);
        sh(n1-1, n2-1);
        n1 = n2 = 0;
        cout << endl;
    }
    return 0;
}
