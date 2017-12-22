/*
Suffix array implementation using bucket sorting + lcp.
Complexity O(n log n), str[] is the target string,
n is its length and suffix[i] contains i'th sorted suffix position.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX = 10005 * 2;
const int MAX_LOG = 18;

int n, step, mv, suffix[MAX], tmp[MAX];
int sum[MAX], cnt[MAX], _rank[MAX_LOG][MAX];
char str[MAX];

bool _equal(const int &u, const int &v)
{
	if(!step) return str[u] == str[v];
	if(_rank[step-1][u] != _rank[step-1][v]) return false;
	int a = u + mv < n ? _rank[step-1][u+mv] : -1;
	int b = v + mv < n ? _rank[step-1][v+mv] : -1;
	return a == b;
}

void update()
{
	int i, rnk;
	for(i = 0; i < n; i++) sum[i] = 0;
	for(i = rnk = 0; i < n; i++)
    {
		suffix[i] = tmp[i];
		if(i && !_equal(suffix[i], suffix[i-1]))
        {
			_rank[step][suffix[i]] = ++rnk;
			sum[rnk+1] = sum[rnk];
		}
		else _rank[step][suffix[i]] = rnk;
		sum[rnk+1]++;
	}
}

void Sort()
{
	int i;
	for(i = 0; i < n; i++) cnt[i] = 0;
	memset(tmp, -1, sizeof tmp);
	for(i = 0; i < mv; i++){
		int idx = _rank[step - 1][n - i - 1];
		int x = sum[idx];
		tmp[x + cnt[idx]] = n - i - 1;
		cnt[idx]++;
	}
	for(i = 0; i < n; i++){
		int idx = suffix[i] - mv;
		if(idx < 0)continue;
		idx = _rank[step-1][idx];
		int x = sum[idx];
		tmp[x + cnt[idx]] = suffix[i] - mv;
		cnt[idx]++;
	}
	update();
	return;
}

bool cmp(const int &a, const int &b)
{
	if(str[a]!=str[b]) return str[a]<str[b];
	return false;
}

void Suffix_Array()
{
	int i;
	for(i = 0; i < n; i++) tmp[i] = i;
	sort(tmp, tmp + n, cmp);
	step = 0;
	update();
	++step;
	for(mv = 1; mv < n; mv <<= 1)
    {
		Sort();
		step++;
	}
	step--;
	for(i = 0; i <= step; i++) _rank[i][n] = -1;
}

int LCP(int u, int v)
{
	if(u == v) return n - u;
	int ret, i;
	for(ret = 0, i = step; i >= 0; i--)
    {
		if(_rank[i][u] == _rank[i][v])
		{
			ret += 1<<i;
			u += 1<<i;
			v += 1<<i;
		}
	}
	return ret;
}
//Set n as the length of the String. Don't Use it in local it's been declared Global
int main()
{
	int tcase, ori, ans, i, ghum;
	scanf("%d", &tcase);
	while(tcase--)
	{
		scanf("%s", str);
		strcpy(temp, str);
		strcat(str, temp);
		n = strlen(str);
		Suffix_Array();
		ori = n >> 1;
		ans = suffix[0];
		for(i=0; i<n; i++)
		{
			if(suffix[i] < ori)
			{
				ghum = LCP(suffix[i], ans);
                if(ghum == n-ans ) ans = min( ans , suffix[i]);
			}
		}
		printf("%d\n", ans+1);
	}
	return 0;
}
