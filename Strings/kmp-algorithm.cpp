#include<iostream>
#define MAXN 100005
using namespace std;
int f[MAXN]; 
string p;
void precompute_kmp_failure()
{
        int i = 0, j =-1,n;
        f[0] = -1;
        n = p.length();
        while(i < n)
        {
                while(j>=0 && p[i] != p[j])
                        j = f[j];
                j++;
                i++; 
                f[i] = j;
                cout << f[i] << " ";
        }
        cout << endl;

}
void kmp_search(string T)
{
        int i =0, j=0; 
        int n, m;
        n = T.length();
        m = p.length();
                
        while(i < n){
                while(j >=0 && T[i] != p[j])
                        j = f[j];
                i ++; 
                j++; 
                if(j == m) {
                        cout<<" P is found at index" << (i-j)<<" in String \n";
                        j = f[j];
                }}
}

int main()
{
        cout << "Enter a string " <<endl;
        string T;
        cin >> p>> T;
        precompute_kmp_failure();
        kmp_search(T);

        
}

