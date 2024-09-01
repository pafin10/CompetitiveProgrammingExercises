#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>


using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define itb(i, start, n) for (int i = start; i >= n; --i)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
const int MAX_N = 200'005;

int bin_log[MAX_N];
int m[MAX_N][17];
int main(int argc, char const *argv[]) {  
    // Given a vector and a number of queries with indices l and r, find the min 
    // in the range [l,r] for each query ?
    // yes but watch explanation video again
    
    ifstream cin("staticRangeMinQueries.txt");
    int t; //cin>>t; 
    t=1;
    while(t--) {
        int n, q; cin>>n>>q;
        vi a(n);
        it(i,0,n) {
            cin>>a[i]; 
            m[i][0] = a[i];
        }
        bin_log[1] = 0;
        for (int i = 2; i <= n; i++) {
            bin_log[i] = bin_log[i/2]+1;
        }
        for (int j = 1; j < 18; j++) {
            for (int i = 0; i + (1<<j) -1 < n; i++) {
                m[i][j] = min(m[i][j-1], m[i+(1<<(j-1))][j-1]);
            }
        }
        
        it(i,0,q) {
            int l,r;
            cin>>l>>r; 
            l--, r--; 
            int len = r-l+1; 
            int k = bin_log[len];
            cout<<min(m[l][k], m[r-(1<<k)+1][k])<<endl; 
        }
    }
}