#include<bits/stdc++.h>
using namespace std;

#define MAX 1000005

int status[(MAX/32) + 2];

#define check(i) (status[i >> 5] & ( 1 <<( i & 31)))
#define set1(i) status[i >> 5] |= ( 1 << (i & 31) )

int prime[100005];

void bitwise_sieve()
{
	int w, i, j, k;
	w = sqrt(MAX);

	for(i=2*2; i<MAX; i+=2) set1(i);
    for(i=3; i<= w; i+=2)
	{
		if(!check(i)) // actually means check(status[i / 32], i % 32)
		{
			for(j = i*i; j < MAX; j+= (i << 1))
			{
				set1(j);
			}
		}
	}
	k = 0;
    prime[k++]  = 2;

    for(i=3; i<MAX; i+=2)
        if( !check(i)) prime[k++] = i;
}

int main()
{
    bitwise_sieve();
    return 0;
}
