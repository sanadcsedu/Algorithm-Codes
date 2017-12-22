#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#define inf 10000000
using namespace std;
int dp[110][110];
void reset(int n)
{
    int i, j;
    for(i=0; i<=n; i++)
        for(j=0; j<=n; j++)
            dp[i][j] = inf;
}
void Floyd_warshall(int n)
{
    int i, j, k;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
}
int main()
{
    int tcase=1, c, s, q, start, end, a, b, w, i;
    bool blank = false;
    for(;;)
    {
        cin >> c >> s >> q;
        if ( c == 0 && s == 0 && q == 0 ) break;
        reset(c);
        for(i=0; i<s; i++){
            cin >> a >> b >> w;
            dp[a][b] = w;
            dp[b][a] = w;
        }
        Floyd_warshall(c);
        if ( blank ) printf ("\n");
        blank = true;

        printf ("Case #%d\n",tcase++);

        for ( int i = 0; i < q; i++ ) {
            cin >> start >> end;
            if ( dp[start][end] == inf ) printf ("no path\n");
            else printf ("%d\n",dp[start][end]);
        }
    }

    return 0;
}
