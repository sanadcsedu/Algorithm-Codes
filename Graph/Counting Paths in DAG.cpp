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
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

#define EPS 1e-9
#define MAX 1000004
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define mod 1000000003
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

unsigned long long a[105][105];
int w, h;
bool flag[105][105];

int dp(int p, int q)
{
	if(flag[p][q])
	{
		if(p==0 && q==0)return a[p][q] = 1;

		if(a[p][q] != -1)return a[p][q];
		else
		{
			if(p==0)return a[p][q] = dp(p, q-1);
			else if(q==0)return a[p][q] = dp(p-1, q);
			else return a[p][q] = dp(p, q-1) + dp(p-1 , q);
		}
	}
	return 0;
}
void reset(){

	int i, j;
	for(i=0; i<102; i++)
		for(j=0; j<102; j++)
		{
			a[i][j] = -1;
			flag[i][j] = true;
		}
}
int main()
{
	//READ("input.txt");
	//WRITE("output.txt");
	int i, u, v, n;
	for(;;)
	{
		cin >> w >> h;
		if(w==0 && h==0)break;
		reset();
		cin >> n ;
		for(i=0; i<n; i++)
		{
			cin >> u >> v;
			flag[u][v] = false;
		}
		dp(w, h);

		if(a[w][h]==1)printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
		else if(a[w][h]==0)printf("There is no path.\n");
		else printf("There are %d paths from Little Red Riding Hood's house to her grandmother's house.\n", a[w][h]);
	}
	return 0;
}
