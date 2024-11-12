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
#include <cstring>


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
    // ifstream cin("kousukesAssignment.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n + 1);
        
        for (int i = 1; i <= n; i++) {
            cin>>a[i];
        }
        
        map<int, int> m; 
        m[0] = 0;
        int last[n + 1];
        int ps[n + 1];
        ps[0] = 0;

        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i - 1] + a[i];
            if (m.find(ps[i]) == m.end()) {
                last[i] = -1;
            }
            else {
                last[i] = m[ps[i]];
            }
            m[ps[i]] = i;
        }

        int dp[n +1];
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i], dp[i - 1]);
            if (last[i] != -1) {
                dp[i] = max(dp[i], dp[last[i]] + 1);
            }
        }
        
        cout<<*max_element(dp, dp + n + 1)<<endl; 
    }
}