#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<deque>
#include<set>
#define MAX 1000000
#define pi acos(-1.0)
#define inf 2147483647
#define ll long long int
#define EPS 1e-9
#define mod 100000007
using namespace std;
map <string, int > name;
char input[35], a[35], b[35];
int parent[5010], fre[5010];
int find(int r)
{
    if(parent[r]==r)return r;
    else return find(parent[r]);
}
void Union(int x, int y)
{
    int u, v;
    u = find(x);
    v = find(y);
    if(u!=v)
    {
        parent[u] = v;
    }

}
int main()
{
    int c, r, i;
    for(;;)
    {
        cin >> c >> r;
        name.clear();
        if(c==0 && r==0)break;
        for(i=0; i<c; i++){
            parent[i] = i;
            fre[i] = 0;
        }

        for(i=0; i<c; i++)
        {
            cin >> input;
            name[input] = i;
        }
        for(i=0; i<r; i++)
        {
            cin >> a >> b;
            Union(name[a], name[b]);
        }
        for(i=0; i<c;i++)
            fre[find(i)]++;
        int max = -1;
        for(i=0; i<c; i++)
            if(max<fre[i])max = fre[i];
        cout << max << endl;
    }
    return 0;
}
