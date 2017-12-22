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
//#define mp make_pair
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
int a[15];
bool taken[15];

vector< vector<int> > _list;
map< vector<int>, bool > mp;
vector<int> temp;
int t, n;

int backtracking(int sum , int k) {

    if (sum == t)
    {
        if (!mp[temp])
        {
            _list.push_back(temp);
            mp[temp] = true;
        }
        return 0;
    }

    for ( ; k<n ; k++)
    {
        if (!taken[k] && sum + a[k] <= t)
        {
            temp.push_back(a[k]);
            taken[k] = true;
            backtracking(sum+a[k] , k);
            taken[k] = false;
            temp.pop_back();
        }
    }

    return 0;
}
void reset()
{
    mem(taken);
    temp.clear();
    mp.clear();
    _list.clear();

}
int main()
{

    int i, j;

    while ( scanf("%d %d",&t,&n) && n)
    {
        reset();
        for (i=0 ; i<n ; i++)
        {
            scanf("%d",&a[i]);
        }
        printf("Sums of %d:\n",t);
        backtracking(0,0);

        if (!_list.size())
            printf("NONE\n");

        for (i=0 ; i<(int)_list.size() ; i++)
        {
            for (j=0 ; j<(int)_list[i].size() ; j++)
            {
                if (!j) printf("%d",_list[i][j]);
                else printf("+%d",_list[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}
