#include<bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LOOP(i,a) FOR(i,0,a)

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define BIG(p) memset(p, 0x3f, sizeof(p))

#define ll unsigned long long
#define oo (1000000000+7)

#define DEBUG
#ifdef DEBUG
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...) // Just strip off all debug tokens
#endif
 struct debugger
 {
	 template<typename T> debugger& operator , (const T& v)
	 {
			 std::cerr<<v<<" ";
			 return *this;
	 }
} dbg;

using namespace std;
ll modularexponentitaion(ll a, ll b, ll c = oo)
{
	if( b == 0)
			return 1;
	ll res = modularexponentitaion(a, b/2);
	res = ( res * res ) % c;
	if( (b&1))
		return (res * a) % c;
	return res;
}

int main()
{
	deb(modularexponentitaion(2,10));
	return 0;
}
