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
#define inf 2147483647
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
//typedef pair <int, int> pii;

//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};
int dx[]={1,-1,0, 0,0, 0};
int dy[]={0, 0,1,-1,0, 0};
int dz[]={0, 0,0, 0,1,-1};

struct node
{
    int L, R, C;
    node (){}
    node(int a, int b, int c) : L(a), R(b), C(c){}
};
queue <node> Q;

int dis[35][35][35], l, h, w;
char field[35][35][35];

bool valid(int x, int y, int z)
{
    if(x>=0 && x<l && y>=0 && y<h && z>=0 && z<w && field[x][y][z]!='#' &&dis[x][y][z] == -1) return true;
    return false;
}
int sl,sr,sc;
int BFS()
{
    _set(dis);
    dis[sl][sr][sc]=0;
    Q.push(node(sl,sr,sc));
    int i, l, r, c;
    while(! Q.empty())
    {
        node temp = Q.front();
        Q.pop();
        for(i=0;i<6;i++)
        {
            l = temp.L + dx[i] , r = temp.R + dy[i], c = temp.C + dz[i];
            if(valid(l, r, c))
            {
                dis[l][r][c] = dis[temp.L][temp.R][temp.C] + 1;

                if(field[l][r][c] == 'E')
					return dis[l][r][c];
				else
					Q.push(node(l,r,c));
            }
        }
    }
    return -1;
}

int main()
{
	//READ("input.txt");
	//ios_base::sync_with_stdio(0);
	int i, j, k, ans;
	while((scanf("%d %d %d",&l,&h,&w)!=EOF && l!=0 && h!=0 && w!=0))
    {
        getchar();
        while(!Q.empty()) Q.pop();
        for(i=0; i<l; i++)
        {
            for(j=0; j<h; j++)
            {
                for(k=0; k<w; k++)
                {
                    field[i][j][k] = getchar();
                    if(field[i][j][k] == 'S')
                    {
                        sl=i,sr=j,sc=k;
                    }
                }
                getchar();
            }
            getchar();
        }
        ans = BFS();
        if(ans != -1) printf("Escaped in %d minute(s).\n", ans);
        else printf("Trapped!\n");
    }
	return 0;
}
