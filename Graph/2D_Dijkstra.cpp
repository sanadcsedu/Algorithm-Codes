#include<stdio.h>
#include<iostream>
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
#define pi acos(-1.0)
#define inf_max 2147483647
#define inf_min -2147483647
#define N 30010
using namespace std;

struct node {
  int cost;
  int x;
  int y;
  node(){}
  node(int nweight, int nx, int ny) : cost(nweight),x(nx),y(ny){}
  bool operator <(const node &e)const{
        return cost > e.cost;
    }
};
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int dis[1001][1001];
int graph[1001][1001];

int dijkstra(int graph[1001][1001], int nrows, int ncols)
{
    priority_queue<node> q;
    for(int i = 0; i < nrows; ++i)
        for(int j = 0; j < ncols; ++j)
            dis[i][j] = inf_max;
    q.push(node(graph[0][0], 0, 0));
    dis[0][0] = graph[0][0];

    while ( !q.empty() )
    {
        node s = q.top();
        q.pop();
        if ( s.x == nrows-1 && s.y == ncols-1 )
          return s.cost;
        for(int i = 0; i < 4; ++i)
        {
              int nx = s.x + dx[i];
              int ny = s.y + dy[i];
              if ( nx >= 0 && nx < nrows && ny >= 0 && ny < ncols )
              {
                    if ( dis[nx][ny] > dis[s.x][s.y] + graph[nx][ny] )
                    {
                      dis[nx][ny] = dis[s.x][s.y] + graph[nx][ny];
                      q.push(node(dis[s.x][s.y] + graph[nx][ny],nx,ny));
                    }
              }
        }
    }
  return -1;
}
char line[3000];
int main()
{
    int nboards;
    scanf("%d", &nboards);
    for(int k = 0; k < nboards; ++k)
    {
          int ncols, nrows;
          scanf("%d\n%d\n",&nrows,&ncols);
      for(int i = 0; i < nrows; ++i)
      {
        gets(line);
        for (int j = 0; j < ncols; ++j)
            graph[i][j] = line[j*2] - '0';
      }
      printf("%d\n",dijkstra(graph,nrows,ncols));
    }
  return 0;
}
