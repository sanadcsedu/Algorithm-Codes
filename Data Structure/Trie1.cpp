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

struct trie
{
    int endmark;
    trie *next[11];
    trie()
    {
        endmark = 0;
        memset(next, 0, sizeof(next));
    }
};
trie *root;

int _insert(string s)
{
    trie *cur = root;
    int len = s.length();
    int i, x, flag = -1 ;
    for(i=0; i < len; i++)
    {
        x = s[i] - '0';
        if(cur->endmark == 1)
        {
            flag = 0;
            break;
        }
        else if(cur->next[x] == NULL)
        {
            cur->next[x] = new trie();
            flag = 1;
        }
        cur = cur ->next[x];
    }
    cur->endmark = 1;
    if(flag == -1 || flag == 0)return 0;
    else return 1;

}
void _clear(trie *cur)
{
    for(int i=0; i< 11; i++)
    {
        if(cur->next[i] != NULL)
            _clear(cur->next[i]);
    }
    free(cur);
}
int main()
{
    //READ("input.txt");
    int t, tcase, n, ret, i;
    scanf("%d", &tcase);
    string str;
    bool yes;
    for(t=1; t<= tcase; t++)
    {
        scanf("%d", &n);
        root = new trie();
        yes = true;
        for(i=0; i<n; i++)
        {
            cin >> str;
            if(yes)ret = _insert(str);
            if(!ret)yes = false;
        }
        if(!yes)printf("Case %d: NO\n", t);
        else printf("Case %d: YES\n", t);
        _clear(root);
    }
	return 0;
}
