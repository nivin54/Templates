/*Every permutation can be expressed as a set of disjoint cycle,
 * representing position changes of the items. We first detect 
 * the number of disjoint cycle. To get the minimal number of swaps,
 * we subtract the permutation length by total number of disjoint cycles,
 * Above rule follows from the observation, in order to 'fix' a cycle of 
 * N elements, N - 1 swaps are enough.
*/
#include <bits/stdc++.h>
using namespace std;
int findx(int arr[], int x, int n)
{
		for(int i = 0 ; i < n; ++i )
				if( arr[i] == x )
						return i;
		return -1;	
}
int minimalswaps(int arr1[], int arr2[], int n )
{
		int permutation[n];
		for( int i = 0 ; i < n ; ++i )		
				permutation[i] = findx(arr1, arr2[i], n);
		int numberofcycles = 0 ;
		for( int j = 0 ; j < n ; ++j )
		{
			if(  permutation[j] != -1 )
			{
					numberofcycles += 1;
					while ( permutation[j] != -1)
					{						
						int next = permutation[j];
						permutation[j] = -1;
						j = next;												
					}										
			}					
		}
		return n - numberofcycles;										
}
int main()
{
		int arr[5] = { 1, 2, 3, 4, 5};
		int arr1[5] = {5, 3, 4, 2, 1};
	
		cout<< minimalswaps(arr, arr1, 5);


		return 0;
}
