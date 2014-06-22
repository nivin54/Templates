/* The number of positive integers, not greater than n,
 * and relatively prime with n, equals to Euler’s totient function φ (n).
 * Properties to be mentioned.
 * φ (p) = p -1, where p is prime.
 * φ (p ^ a) = p^a ( 1 - 1/p) = p^a - p^(a-1), where p is prime and a > 0.
 * φ (m * n) = φ(m) * φ(n), where m and n is relatively prime.
 * Conclusion φ (n) = n * (1 – 1/p 1) * (1 – 1/p 2) * ... * (1 – 1/p k)
*/
#include<bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LOOP(i,a) FOR(i,0,a)

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define BIG(p) memset(p, 0x3f, sizeof(p))

#define ll unsigned long long
#define oo (1000000000+7)
#define MAXN 100000
using namespace std;

#define DEBUG
#ifdef DEBUG
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...) // Just strip off all debug tokens
#endif
struct debugger {
	template<typename T> debugger& operator ,(const T& v) {
		std::cerr << v << " ";
		return *this;
	}
} dbg;

template<class T> T gcd(const T a, const T b) {
	return (b ? gcd<T>(b, a % b) : a);
}

int eulerphi(int N)
{
	int res = N;
	for(int i = 2 ; i*i <= N ; i++ )
	{
		if( N % i == 0)
				res -= res/i;
		while(N % i == 0)
				N /= i;
	}
	if(N > 1)
			res -= res/N;
	return res;

}
int main()
{
	deb(eulerphi(4));
	return 0;
}
