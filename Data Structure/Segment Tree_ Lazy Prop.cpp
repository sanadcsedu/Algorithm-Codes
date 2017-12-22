#include<stdio.h>
#include<string.h>
#define MAX 1 << 18
#define ll long long int
ll Tree[MAX][2];

void update(int node, int l, int r, int i, int j, ll x)
{
    if(i > r || j < l) return;
    if(l >= i && r <= j)
    {
        Tree[node][0] += ((r - l + 1)*x);
        Tree[node][1] += x;
        return ;
    }
    int left, right, mid;
    left = node << 1;
    right = left + 1;
    mid = (l + r) >> 1;
    update(left, l, mid, i, j, x);
    update(right, mid + 1, r, i, j, x);
    Tree[node][0] = Tree[left][0] + Tree[right][0] + (r - l + 1)* Tree[node][1];
}

ll query(int node , int l ,int r, int i, int j, ll carry)
{
    if(i > r || j < l) return 0;
    if(l >= i && r <= j) return Tree[node][0] + (carry *(r - l + 1));
    int left , right, mid;
    ll ret1, ret2;

    left = node << 1;
    right = left + 1;
    mid = (l + r) >> 1;

    ret1 = query(left, l, mid, i, j, carry + Tree[node][1]);
    ret2 = query(right, mid + 1, r, i, j, carry + Tree[node][1]);
    return ret1 + ret2;

}

int main() {

	int test, n, q, c, x, y, a;
	scanf("%d", &test);
	while(test--) {
		scanf("%d%d", &n, &q);
		memset(Tree, 0, sizeof(Tree));
		while(q--)
        {
			scanf("%d%d%d", &c, &x, &y);
			if(c) printf("%lld\n", query(1, 1, n, x, y, 0));
			else
			{
				scanf("%d", &a);
				update(1, 1, n, x, y, a);
			}
		}
	}
	return 0;
}



