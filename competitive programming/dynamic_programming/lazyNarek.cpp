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
const int MAX_N = 100'005;
const string narek = "narek";

int32_t main() {
    // ifstream cin("lazyNarek.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m; 
        vector<string> s(n); 
        vi dp(5, int(-1e9)), ndp(5);
        dp[0] = 0;

        for (int i = 0; i < n; i++) cin>>s[i];

        for (int i = 0; i < n; i++) {
            ndp = dp; 

            for (int k = 0; k < 5; k++) {
                if (dp[k] == int(-1e9)) continue;
                int counted_score = 0, next = k;

                for (int j = 0; j < m; j++) {
                    int ind = narek.find(s[i][j]);
                    if (ind == -1) continue;

                    if (ind == next) {
                        counted_score++;
                        next = (next + 1) % 5;
                    }
                    else counted_score--;
                }
                ndp[next] = max(ndp[next], dp[k] + counted_score);
            }
            dp = ndp; 
        }

        int ans = 0;
        for (int i = 0; i < 5; i++) ans = max(ans, dp[i] - 2 * i);
        cout<<ans<<endl; 
    }
}