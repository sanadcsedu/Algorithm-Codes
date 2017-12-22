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
#include<string>
#define MAX 1000004
#define pi acos(-1.0)
#define inf 2147483647
#define ll long long int
#define EPS 1e-9
#define mod 100000007
using namespace std;
struct edge
{
	int from, to, weight;
	edge(){}
	edge(int x, int y, int z):from(x), to(y), weight(z){}
	bool operator<( const edge & p)const
	{
		return weight > p.weight;
	}
}temp;
int parent[MAX];
int find(int r)
{
	if(parent[r]==r)return r;
	return parent[r] = find(parent[r]);
}
void Union(int a, int b)
{
	int u, v;
	u = find(a);
	v = find(b);
	if(u!=v)parent[u] = v;
}
priority_queue <edge> pq;
int main()
{
	int n, m, i, a, b, w, u, v, k;
	for(;;)
	{
		cin >> n >> m;
		if(n==0 && m==0)break;

		while(!pq.empty())pq.pop();
		for(i=0; i<n; i++)
			parent[i] = i;

		for(i=0; i<m; i++)
		{
			cin >> a >> b >> w;
			pq.push(edge(a, b, w));
		}
		int count = 0, res = -1;
		while(!pq.empty())
		{
		    if(count == n-1)break;
			temp = pq.top();
			u = find(temp.from);
			v = find(temp.to);
			if(u!=v)
			{
			    Union(temp.from, temp.to);
                if(res < temp.weight)res = temp.weight;
                count ++;
			}
			pq.pop();
		}
		if(count == n-1)printf("%d\n", res);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}


