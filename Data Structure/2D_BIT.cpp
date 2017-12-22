#include<bits/stdc++.h>

#define max_x 1001
#define max_y 1001

using namespace std;
int tree[1005][1005];
int flag[1005][1005];

void update(int x, int y, int val)
{
    int y1;
    while( x <= max_x )
    {
        y1 = y;
        while( y1 <= max_y)
        {
            tree[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}
int Query(int x, int y)
{
    int sum = 0;
    int y1;
    while (x > 0)
    {
        y1 = y;
        while ( y1 > 0)
        {
            sum += tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return sum;
}
int main()
{
    int t, tcase, q, ch, x1, x2, y1, y2, i;
    scanf("%d", &tcase);
    for(t=0; t< tcase; t++)
    {
        scanf("%d", &q);
        memset(tree, 0, sizeof(tree));
        memset(flag, 0, sizeof(flag));

        printf("Case %d:\n", t+1);
        for(i=0; i<q; i++)
        {
            scanf("%d", &ch);
            if(ch)
            {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1++, y1++, x2++, y2++;
                printf("%d\n", Query(x1-1, y1-1) + Query(x2, y2) - Query(x2, y1-1) - Query(x1-1, y2));
            }
            else
            {
                scanf("%d %d", &x1, &y1);
                x1++, y1++;
                if(flag[x1][y1]) continue;
                flag[x1][y1] = 1;
                update(x1, y1, 1);
            }
        }
    }
    return 0;
}
