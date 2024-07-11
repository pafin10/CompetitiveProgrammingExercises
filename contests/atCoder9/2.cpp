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
const int MOD = 998244353;

int countValidSequences(int M, int N, vi& X) {
    vector<vector<vi>> dp(N + 1, vector<vi>(M + 1, vi(2, 0)));

    // Base case: length 1 sequences
    for (int b = 1; b <= M; ++b) {
        dp[1][b][0] = 1;
    }
    bool valid(N+1);

    // Fill the DP table
    for (int i = 2; i <= N; ++i) {
        // Compute total sum of previous states
        int total_sum_0 = 0;
        int total_sum_1 = 0;
        for (int k = 1; k <= M; ++k) {
            total_sum_0 = (total_sum_0 + dp[i-1][k][0]) % MOD;
            total_sum_1 = (total_sum_1 + dp[i-1][k][1]) % MOD;
        }

        for (int b = 1; b <= M; ++b) {
            // dp[i][b][0]: Add sequences of length i-1 where b is added fresh
            dp[i][b][0] = (total_sum_0 + total_sum_1 - dp[i-1][b][0] - dp[i-1][b][1] + 2 * MOD) % MOD;

            // dp[i][b][1]: Extend sequences where b already ensured X[b] or transition from X[b] to b
            dp[i][b][1] = dp[i-1][b][1]; // Continue sequences where b already ensured X[b]
            dp[i][b][1] = (dp[i][b][1] + dp[i-1][X[b]][0]) % MOD; // Transition from sequences ending with X[b]
        }
    }

    // The result is the sum of all valid sequences of length N
    int result = 0;
    for (int b = 1; b <= M; ++b) {
        result = (result + dp[N][b][0] + dp[N][b][1]) % MOD;
    }

    return result;
}

int32_t main() {
    ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n; cin>>m>>n; 
    vi x(m);
    it(i,0,m) cin>>x[i];
    int vs = countValidSequences(m,n,x);
    cout<<vs<<endl;

}