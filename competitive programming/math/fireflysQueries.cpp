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
#define int long long
const int MAX_N = 100'005;

int32_t main() {
    // ifstream cin("fireflysQueries.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, q; cin>>n>>q; 
        vi a(n);
        vi prefSums(1); 

        for (int i = 0; i < n; i++) {
            cin>>a[i];
            prefSums.pb(prefSums.back() + a[i]);
        }
        for (int i = 0; i < n; i++) {
            prefSums.pb(prefSums.back() + a[i]);
        }
        
        while(q > 0) {
            int l, r; cin>>l>>r; 
            l--; r--; 
            int l_rotation = l / n; 
            int r_rotation = r / n;
            int l_pos = l % n;
            int r_pos = r % n; 


            int ans = prefSums[n] * (r_rotation - l_rotation + 1) - (prefSums[l_rotation + l_pos] 
            - prefSums[l_rotation]) - (prefSums[r_rotation + n] - prefSums[r_rotation + r_pos + 1]);
            
            cout<<ans<<endl; 
            q--;
        }
    }
}