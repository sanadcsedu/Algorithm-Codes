#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

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
#define MAX 1000000
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define mod 100000007
#define inf 10000000
#define ll long long int
#define llu long long unsigned

#define sz(a) ((int)a.size())
#define FOR(i, n) for(i=0; i<n; i++)
#define FOR1(i, n) for(i=1; i<=n; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define _set(a) memset(a,-1,sizeof(a))
#define FORI(i, a, b) for(i=a; i>=b; i--)
#define FORab(i, a, b) for(i=a; i<=b; i++)

#define SD(a) scanf("%d",&a)
#define SLF(a) scanf("%lf",&a)
#define SC(a) scanf("%c",&a)
#define SS(a) scanf("%s",a)
#define SLL(a) scanf("%lld", &a)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

using namespace std;

typedef pair <int, int> pii;

//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};

string str[15];
string match;
int n;
int fre[15];
int check(int mask, int k)
{
    return mask & (1 << k);
}
int set1(int mask, int k)
{
    return mask | (1 << k);
}

int yes(int mask, int m)
{
    string temp = "";
    int i, flag, j;
    for(i=0; i<n; i++)
    {
        flag = 0;
        for(j=0; j<m; j++)
        {
            if(check(mask, j))
            {
                if(str[j][i] == '1')
                {
                    flag = 1;
                }
            }
        }
        if(flag)temp.push_back('1');
        else temp.push_back('0');
    }

    if(temp == match)return __builtin_popcount(mask);
    else return inf;
}

int backtrack(int m)
{
    int res, ans, mask, z, i;
    z = 1<<m;
    ans = inf;
    for(i=0; i<z; i++)
    {
        mask = i;
        res = yes(mask , m);
        if( res < ans ) ans = res;
    }
    return ans;
}

int main()
{
	//READ("input.txt");
	//ios_base::sync_with_stdio(0);
	int tcase, t, m, i, ans;
	SD(tcase);
	FOR(t, tcase)
	{
        SD(n);
        SD(m);
        FOR(i, m)
            cin >> str[i];

        cin >> match;

        ans = backtrack(m);
        printf("Data Set %d:\n", t+1);
        if(ans == inf)printf("Impossible\n\n");
        else printf("%d\n\n", ans);
	}
	return 0;
}
