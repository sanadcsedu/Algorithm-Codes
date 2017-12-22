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
#define MAX 110
#define pi acos(-1.0)
#define inf 2147483647
#define ll long long int
#define EPS 1e-9
#define mod 100000007
using namespace std;
int parent[MAX];
double arrx[MAX], arry[MAX];
struct edge
{
	int x, y;
	double w;
	edge(){}
	edge(int a, int b, double c): x(a), y(b), w(c) {}
	bool operator<(const edge & p)const
	{
		return w > p.w;
	}
};
priority_queue<edge> pq;
int Find(int r)
{
	if(parent[r]==r)return r;
	return parent[r] = Find(parent[r]);
}
void Union(int a, int b)
{
	int u, v;
	u = Find(a);
	v = Find(b);
	if(u!=v)
		parent[u] = v;
}
int main()
{
	int tcase, i, n, j, u, v;
	double weight, ans;
	cin >> tcase;
	while(tcase--)
	{
		cin >> n;
		ans = 0;
		for(i=0; i<n; i++)
		{
			cin >> arrx[i] >> arry[i];
			parent[i] = i;
		}
        while(!pq.empty())
        pq.pop();
		for(i=0; i<n; i++)
			for(j=i+1; j<n; j++)
			{
				weight = sqrt((arrx[j]-arrx[i])*(arrx[j]-arrx[i])+(arry[j]-arry[i])*(arry[j]-arry[i]));
				pq.push(edge(i, j, weight));
			}
		int count = 0;
		while(!pq.empty())
		{
			if(count == n-1)break;
			edge temp;
			temp = pq.top();
			u = Find(temp.x);
			v = Find(temp.y);
			if(u!=v)
			{
				ans += temp.w;
				count ++;
				Union(temp.x, temp.y);
			}
			pq.pop();
		}
		printf("%.2lf\n", ans);
		if(tcase)cout << endl;
	}
	return 0;
}


