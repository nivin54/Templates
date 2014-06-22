/*Trivial Division
 * Number of divisor, prime to n can be found using trail division.
 *
 * Number of divisors of n, every number can be represented by unique multiples
 * of prime powers. e.g. N = a^i * b^j * … * c^l, { a, b, c} are unique primes.
 * number of divisors can be treated as 'Gift Problem'.
 * Given boxes of gifts, and each box has a default gift named 'ONE'. We are asked to
 * take a gift from each box and put into a larger box. How many ways can it be achieved.
 * Let us assume each box is named after letter {A - Z } and number of gifts in each box
 * is { 1 - infi. } excluding default gifts. Counting methods can be used to find the result.
 * We can choose 1 gift from each boxes. i.e. ACombination1 * BCombination1 * CCombination1 etc.
 * Apply ncr formula and multiply with other boxes, gives the total ways of doing it.
 *
 * Sum of divisors, SOP (Sum of Products can be found separately using Sum of G.P i.e.{ a + a^2 + a^3 + .. a^n }
 * Sn = a * ( 1 - r^n ) / ( 1 - r ) or Sn = a * ( r^n - 1 ) / ( r - 1 ), both formula work :D.
 *
 * */
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
ll numPF(ll N) {
	ll res = 0;
	for (int i = 2; i * i <= N; ++i) {
		if (N % i == 0)
			res += 1;
		while (N % i == 0)
			N /= i;
	}
	if (N > 1)
		res += 1;
	return res;

}
ll numDiv(ll N) {
	ll res = 1;
	for (int i = 2; i * i <= N; ++i) {
		ll gifts = 1;
		while (N % i == 0) {
			N /= i;
			gifts += 1;
		}
		res *= gifts;
	}
	if (N > 1)
		res *= 2;
	return res;

}
ll modularexponentitaion(ll a, ll b, ll c = oo) {
	if (b == 0)
		return 1;
	ll res = modularexponentitaion(a, b / 2);
	res = (res * res) % c;
	if ((b & 1))
		return (res * a) % c;
	return res;
}
ll sumGP(ll base, ll expo) {
	ll res, tres;
	tres = modularexponentitaion(base, expo);
	res = (tres - 1) / (base - 1);
	return res;
}

ll sumDiv(ll N) {
	ll res = 1;
	for (int i = 2; i * i <= N; ++i) {
		ll exponents = 1;
		while (N % i == 0) {
			N /= i;
			exponents += 1;
		}
		if (exponents > 1) {
			res *= sumGP(i, exponents);
		}
	}
	if (N > 1)
		res *= sumGP(N, 2);
	return res;

}


int main() {
	deb(numPF(30), numDiv(60), sumDiv(60));
	return 0;
}
