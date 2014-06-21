/*
Prime Sieve faster way to find the primes. Outerloops find the prime number
and inner loops removes all the multiples of the current prime.
To Ponder -> Why inner loop start from i*i, because mutliples lesser than
(1...i-1) would have marked by the prime lesser than i.*/

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
int Prime[MAXN];
int SieveEratos(int n) {
	SET(Prime);
	Prime[0] = Prime[1] = 0;
	for (int i = 2; i * i < n; i++) {
		if (Prime[i]) {
			for (int j = i * i; j < n; j += i) {
				Prime[j] = 0;
			}
		}
	}
	return 1;
}

int main() {

	SieveEratos(100);
	for (int i = 1; i < 100; ++i) {
		if (Prime[i])
			deb(i);
	}
	return 0;
}
