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
    int cnt;
    int next[54];
    trie()
    {
        cnt = 0;
        memset(next, 0, sizeof(next));
    }
};
trie T[100100];
int sz;
char s[105], p[105];
char ss[10005];

void reset()
{
    T[0] = trie();
    sz = 0;
}
void _insert(int node,int pos)
{
    if(s[pos]==0)
    {
        T[node].cnt++;
        return;
    }
    int x;
    if(s[pos] >= 'a' && s[pos] <= 'z') x = s[pos] - 'a';
    else x = s[pos]-'A' + 26;

    if(T[node].next[x]==0)
    {
        T[node].next[x] = ++sz;
        T[sz] = trie();
    }
    int cur = T[node].next[x];

    _insert(cur , pos+1);
}

int _find(int node,int pos)
{
    if(p[pos]==0)
    {
        return T[node].cnt;
    }
    int x;
    if(p[pos] >= 'a' && p[pos] <= 'z') x = p[pos] - 'a';
    else x = p[pos]-'A' + 26;


    int cur = T[node].next[x];
    if(cur == 0 ) return 0;
    return _find(cur , pos+1 );
}
int main()
{
    //READ("input.txt");
    int t, tcase, i, n, ans, x, j;
    scanf("%d", &tcase);
    for(t=0; t<tcase; t++)
    {
        reset();
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%s", s);
            x = strlen(s);
            if(x>2)sort(s+1, s+x-1 );
            _insert(0,0);
        }
        scanf("%d", &n);
        getchar();
        printf("Case %d:\n", t+1);
        for(i=0; i<n; i++)
        {
            gets(ss);
            ans = 1;
            mem(p);
            x = 0;
            for(j=0; ss[j]; j++)
            {
                if(ss[j] == ' ' && x>0)
                {
                    if(x>2)sort(p+1, p+x-1 );
                    ans *= _find(0,0);
                    mem(p);
                    x = 0;
                }
                else if(isalpha(ss[j])) p[x++] = ss[j];
            }
            if(x > 0)
            {
                if(x>2)sort(p+1, p+x-1 );
                ans *= _find(0,0);
            }
            printf("%d\n", ans);
        }
    }
	return 0;
}

 