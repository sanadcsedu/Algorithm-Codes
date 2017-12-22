#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<stdlib.h>
#include<map>
#include<algorithm>
#include<list>
#include<vector>
#include<iostream>
#define pi acos(-1.0)
#define inf_max 2147483647
#define inf_min -2147483647

using namespace std;

int matrix[110][110];
char input[110][110];
int start_x, start_y, end_y, end_x, r, c;
queue <int> Q;
int dx[] = {-1, -1, -2, -2, 2, 2, 1, 1};
int dy[] = { 2, -2,  1, -1, -1,1, 2, -2};
int hx[] = {1, 1, -1, -1, -1, 0, 1, 0};
int hy[] = {1, 0, -1, 0, 1, -1, -1, 1};
bool valid(int p, int q)
{
    if ( p >= 0 && p < r && q >= 0 && q < c ) return true;
    else return false;
}
void change(int r, int c, int v)
{
    matrix[r][c] = v + 1 ;
    Q.push(r);
    Q.push(c);
}
void horse(int x, int y)
{
    int i, pre_x, pre_y;
    for(i=0; i<8; i++)
    {
        pre_x = x + dx[i];
        pre_y = y + dy[i];
        if(valid(pre_x, pre_y) && input[pre_x][pre_y]!='A' && input[pre_x][pre_y]!='B')matrix[pre_x][pre_y] = inf_max;
    }
}
void BFS()
{
    int u, v, i, pre_hx, pre_hy;
    matrix[start_x][start_y] = 0;
    Q.push(start_x);
    Q.push(start_y);
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        v = Q.front();
        Q.pop();

        for(i=0; i<8; i++)
        {
            pre_hx = u + hx[i];
            pre_hy = v + hy[i];
            if(valid(pre_hx, pre_hy) && matrix[pre_hx][pre_hy]== -1) change(pre_hx, pre_hy, matrix[u][v]);
        }
    }
}
int main()
{
    int i, j, tcase;
    scanf("%d", &tcase);
    while(tcase--)
    {
        scanf("%d %d",&r, &c);
        getchar();

        for(i=0; i<r; i++)
            gets(input[i]);

        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                matrix[i][j] = -1;

        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
            {
                if(input[i][j]=='A')
                {
                    start_x = i;
                    start_y = j;
                }
                else if(input[i][j]=='B')
                {
                    end_x = i;
                    end_y = j;
                }
                else if(input[i][j]=='Z')
                {
                    matrix[i][j] = inf_max;
                    horse(i, j);
                }
            }

        BFS();

        if(matrix[end_x][end_y] == -1)printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n",matrix[end_x][end_y]);
    }
    return 0;
}
