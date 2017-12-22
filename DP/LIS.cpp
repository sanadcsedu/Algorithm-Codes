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
struct elephant
{
    int weight, IQ;

}a[1010];
bool cmp (int x, int y)
{
    if(a[x].IQ < a[y].IQ)return true;
    return false;
}
int LIS[1010],seq[1010],ind[1010];
int main()
{
	int n,loop,m,i,j, ww, ss;
	n = 0;
	memset(ind, 0, sizeof(ind));
    while (scanf("%d", &ww) != EOF)
    {
        scanf( "%d", &ss);
        a[n].weight = ww;
        a[n].IQ = ss;
        ind[n] = n;
        n++;
    }
    memset(LIS,0,sizeof(LIS));
    loop = n;

    for(i=0;i<loop;i++)
        LIS[i]=1;

    sort(ind, ind+ loop, cmp);

    for(i=0;i<loop;i++)
        for(j=i+1;j<loop;j++)
            if(a[ind[i]].weight > a[ind[j]].weight) LIS[j] = max(LIS[j],LIS[i]+1);

    m = 0;
    for(i=0;i<loop;i++)
        if(m<LIS[i])m = LIS[i];

    printf("%d\n",m);
    int hold = m;
    for(i=loop-1 ; i>= 0; i--)
        if(LIS[i] == m)seq[m--] = ind[i]+1;

    for(i=hold; i>=1; i--)
        printf("%d\n",seq[i]);

    return 0;
}
