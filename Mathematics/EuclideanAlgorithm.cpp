/* Euclidean Algorithm, to find the greatest common factor
 * Eg. 6 & 8, For 6, common factor 1, 2, 3, 6. For 8, common factor
 * 1, 2, 4, 8. Greatest common is 2 as seen from above example.
 * Euclid propsed this algorithm with a property in mind.
 * common divisor of two number a & b is same, even if the number is 
 * subracted from the other number say d = b - a, common divisor 
 * still maintained. Largest common factor is the first common multiple
 * for both a and b. Eg. 6 and 8. For 6, 6, 12, 18, 24... For 8, 8, 16,24..
 * So common is 24. We get LCM by a * b / gcd ( a, b );
 */
 
#include <bits/stdc++.h>
using namespace std;
int gcd( int a, int b)
{
		if( !a )
				return b;
		return gcd ( b % a, a );
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout<< gcd(a,b);
	return 0;		
}
