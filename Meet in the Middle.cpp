/******************************
*	Sanad Saha            *
*	University of Dhaka   *
******************************/

#include<bits/stdc++.h>

using namespace std;

int a[4005];
int b[4005];
int c[4005];
int d[4005];
int ab[4000*4000 + 5];
int _binary_search(int val, int n)
{
    int high, low, mid, _size, ret, temp;
    low = 0;
    _size = n * n;
    high = _size;
    ret = 0;
    while(low <= high)
    {
        mid = (high + low) >> 1;
        if(ab[mid] == val)
        {
            temp = mid - 1;
            while(mid < _size && ab[mid] == val)
            {
                ret ++;
                mid ++;
            }
            while(temp >= 0 && ab[temp] == val)
            {
                ret ++;
                temp --;
            }
            return ret;
        }
        else if(ab[mid] < val) low = mid + 1;
        else if(ab[mid] > val) high = mid - 1;

    }
    return 0;
}
int main()
{
	int i, n, j, cnt;
    scanf("%d", &n);
    for(i=0 ; i<n; i++)
    {
        scanf("%d %d %d %d", &a[i] , &b[i], &c[i], &d[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            ab[i*n + j] = a[i] + b[j];
        }
    }
    sort(ab, ab+ n*n);
    cnt = 0;
    int z;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            z = -1 *(c[i] + d[j]);
            cnt += _binary_search(z, n);
        }
    }
    printf("%d\n", cnt);
	return 0;
}



