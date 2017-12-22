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
    //int endmark;
    int cnt;
    trie *next[5];
    trie()
    {
        //endmark =0 ;
        cnt = 0;
        memset(next, 0, sizeof(next));
    }
};
trie *root;
map <char, int> my_map;
int _insert(string s)
{
    trie *cur = root;
    int len, x,i;
    int ans, z;
    len = s.length();
    ans = 0;
    for(i=0; i<len; i++)
    {
        x = my_map[s[i]];
        if(cur->next[x] == NULL)
        {
            cur->next[x] = new trie();
        }
        cur = cur->next[x];
        cur->cnt ++;
        z = cur->cnt * (i+1);
        if(z > ans)ans = z;

    }
    return ans;
}
void _clear(trie *cur)
{
    for(int i=0; i<5; i++)
    {
        if(cur->next[i] != NULL)
            _clear(cur->next[i]);
    }
    free(cur);
}
int main()
{
    //READ("input.txt");
    my_map['A'] = 0; my_map['C'] = 1; my_map['G'] = 2; my_map['T'] = 3;

    int t, tcase, i, n;
    string s;
    scanf("%d", &tcase);

    for(t=0; t<tcase; t++)
    {
        scanf("%d", &n);
        root = new trie();
        int _max = -1, ret;
        for(i=0; i<n; i++)
        {
            cin >> s;
            ret = _insert(s);
            if(_max < ret ) _max = ret;
        }
        printf("Case %d: %d\n", t+1, _max);
        _clear(root);
    }
	return 0;
}
