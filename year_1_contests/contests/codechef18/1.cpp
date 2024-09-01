#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <queue>
#include <unordered_map>

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
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
//#define int long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        vi a(n);
        it(i,1,n+1) a[i-1] = i;
        it(i,0,n) {
            cout<<a[i]<<" ";
        }
        cout<<endl; 
      
        int start = n/2+1;
        iota(all(a), start);
        int j = 1; 
        it(i,1,n+1) if(a[i-1] > n) {a[i-1] = j; j++;}
        vout(a);
        
        cout<<endl; 
        
    }
	return 0;
}
