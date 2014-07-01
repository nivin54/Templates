/*Given sequence of numbers need to count the gcd of three numbers equal 1.
Brute force will eventually time out, We introduce mobious function, mobious
function separates the numbers into 3 baskets. 1 basket non square free number,
2 basket - number of prime divisor is even, 3 - basket number of prime divisor is
odd. Each basket incurring a value - 0, 1, -1. Then we apply a formula
Mobiousvalue * C(D[N],3), Where in D[N] is the number element in the sequence that
is divisble by N. Mobious function performs IEP(Inclusion Exclusion Principle) at each
level. i.e. 1C3 - 2C3 - 3C3 - 5C3 + 6C3 + 10C3 + 15C3 + 30C3.*/

#include<bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LOOP(i,a) FOR(i,0,a)

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define BIG(p) memset(p, 0x3f, sizeof(p))

#define ll unsigned long long
#define oo (1000000000+7)

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
using namespace std;
/*
 This is assumed to be nc3. So we have
 decided on direct formula.*/
long long combinatorial(long long N) {
	long long res;
	res = 1LL * (N - 1) * (N) * (N - 2);
	return res / 6LL;
}
int isitsqurefree(int n) {
	int primefactors = 0;
	for (int i = 2; i * i <= n; i += 1) {
		if (n % i == 0) {
			n /= i;
			primefactors += 1;
			if (n % i == 0)
				return 0;
		}
	}
	if( n > 1 )
			primefactors += 1;

	return (primefactors & 1) ? -1 : 1;
}
int cnt[1000005];

int main() {
	int N, aux, maxm = 0;
	cin >> N;
	for (int i = 1; i <= N; i += 1) {
		cin >> aux;
		cnt[aux] += 1;
		maxm = max(aux, maxm);
	}
	long long res = combinatorial(N);
	for (int i = 2; i <= maxm; i += 1) {
		long long  sign = isitsqurefree(i);
		if (!sign)
			continue;
		int all = 0;
		for (int j = i; j <= maxm; j += i)
			all += cnt[j];

		res = res + (combinatorial(all) * sign);
	}
	cout << res << endl;
	return 0;
}

