#include <bits/stdc++.h>

#define MAX 1000005
#define MOD 1000000007
#define INF (1 << 30)
#define lli long long int
#define ull unsigned long long int
#define eps 1e-9
#define pb push_back
#define SZ(a) a.size()
#define sf scanf
#define pf printf
#define si(a) sf("%d", &a)
#define sd(a) sf("%lf", &a)
#define sll(a) sf("%lld", &a)
#define pi(a) pf("%d\n", a)
#define pd(a) pf("%lf\n", a)
#define pll(a) pf("%lld\n", a)
#define COUT(a) cout << a << endl
#define pii pair < int, int >
#define vi vector < int >
#define vll vector < lli >
#define vs vector < string >
#define MP map < int, int >
#define clr(a) memset(a, 0, sizeof(a))
#define set(a, b) memset(a, b, sizeof(a))
#define BSET(a) bitset < MAX > a
#define bit(n, i) (n&(1 << i))
#define ifc(n) (flag[n >> 6]&(1 << ((n >> 1) & 31)))
#define isc(n) (flag[n >> 6]|=(1 << ((n >> 1) & 31)))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
#define Degree(x) x*180.0/pi
#define Radiun(x) x*pi/180.0
#define Read() freopen("input.txt", "r", stdin)
#define Write() freopen("output.txt", "w", stdout)

using namespace std;

bool fits(double a, double b, double c, double d){
	double X,Y,L,K,DMax; 
	if(a<b)	swap(a,b); 
	if(c<d)	swap(c,d);
	if(c<=a && d<=b) return true; 
	else{

		if(d>=b) return false;

		else{
			X = sqrt( a*a + b*b ); Y = sqrt( c*c + d*d ); 
			if(Y<b)return true; 
			else{
				if(Y>X)	return false;
				else{
					L = ( b - sqrt( Y*Y - a*a) ) /2.0;
					K = ( a - sqrt( Y*Y - b*b) ) /2.0; DMax = sqrt(L * L + K * K); 
					if (d >= DMax) return false;
					else return true;
				}
			}
		}

	}

} 

int main(){
	//Read();
    double a, b, c, d, e;
    while (scanf("%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e) == 5){
		bool flag = fits(d, e, a, b) || fits(d, e, b, c) || fits(d, e, c, a);
		if (!flag)	puts("NO");
		else	puts("YES");
    }

    return 0;
}